# Chapter 0

# AXO - a programming language meant to modernize C

# Abstract
This thesis presents the development of Axo, a new programming language. The work is structured into six chapters, each addressing a distinct aspect of the project. The opening chapter outlines the motivation for creating the language and defines its objectives. Chapter 2 explores the fundamental design principles of Axo, with an emphasis on its similarities to and differences from existing programming languages and tools.

Chapter 3 examines the architecture of the compiler, detailing its design and implementation. This includes a step-by-step explanation of the compilation process, the challenges encountered during development, and the solutions implemented. Chapter 4 provides an evaluation of Axo’s performance, focusing on both compilation speed and runtime efficiency, along with an overview of the built-in testing system.

Finally, Chapter 6 offers a comprehensive summary of the project, reflecting on the achievements, insights gained, and potential directions for future work.

This thesis is also published online and can be accessed at https://www.axolang.com.


# TODO


# Chapter 1

# Motivation
Programming has always appealed to me because of its inherent challenges, particularly when working within imposed limitations and creating solutions from scratch. This is why low-level languages have been a personal favorite. Their philosophy of being close to assembly-level code while remaining human-readable, and offering only basic constructs while leaving the rest to the programmer, is both intriguing and rewarding.

Learning and using low-level languages provides significant benefits. They encourage a deep understanding of underlying systems and problems, and the process of solving these challenges with limited tools can be both enjoyable and fulfilling. Additionally, the potential performance gains often associated with low-level languages are invaluable in many applications.

## Good, but old standard
For over 50 years, the C language has been the gold standard in low-level programming. Many modern languages aspire to replace it as the foundational systems language, but this has proven to be an incredibly difficult task. C's age is both its greatest weakness and its greatest strength. Its syntax and feature set may seem limited by today’s standards, but its simplicity has enabled decades of refinement in tooling and libraries. The ecosystem built around C is unmatched, with an immense repository of reusable code and widespread support across platforms. It serves as a bridge language, with most modern languages providing bindings to C rather than any other language.

## C's Double-Edged Sword
C’s simplicity makes it an excellent choice for beginners exploring low-level programming. It strips away complexities such as classes, polymorphism, and interfaces, leaving the programmer with pure logic. However, delivering a simple and clean language often comes at the cost of omitting features that make programming more efficient or user-friendly.

For example, C lacks a module system and namespaces, which are essential for organizing and scaling codebases. Its standard library is intentionally minimal, leaving the definition and implementation of many data structures to the user. While this aligns with C’s philosophy of offering total control, it can lead to inefficiencies, particularly for programmers accustomed to modern conveniences.

## Tooling and libraries
One of C’s most significant limitations is its lack of built-in support for common data structures like hashmaps, dynamic arrays, or sets. While this supports C’s goal of giving programmers complete control, it often slows down development, as creating these structures from scratch is time-consuming.

Another critical shortcoming is the absence of a package manager. Developers are forced to manually search for and integrate external implementations, making the process of building and maintaining a project unnecessarily exhausting. These issues with tooling and libraries create friction that modern developers may find hard to justify.


## Defaults
C’s minimalism extends to its lack of reasonable defaults, a design decision that often creates unnecessary complexity. For example, default parameters for functions are not supported. This limitation can lead to verbose and cumbersome code, as seen in the following example:

```c
t result = some_func(&value, 2, NULL, NULL, some_lib_default_flag, 0);
```

With better default handling, the same function could be simplified to:

```c
result = some_func(&value, 2)
```
Such omissions make C less convenient for common use cases, even when it remains powerful for highly specialized tasks.

## Objects
The use of objects is a polarizing topic among programmers. While some prefer the organization they offer, others find them cumbersome. Although I appreciate grouping functions by the structures they process, features like polymorphism or inheritance are often implemented poorly or misused. For this reason, Axo avoids these concepts entirely. Instead, the language adopts an object method syntax (syntax only) to enable method chaining. This will be discussed further in the next chapter on syntax.


# Objectives
The objectives of this thesis are as follows:

## Develop a Blueprint for Axo
Establish a clear design for the language, including its syntax, semantics, and core principles, to ensure its consistency and usability throughout development.

## Implement a Compiler
Create a fully functional compiler for Axo, translating source code into executable machine code with a focus on simplicity, performance, and reliability.

## Assess Language Performance
Evaluate Axo in terms of runtime efficiency and compilation speed, benchmarking it against similar languages to identify strengths and areas for improvement.

## Enhance Accessibility
Build a comprehensive website for Axo, including detailed documentation and a web-based playground for hands-on experimentation.

## Promote Testing and Debugging
Include a built-in testing framework within Axo to improve the developer experience.



# Scope
The scope of this project is defined by its primary goals and limitations, focusing on the design, implementation, and presentation of Axo as a programming language. Each aspect of the scope establishes the boundaries and practical outcomes of the work.

## Design
The initial phase of the project focuses on designing the Axo programming language. This involves creating a comprehensive blueprint to ensure the language's syntax, semantics, and overall structure align with its intended purpose. A robust design minimizes the need for extensive changes during development, saving time and effort.

## Compiler
To bring the language to life, a compiler is developed. A compiler was chosen over an interpreter to emphasize Axo’s low-level, C-like nature while striving for simplicity and ease of use. The compiler is designed to translate Axo code efficiently into human-readable C code which later gets translated to the target.

## Github
The project will be hosted on a well-organized GitHub repository to facilitate community engagement. The repository will include the source code, build instructions, and automated testing for each supported platform to ensure stability and maintainability.

## Website
In addition to a GitHub repository, the project includes the development of a dedicated website. The website will provide comprehensive documentation and an interactive web-based playground, allowing users to explore the language without the need for local setup. This enhances accessibility and allows for experimentation in scenarios where a computer may not be available.



# About
I started programming when I was about 13 years old through the world of video games. After making a few small games myself I noticed that some aspects are present in each game, so I decided to make a library that would work on top of a framework I used back then called LOVE2D and would elevate the usage experience to be similar to a game engine. After that, I wanted to replace the underlying framework with my own, which I did. I implemented it in Go and while I do agree with the design of Go programming language, I was annoyed at times, so I ultimately decided to go for my own programming language where I could finally have exactly what I want.
One of the most important factors of making a language I would enjoy was making it easy. I do believe that everything should be straightforward; after all the programming languages are there to help overcome issues, not create them with their weird syntax or too abstract behaviour.
Becasue of that I started working my journey by attempting to create 3 interpreted languages. Every next one, I felt like I was a step closer and the experience overall felt really rewarding; I actually felt like I learn a lot during my little design and implementation trials.
Although I believe things should be easy I also believe in innovation. Just because something is unfamiliar, doesn't mean it is a bad design. I tried that aproach in my latest attempt at an interpreted language, which I named QIK. It was meant to be easy, but also very flexible, but talking about its precise goals and specifications is beyond the scope of this thesis.
The issue arise at the end of the project, which was rather unfortunate. One of the issue was the performance of the langauge itself; altough the interpreter was written in pure C, it was still unoptimized, so benchmarking it with Lua made the speed issue very apparent.
The other thing was the implementation itself; I did everything myself, that includes the parser and lexer. While I do not think this is not sometimes the right aproach, taking a look at this with my current knowledge makes me question my decisions. I wasn't really aware how lexers and parsers are supposed to work, so the implementation was really naive.
The last problem was definitely lack of memory management. It was a glairing issue in my original design of QIK. I could either fix that by writing a garbage collector (which would make it even slower) or just give up and state manual memory management which didn't fit the whole "being easy" narrative and is really incohirent with dynamic languages in my opinion, which are destined to be slower then statically typed solutions.
It just so happened that I was talking with my friends from US and one of them was implementing a compiler himself, so I asked how do I aproach this subject. Not a month later I had classes at my university about compilers, so the choice was really influenced by these two factors, thus making it more natural to go with the tools presented to me at the classes I took (even though I still remember I didn't have the best grade from that course, but to be honest it was really insightful).
The tools, namely flex and bison, solved the issue of poorly written lexer and parser by providing a working, well established alternative which even used my beloved C.
As for the performance issues, I listened to that one friend and decided to transpile to C and rely on the final C compiler in terms of optimization.
And with these in mind I started on implementing the language itself.

# Chapter 2

# Similar Languages
It is almost impossible to create something entirely new, and claiming that this project is absolutely unique or uninfluenced by other programming languages would be inaccurate. This section discusses some of the languages and features that inspired Axo. It also explores why these languages, despite their merits, do not entirely align with Axo’s vision. In essence, each language contributed something valuable but also had inherent characteristics that clashed with Axo’s goals.

## C
C is the most obvious candidate and the foundation for Axo’s design. Some key similarities and differences have already been discussed in earlier sections, but to reiterate briefly: C is an enduring standard in programming. However, while it has stood the test of time, it lacks certain functionalities that are expected in modern languages today, even ones that would not conflict with its core design principles.

Programmers owe much to C for its contributions to the industry, but there is room for improvement. This is evident in the growing trend of attempting to create “the new C.” Despite its importance, C is not particularly easy to learn or use, even for developers with prior experience.

## Go
Go is a syntax-friendly language that is straightforward and easy to read. Its simplicity and predictability are some of its strongest features, making it highly approachable for developers. Reading Go code is intuitive, as it avoids hidden behavior. It has quickly gained popularity among developers (SURVEY Reference Here), owing to its sense of familiarity despite being a relatively new language.

However, Go achieves this simplicity by relying on garbage collection, which introduces a performance trade-off. While its garbage collector is efficient, this reliance inherently slows down execution and contradicts Axo’s goal of offering low-level performance.

## Rust
Rust is another relatively new language that has earned widespread acclaim from developers. Axo shares some syntactic similarities with Rust, which were cleverly pointed out by a colleague. Interestingly, Rust was not a direct inspiration for Axo; the similarities arose coincidentally.

Despite its undeniable popularity, Rust diverges significantly from Axo’s vision. Its emphasis on memory safety introduces a steep learning curve, requiring developers to adopt an entirely new paradigm of memory management that is uncommon in most other languages. While Rust’s features are impressive, its complexity makes it unsuitable as a model for Axo, which aims to remain simple and accessible.
On top of that, Rust design has some flaws which are tied to the fact of C interop having obvious design missmatch with that of Rust, while being the most widely used standard.

## Zig
The last language worth mentioning is Zig. Like Axo, Zig seeks to complement C rather than compete with it, extending its design principles in thoughtful ways. Axo’s compile-time behavior and capabilities were directly inspired by Zig.

That said, Zig’s syntax, while designed to be easy, includes an overwhelming number of features. This complexity requires a deep understanding, making it less approachable than one might hope. Axo strives to avoid this pitfall by maintaining a balance between functionality and simplicity.



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

### 2.2 Loop interrupts
There are 2 statements that are specific to loops and can only be used inside one. Each one of these only effects the inner-most loop.

#### 2.2.1 Break statement
Break statement can be used to immidietely stop iterating a loop after encountering the statement.
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
This will make it so 16 isn't printed and the loop goes back to checking the condition immidiately.

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
Return statements can be used to return a value from a function. They do not work for returning a value out of a scope, just like in C. It uses a different keywoard though:
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
It's possible to group a list of statements into one statement using a scope block. Note that such union will not be atomic. Main uses of this structure is for loops, conditions and to have a seperate scope. While using block scopes does create a new scope, it will also gain access to all modules and variables of the parent scope.
```axo
{
    a = 12
    {
        //This works, because of scopes inherit parent variables
        b = a+12
        ~print(b)
    }
    //This will fail as 'b' is no longer in scope
    ~print(b)
}
```

### 2.6 Defer statement
Borrowed from other languages, Axo introduces deffer statements. They work for scopes only. This is useful particulary when one wants to ensure some memory being deallocated after use without having to remember about it in the later section of the code.
```axo
fn foo(){
    s = str.alc("Hello world")
    defer s.free()
    //Use string here
    //...
    
    //No need to free memory after use, since it has been deffered already!
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
However, one can use the following syntax to declaare a value without initial assignment:
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

### 3.4 Binary operators
Axo supports most widely known binary operators such as:
- Addition and substraction (`+` and `-`)
- Multiplication and division (`*` and `/`)
- Modulo (`%`)
- Unary minus (`-expr`)
with the classic operation precedence. Using parenthesis is also supported to indicate a non-default precedence.


TODO: Finish this.

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




# TODO


# Chapter 3

# TODO


# TODO


# TODO




# TODO


# TODO


# Chapter 4

# TODO


# TODO


# TODO


# Chapter 5

# TODO


# TODO




# Chapter 6

# TODO


# TODO


# TODO


