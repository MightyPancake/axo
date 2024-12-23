# Syntax
The design of Axo put heavy emphasis on syntax, as it is almost the biggest factor when it comes to user experience. Functionality of the language was really similar to C, but syntax was where most changes were planned.
Providing a simple, friendly looking syntax that would be both intuitive to read, with as little ambigouties while also having some shortucts ultimately lead to programmers having to write less code.

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
There are some directives in Axo that, just like in C, start with the `#` character and are mostly done at compile time. It's worth noting that the current implementation doesn't have a seperate pre-processor as the whole language itself is sort of a huge C preprocessor in a way.

#### 1.1.1 #include
Used to directly copy a C `#include header` directive.
This supports multiple includes seperated with commas like so:
```axo
#include <stdio.h>, <time.h>, "header.h
```
as well as single include statements.

#### 1.1.2 #source
Marks a certain C file to be included in the final compilation
```axo
#source source_file.c
```

#### 1.1.3 #provided
Marks a certain variable as provided by the underlying C compiler. This is widely used for C ABI as a way of communitacting which values are provided by the header or source files used in the code.
```axo
#provided (int fn const @byte, ...) printf
```

#### 1.1.4 #typ
Similar to `#provided`, but for types instead. Add a certain type as a primitive to Axo's type dictionary. Can also be used with a structure declaration to declare the defined structure in axo without including the defintions as a C structure declarations in the outputed C file.
```axo
//Declares size_t as a valid Axo type. This should be used when such type is already defined somewhere else in C
#typ size_t

//Declares my_struct as a valid Axo type without declaring it in C. Similar to previous, but can include exact structure.
#typ struct my_struct (
    int a,
    byte b
)
```

#### 1.1.5 #flag
A definitions that can be used to add a certain flag to the compilation flags in the proccess of compiling the resulting C to binary. Useful for avoiding having to manually link libraries by hand in the compiler command.
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
A function declaration is a way to tell the compiler a certain function prototype. A function cannot called or reffered to before declaration. To be called, the function also needs a definition.
There are 3 ways to declare a function in Axo:
1. Use `#provided` declaration (which assumes the function definition is provided by either one of the C sources or headers)
2. Declare a function with definition
3. Declare a function prototype with no body

The first option was already briefly discussed before and will be further tackled in the C ABI section later in thesis.

#### 1.2.1 Function definition
This is the main way one should define a function. The syntax is the following:
```axo
fn t name(t1 n1, t2 n2, tn nn){
    //Code
}
```
The above definition will declare a defined function that returns type `t` and takes in parameters `n1`-`nn` of type `t1`-`tn` respectively. While this syntax is enough to work with Axo, there are also some provided shortcuts

##### 1.2.1a Inferred return type
Users can ommit providing the return type when defining a function.
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

Default parameters will be discussed fruther in detail later on in the section describing function calls.

##### 1.2.2 Function prototype declarations
It is possible, although should rarely be used, to declare a function without the corresponding body. This allows the compiler to accept calls to that function as valid despite lack of defintion, cause it is assumed such defintion is defined later on.
This is mainly used to define a recursive function and otherwise using this feature is **not** advised as it essentially dodges compile time errors and can be dangerous.
The syntax looks similar, but uses `;` instead of body and requires the return type, since it cannot be inferred from the body which is not present.
```axo
fn t name(t1 n1, t2 n2, tn nn);
```

### 1.3 Structure declarations
Structures are a way to describe a certain data structure by using multiple types bundled into a single structure.
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
### 1.4 Enum declarations
Enums are a datatype that is only limited to certain values.
To declare an enum, as syntax similar to structure is used
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
Note that all enum values like `pawn` or `bishop` are not taking any space in the global scope; they're tied strictly to the enum. This will be disscussed in further detail later on.

### 1.5 Use module declaration
Axo has a system of modules; a simple way to package reusable code.
To use a module simply use:
```axo
use module_name
```
Where `module_name` coresponds to the module name that is needed.

### 1.6 Include declaration
This declaration includes *an axo file*. This shouldn't be confused with the `#include` directive, which is used for C headers. Axo will try to search for the included file locally by resolving the path.
```axo
include "my_source_file.axo"
```
It switches the context of the lexer to the target file and will switch back after the desired file runs out of input data.

### 1.7 Module declaration
Axo modules can contain data about specifics of the module such as description or author. To mark a certain module info, one should use the following syntax, preferably at the top of the main module file (which will be mentioned in the apropriate section).
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
Name field is a unique identifier that wil be used when accessing said module. Version should be set to the exact version of the module.
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
Axo supports forwarding a type defintions which act like a `typedef` in C.
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

For more precise information one can always inspect the automatically genereted grammar file.

### 2.1 Loops
Loops are a main way to iterate over value in Axo. Currently Axo only supports 3 types of loops.
Unlike in C, Axo loops don't require parenthisis around the condition part of the loop. Just like in C, they run statements and therefore scopes (noted by braces `{...}`) are not needed when only one statement has to be iterated in a loop.

#### 2.1.1 The `while` loop
The most simple loop that requires a single condition and the running statement. This loop will perform as long as the conditon inside is `true` or in other words, non-zero. Below is how the syntax works:
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
    statament //elem is the iterated value, i is the index
```

#### 2.2 Expression statements
Any expression is also a valid statement just like in C. However, it doesn't require the use of `;`.
```axo
fn main(){
    1
    "hello world"
    ~print("Hopefully this compiles!")
}
```
Note that in the above example only one statement actually has any effect and the rest will be discarded by the finalizing C compiler.

#### 2.3 Return statements
Return statements can be used to return a value from a function. They do not work for returning a value out of a scope, just like in C. It uses a different keywoard though:
```axo
ret some_value
```
Using a return statement outside a function body will result in an error

#### 2.3.1 Empty return statement
To return without a value, the following syntax has to be used:
```axo
ret;
```

#### 2.4 Code scopes
To treat 
TODO: Finish this

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

#### #line
Expression that is replaced with the current line in the code

#### #column
Expression that is replaced with the current column in the code.

#### #file
Expression that is replaced with the current file in the code.

## Types
Types are a big part of a language, specifically when the design assumes static types which is the case for Axo. While the types themselves are really the simplest they can be, ther representation in syntax is convoluted.

### Primitive types naming
Primitive types in C are a bit odd both in terms of naming convention. Because of this, most C types have been aliased in Axo to be more modern and therefore make more sense to the common user.
The best example here is renaming of the `char` type to `byte` which reflects better the avarage usage of this type and gets rid of the original stigma which was tied to always using ASCII as the default way of text representation, which is simple not the case in the XXI century.
Most numerical types have been given some much needed abbrevations that were inspired by other modern languages, like `long int` being renamed to `i32` instead, which results in a more readable and faster to type code. Technically, this isn't the best way of dealing with this, because `long` doesn't explicitly describe the size, but in practice almost any modern C compiler matches the size. The complete reference can be found in the table below.
| C                 | axo  |
|-------------------|------|
| char              | byte |
| float             | f32  |
| double            | f64  |
| long int          | i64  |
| unsigned int      | u32  |
| unsigned long int | u64  |
| void              | none |

### Complex types and variable declarations
Describing how C variable type declaration syntax works completely is besides the point of this thesis. It is quite mind boggling and is often a point of frustration for new programmers, which leads to many struggles. At the very start of the project, personal knowldge on this topic was rather limited. It took many tests and help to finally grasp how it works. It took a well written article on the matter to understand how it works, which was needed anyway since Axo targets C as it's backend.
Axo differs from C dramatically on that matter. The latter uses what's known as variable oriented declaration, which is the main source of missunderstanding, while the first uses a type-name system, which makes a difference in that is apparent mostly in more complex types.
Because of this, lots of programmers don't fully understand how to write or read declarations. Consider the following:
```c
char *(*(**foo [][8])())[];
```
this is a valid C declaration and it's not even *that* hard, but without proper knowledge one cannot see what it encodes to.
That's because rules responsible for complex types like function pointers and arrays that require a subtype have their rules designed in a very odd way, which looks well on smaller example, for example:
```c
char arr[][4]
```
Looking at the example above it's obvious that it denotes a 2D array of chars, so the rules make a lot of sense here, but in hte bigger picture, like the one presented above, it's clear these rules are not intuitive at all.
Axo goes for a much simpler aproach. User declares a variables by one, standard syntax:
```axo
type name
```
Which still stays intuitive for people that are familiar with C.

### Pointers
The following syntax can be used to denote a pointer to type `t` in Axo:
```axo
@t
```
Note that the classic `*` has been replaced with `@` as it reads 'at' which followed by the type reads out what the type is. As an example `@int` is will not a type that points *at* an integer. This also removes ambiguity with mulitplication use of the `*` character.
Note that `t` can be any complex type (ie. other pointer, array or a function pointer, but also just a primitive type).

### Function pointers
To denote a function pointer, one should use the following syntax:
```axo
(t fn t1, t2, tn)
```
Where t1 is the returned type and t1-tn are the types of paramaters in the correct order. 
Please note that for convinience, functions that do not return a value (therefore return `none`) can be noted with `none` as the return type or by just ommiting the return type entirely, for example:
```axo
(fn int, int)
```

Both the return as well as parameter types can be complex types themselves.

### Arrays
Axo has a very unique aproach to arrays as their type can have two underlying types which can be determined at runtime. The same type is used for dynamic and static arrays. This will be discussed later on, but when it comes to the type syntax itself there's no real difference.
To denote an array of type `t` one should use the following syntax:
```axo
[]t
```
Note that this creates a single dimensional array, but Axo also supports arrays up to 3 dimensions in current implementation. Each dimesions is marked by visually imposing an extra space by using `|` in the braces like so:
```axo
// 2D array of int
[ | ]int

// 3D array of int
[ | | ]int
```
Note that whitespace is optional here and was used to better convery the design fantasy of this aproach.

Please note that N-dimensional arrays are not the same as jagged arrays (arrays that hold arrays), which are valid in Axo too:
```axo
// Array of arrays of char (aka multiple string)
[][]int
```
Both are a valid way of representing data, but each one comes with their pros and cons which will be disscussed later in later chapters.

Unlike C, arrays in Axo are not just contigous spaces in memory, but rather a stucture that is built into the compilers itself.
This means each array value has pseudo-fields that can be accessed with `.field` syntax and pseudo methods which can be used using the normal method syntax which will be covered shortly.

### Summary of complex types
The above information is all it takes to understand any complex type and variable declaration in axo.
The previously mentioned example of C declaration "mess":
```c
char *(*(**foo [][8])())[];
```
can be gracefully represented in axo with the following syntax:
```axo
[][]@(@[]byte fn) foo
```
Which is now more clear and can be read as declaration of *array of array of pointers to functions that return pointers to arrays of byte* with name `foo`. Notice how everything reads nicely from left to right and can be easily translated to english without any mental gymnastics.

This aproach also means that the variable declaration syntax does not need parenthis do determine the precendence of each complex type construction, which is unfortuntely the case for C. This also means that outside of function types, parenthesis are not usable in declarations, which can prevent users from making a questionable choice of declaring their variables like this:
```c
// This is a valid C variable declaration
int ((((a))));
```

## Literals
Literals are used to denote a well known compile time value in a simple fashion. Axo shares similar syntax to C, but there are some important differences.

### Default literal types
Each literal type is given a unique default type, for example:
```axo
0
-12
540
```
All numerical literals without a point `.` are assumed to be `int` literals.
All numerical literals containing a `.` in them are assumed to be `f32` and `true` and `false` values are assumed to be of type `bool`.
String literals are assumed to be of type `@byte`, not `[]byte` which is different from the C equivalent of `char[]` and is closely tied to what arrays are in Axo.

## Variable declarations
Some key aspects were already brought up in the type section of syntax, but there are more details strictly typed to variable declaration in Axo that are crucial to its design.
Axo heavily leverages the principle of defaulting, which means it will attempt to deduce types if that's possible. One of the examples can be seen with variables declarations.
One can denote a typical variable declaration with the following syntax:
```axo
name = value
```
Notice how it is the same as assignment, but despite that fact it is not treated as an expression. Axo accomplishes that by checking if the variables that is to be assigned with a new value has been declared and it does so at compile time.
This syntax takes the variable type from the initially assigned expression.
This is the main syntax that should be used to declare a variable which means Axo encourages the use of initial values.
However, one can use the following syntax to declaare a value without initial assignment:
```axo
name = none type
```
where `none` is a keyword.