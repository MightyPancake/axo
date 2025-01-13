# Syntax
The design of Axo put heavy emphasis on syntax, as it is almost the biggest factor when it comes to user experience. Functionality of the language was really similar to C, but syntax was where most changes were planned.
Providing a simple, friendly looking syntax that would be both intuitive to read, with as little ambiguities while also having some shortcuts ultimately lead to programmers having to write less code.

## 1. Declarations
At the highest level each axo program is an ordered list of declarations. These can include:
- Function declarations or definitions
- Import declarations
- C related declarations and macros
- Compiler directives
- Global code scopes
- Structure and enumerate declarations

And much more. The full list can be found in the grammar file.

### 1.1 The `#` Directives
There are some directives in Axo that, just like in C, start with the `#` character and are mostly done at compile time. It's worth noting that the current implementation doesn't have a separate pre-processor as the whole language itself is sort of a huge C preprocessor in a way.

#### 1.1.1 #include
Used to directly copy a C `#include header` directive.
This supports multiple includes separated with commas like so:
```axo
#include <stdio.h>, <time.h>, "header.h"
```
as well as single include statements.

#### 1.1.2 #source
Marks a certain C file to be included in the final compilation
```axo
#source source_file.c
```

#### 1.1.3 #provided
Marks a certain variable as provided by the underlying C compiler. This is widely used for C ABI as a way of communicating which values are provided by the header or source files used in the code.
```axo
#provided (int fn const @byte, ...) printf
```

#### 1.1.4 #typ
Similar to `#provided`, but for types instead. Add a certain type as a primitive to Axo's type dictionary. Can also be used with a structure declaration to declare the defined structure in axo without including the definitions as a C structure declarations in the outputted C file.
```axo
// Declares size_t as a valid Axo type. This should be used when such type is already defined somewhere else in C
#typ size_t

// Declares my_struct as a valid Axo type without declaring it in C. Similar to previous, but can include exact structure.
#typ struct my_struct (
    int a,
    byte b
)
```

#### 1.1.5 #flag
A definitions that can be used to add a certain flag to the compilation flags in the process of compiling the resulting C to binary. Useful for avoiding having to manually link libraries by hand in the compiler command.
```axo
// Links math library
#flag "-lm"
```

#### 1.1.6 #C
Used to directly copy the following string literal as C code.

```axo
#C "int a = 12; return a;"
```

### 1.2 Function declarations
A function declaration is a way to tell the compiler a certain function prototype. A function cannot be called or referred to before declaration. To be called, the function also needs a definition.
There are 3 ways to declare a function in Axo:
1. Use `#provided` declaration (which assumes the function definition is provided by either one of the C sources or headers)
2. Declare a function with definition
3. Declare a function prototype with no body

The first option was already briefly discussed before and will be further tackled in the C ABI section later in thesis.

#### 1.2.1 Function definition
This is the main way one should define a function. The syntax is the following:
```axo
fn t name(t1 n1, t2 n2, tn nn){
    // Code
}
```
The above definition will declare a defined function that returns type `t` and takes in parameters `n1`-`nn` of type `t1`-`tn` respectively. While this syntax is enough to work with Axo, there are also some provided shortcuts.

##### 1.2.1a Inferred return type
Users can omit providing the return type when defining a function.
```axo
fn add(int a, int b){
    ret a+b
}
```
In that case, the return type is inferred from the first return statement present in the function. Please note that it does mean a certain function will still only return one type; if other return statements attempt to return a different type it will result in a compile time error.
If no return statement is present with this syntax, the function is assumed to return `none`.

##### 1.2.1b Default parameters
When defining a function it is possible to specify a default value for a parameter using the assign symbol `=` followed by the expression that should be used.
```axo
fn add(int a=0, int b=10){
    ret a+b
}
```
Note that Axo will try to assign a default value to each parameter based on its type anyway. In most cases it's a zero value, so the above example parameter `int a = 0` could be just simple written as `int a` since default value of type `int` is `0` anyway. More on default values for types in the types section.
It's also worth mentioning this works the other way around. It is possible to avoid explicitly stating parameter type if a default value has been provided. In that case, the type is taken from the default expression, so the above example could be written like this:
```axo
fn add(a=0, b=10){
    ret a+b
}
```
This works because numeric literals without a floating point are assumed to be of type `int`, but one could also just cast the expression to anything that is desirable.

Default parameters will be discussed further in detail later on in the section describing function calls.

##### 1.2.1c The $ operator
When defining methods an expression of `$` can be used to access the underlying value that was used to call the method.
```axo
struct vec3 {
    x = 0.0,
    y = 0.0,
    z = 0.0
}

fn vec3:inverse(){
    $.x = -$.x
    $.y = -$.y
    $.z = -$.z
    ret $
}
```
The above example shows how one can describe an operation of inverting a vector with 3 components.

##### 1.2.2 Function prototype declarations
It is possible, although should rarely be used, to declare a function without the corresponding body. This allows the compiler to accept calls to that function as valid despite lack of definition, because it is assumed such definition is defined later on.
This is mainly used to define a recursive function and otherwise using this feature is **not** advised as it essentially dodges compile time errors and can be dangerous.
The syntax looks similar, but uses `;` instead of body and requires the return type, since it cannot be inferred from the body which is not present.
```axo
fn t name(t1 n1, t2 n2, tn nn);
```

### 1.3 Structure declarations
Structures are a way to describe a certain data structure by using multiple types bundled into a single data oriented unit.
To define a structure, syntax below should be used:
```axo
struct name(
    t1 n1,
    t2 n2,
    tn nn
)
```
This would declare a structure type named `name` with fields named `n1`-`nn` of types `t1`-`tn` respectively.
Just like functions, structure declarations support default values for fields. It works in a similar fashion where type of a field can be inferred from the default expression. Below is an example of how that looks like:
```axo
struct my_struct(
    int num1,
    int num2 = 12,
    num3 = 12
)
```
The same stays true when creating a new instance of a structure from a literal; one can use fields names, rely on order or both.
```axo
// This is equal
my_s = my_struct{5, num3=36}

// to this
my_s = my_struct{5, 12, 36}
```

### 1.4 Enum declarations
Enums are a datatype that is only limited to certain values.
To declare an enum, a syntax similar to structure is used
```axo
enum chess_piece (
    pawn,
    bishop,
    knight,
    rook,
    king,
    queen
)
```
Note that all enum values like `pawn` or `bishop` are not taking any space in the global scope; they're tied strictly to the enum. This will be discussed in further detail later on.

### 1.5 Use module declaration
Axo has a system of modules; a simple way to package reusable code.
To use a module simply use:
```axo
use module_name
```
Where `module_name` corresponds to the module name that is needed.

### 1.6 Include declaration
This declaration includes *an axo file*. This shouldn't be confused with the `#include` directive, which is used for C headers. Axo will try to search for the included file locally by resolving the path.
```axo
include "my_source_file.axo"
```
It switches the context of the lexer to the target file and will switch back after the desired file runs out of input data.

### 1.7 Module declaration
Axo modules can contain data about specifics of the module such as description or author. To mark a certain module info, one should use the following syntax, preferably at the top of the main module file (which will be mentioned in the appropriate section).
```axo
// Module declaration for standard library
module(
	name: "std"
	prefix: "axo__"
	version: "0.0.1"
	author: "mightypancake"
	website: "https://axolang.com"
	license_name: "Apache 2.0"
	license: "https://www.apache.org/licenses/LICENSE-2.0.txt"
	description: "Axo standard library. This mostly reuses C stdlib."
)
```
Name field is a unique identifier that will be used when accessing said module. Version should be set to the exact version of the module.
Author should be said to name of the git user that is responsible for the module. Website points to a module website (preferably, where documentation lays).
The license_name and license fields specify license of the module and the description should provide a short description for the module.

### 1.8 Comptime Block
It is possible to create a compile time declaration using Axo's comptime mechanisms. More on that in the destined section. Syntax looks like this:
```axo
~~
local libs = {
    Windows = {"-lopengl32", "-lgdi32", "-lwinmm", "-lkernel32", "-luser32"},
    Linux = {"-lGL", "-lm", "-lpthread", "-ldl", "-lrt", "-lX11"}
}
return axo.setFlags(libs[axo.os])
~~
```
The example above can be used to link correct libraries based on the target OS.


### 1.9 Type forwarding
Axo supports forwarding a type definitions which act like a `typedef` in C.
```axo
my_t -> t
```
This will result in type `my_t` to be defined as a copy of type `t`.

## 2. Statements
Statements are a key component of any C-like language and Axo doesn't really change much here. The only exception is that users rarely have to use `;` to end of a statement. In fact, most statements do not require the use of semicolon at all.
A list of most widely used statements can be found below:
- A variable declaration
- An expression statement (without `;`)
- An empty statement (denoted as `;`)
- A loop (for, for each and while)
- An `if` statement
- Return statement
- Break and continue statements

For more precise information one can always inspect the automatically generated grammar file.

### 2.1 Loops
Loops are a main way to iterate over value in Axo. Currently Axo only supports 3 types of loops.
Unlike in C, Axo loops don't require parenthesis around the condition part of the loop. Just like in C, they run statements and therefore scopes (noted by braces `{...}`) are not needed when only one statement has to be iterated in a loop.

#### 2.1.1 The `while` loop
The most simple loop that requires a single condition and the running statement. This loop will perform as long as the condition inside is `true` or in other words, non-zero. Below is how the syntax works:
```axo
while condition
    statement
```

#### 2.1.2 The `for` loop
The `for` loop is exactly what one could expect a `for` loop to be. It uses this syntax:
```axo
for start, condition, change
    statement
```
Such loop will start by running the `start` statement and then attempting to run `statement` as long as `condition` expression evaluates to `true`. It will perform `change` statement after each successful iteration.

#### 2.1.3 The `for ... each ... in` loop
This loop can be used to iterate over arrays more easily. The syntax can be observed below:
```axo
for elem each [i] in array
    statement // elem is the iterated value, i is the index
```

### 2.2 Loop interrupts
There are 2 statements that are specific to loops and can only be used inside one. Each one of these only affects the inner-most loop.

#### 2.2.1 Break statement
Break statement can be used to immediately stop iterating a loop after encountering the statement.
```axo
a = 12
while true {
    ~print(a++)
    if a == 20 break
}
```
The above will print `a` from 12 to 20.
#### 2.2.2 Continue statement
Similar to break, continue statement can be used to just skip the current iteration in a loop.
```axo
a = 12
while true {
    ~print(a++)
    if a == 16 continue
    if a == 20 break
}
```
This will make it so 16 isn't printed and the loop goes back to checking the condition immediately.

#### 2.3 Expression statements
Any expression is also a valid statement just like in C. However, it doesn't require the use of `;`.
```axo
fn main(){
    1
    "hello world"
    ~print("Hopefully this compiles!")
}
```
Note that in the above example only one statement actually has any effect and the rest will be discarded by the finalizing C compiler.

#### 2.4 Return statements
Return statements can be used to return a value from a function. They do not work for returning a value out of a scope, just like in C. It uses a different keyword though:
```axo
ret some_value
```
Using a return statement outside a function body will result in an error

#### 2.4.1 Empty return statement
To return without a value, the following syntax has to be used:
```axo
ret;
```

#### 2.5 Block scopes
It's possible to group a list of statements into one statement using a scope block. Note that such union will not be atomic. Main uses of this structure is for loops, conditions and to have a separate scope. While using block scopes does create a new scope, it will also gain access to all modules and variables of the parent scope.
```axo
{
    a = 12
    {
        // This works, because of scopes inherit parent variables
        b = a+12
        ~print(b)
    }
    // This will fail as 'b' is no longer in scope
    ~print(b)
}
```

### 2.6 Defer statement
Borrowed from other languages, Axo introduces defer statements. They work for scopes only. This is useful particularly when one wants to ensure some memory being deallocated after use without having to remember about it in the later section of the code.
```axo
fn foo(){
    s = str.alc("Hello world")
    defer s.free()
    // Use string here
    // ...
    
    // No need to free memory after use, since it has been deferred already!
}
```

### 2.7 Variable declarations
Axo heavily leverages the principle of defaulting, which means it will attempt to deduce types if that's possible. One of the examples can be seen with variables declarations.
One can denote a typical variable declaration with the following syntax:
```axo
name = value
```
Notice how it is the same as assignment, but despite that fact it is not treated as an expression. Axo accomplishes that by checking if the variables that is to be assigned with a new value has been declared and it does so at compile time.
This syntax takes the variable type from the initially assigned expression.
This is the main syntax that should be used to declare a variable which means Axo encourages the use of initial values.
However, one can use the following syntax to declare a value without initial assignment:
```axo
name = none type
```
where `none` is a keyword.

### 2.8 The if statement
The `if` statement is probably the most widely known code structure that can be used to conditionally run a certain part of code. Just like in many other languages, Axo also has `else` statements that can be used strictly after an `if` statement.
```axo
if condition
    statement_1
else
    statement_2
```

## 3. Expressions
Expressions are mostly how they are in C. Each expression must have a type and can be used to describe a value.
Below is a brief list of what counts as an expression in Axo:
- A literal
- An l-value
- A function call
- A binary operation
- A macro expansion "call"
- Assignment
- Other built-in expressions (ie. sz_of or modules)

For more precise information see full grammar.

### 3.1 Comptime lexer positions
Axo provides a way to get the lexer position such as file name of the currently parsed file as well as the column and line number.

#### 3.1.1 #line
Expression that is replaced with the current line in the code.
```axo
~print("Hello from line ", #line)
```

#### 3.1.2 #column
Expression that is replaced with the current column in the code.
```axo
~print("Hello from column ", #column)
```
#### 3.1.3 #file
Expression that is replaced with the current file in the code.
```axo
~print("Hello from file ", #file)
```

### 3.2 Literals
Literals are used to denote a well known compile time value in a simple fashion. Axo shares similar syntax to C, but there are some important differences.

#### 3.2a Default literal types
Each literal type is given a unique default type, for example:
```axo
0
-12
540
```
All numerical literals without a point `.` are assumed to be `int` literals.
All numerical literals containing a `.` in them are assumed to be `f32` and `true` and `false` values are assumed to be of type `bool`.
String literals are assumed to be of type `@byte`, not `[]byte` which is different from the C equivalent of `char[]` and is closely tied to what arrays are in Axo.

### 3.3 Module access
To access a module one should use the following syntax:
```axo
    module_name::field
```
The syntax is quite similar to C++ namespaces.

### 3.4 Operators
### 3.4.1 Binary operators
Axo supports most widely known binary operators such as:
- Addition and substraction (`+` and `-`)
- Multiplication and division (`*` and `/`)
- Modulo (`%`)
- Unary minus (`-expr`)
- Negation (`!`)
- Binary AND and OR (`&&` and `||`)
- Bit shift operators `>>` and `<<`
- Comparasion operators `<`, `>`, `<=` and `>=`
- Equality operators `==` and `!=`
with the classic operation precedence. Using parenthesis is also supported to indicate a non-default precedence between any operations in a typical fashion.

### 3.4.2 Notable operator changes
Some operators were either sligthly changed or remade completely in. Most of the changes were made to either use a seperate, more visually cohesive notation or to allow for better chaining.

#### 3.4.2a Referencing and dereferencing
Axo uses `@` and `.` for taking a pointer of a value and dereferncing a pointer respectively. Please note that the latter is commonly avoided as Axo comes with auto-dereferncing in most cases and is most commonly used when casting to a specific type.
```axo
a = 12
b = a@ //b now points to a
c = b. //c is now 12
```
#### 3.4.2b Assignment
Assignement uses the classic syntax of `lvalue = expression`. However, since syntactically it is the same as declaration with assignment such syntax can only be used once a variable is defined.
```axo
if (a = 12) == 12
    //Do something
```
The above code would only compile if `a` is declared somewhere before.

Axo also supports special assignements, which are just shorter assignment with an operator. These include: `+=`, `-=`, `*=`, `/=` and `%=`.

#### 3.4.2c Indexing
Indexing can be done with the following syntax:
```axo
expression[index]
```
It is worth noting that only array and pointer expression can be treated with indexing and they both behave a little different. More on that in the arrays section.

#### 3.4.2d Getting size
Simillar to C, Axo allows to get the size of epxressions and types, but unlike C it uses two different operators for that; sz_of (which works with expressions) and type_sz (which is for types).

#### 3.4.2e Shortened decreasing and increasing
Axo only supports suffix increasing of an lvalue.
```axo
a = 1
a++ //This is valid
++ //This is not allowed
```

### 3.4.3 Type casting
Type casting in Axo has been changed slightly comparing to C:
```axo
expression.(cast_type)
```
This allows for clear chaining that doesn't require the programmer to memorize the precedence as most type related operators like taking pointer of an l-value or dereferncing it is done as a suffix operator, which makes the precedence more readable.
