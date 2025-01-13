# Semantics

## 1. Compiletime

### 1.1 The type system
Types are a big part of a language, specifically when the design assumes static types which is the case for Axo. While the types themselves are really the simplest they can be, ther representation in syntax is convoluted.

#### 1.1.1 Primitive types naming
Primitive types in C are a bit odd both in terms of naming convention. Because of this, most C types have been aliased in Axo to be more modern and therefore make more sense to the common user.
The best example here is renaming of the `char` type to `byte` which reflects better the avarage usage of this type and gets rid of the original stigma which was tied to always using ASCII as the default way of text representation, which is simple not the case in the XXI century.
Most numerical types have been given some much needed abbrevations that were inspired by other modern languages, like `long int` being renamed to `i32` instead, which results in a more readable and faster to type code. Technically, this isn't the best way of dealing with this, because `long` doesn't explicitly describe the size, but in practice almost any modern C compiler matches the size. The complete reference can be found in the table below.

| **C**             | **axo**|
|-------------------|--------|
| char              | byte   |
| float             | f32    |
| double            | f64    |
| long int          | i64    |
| unsigned int      | u32    |
| unsigned long int | u64    |
| void              | none   |

#### 1.1.2 Complex types and variable declarations
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

#### 1.1.3 Pointers
The following syntax can be used to denote a pointer to type `t` in Axo:
```axo
@t
```
Note that the classic `*` has been replaced with `@` as it reads 'at' which followed by the type reads out what the type is. As an example `@int` is will not a type that points *at* an integer. This also removes ambiguity with mulitplication use of the `*` character.
Note that `t` can be any complex type (ie. other pointer, array or a function pointer, but also just a primitive type).

#### 1.1.3a Function pointers
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

#### 1.1.4 Arrays
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

#### 1.1.5 Summary of complex types
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

#### 1.1.6 Structures
Structures in axo remain mainly the same as they are in C. They consist of fields which can be assigned to and read from. By default all structures are passed by value, therefore it's advised to use pointers to structures if that behaviour is not desired.

#### 1.1.7 Enums
Enums can be used when only certain values can be allowed as a value of a certain type. For example, when defining a chess game it might be useful to have an enum for the various piece types like pawn, bihop, knight etc.
Currently, axo doesn't allow for specifying exactly the underlying type for an enum, so the final size of the type is left to the C compiler to figure out.

##### 1.2 Methods
It's possible to use a method-esque syntax to call a function using a certain instance of a structure. By doing so, the structure will *always* be taken as a reference, so a pointer of the underlying structure will be used.
Note that axo doesn't support Object Oriented aproach and this feature is present merely to make code more readable and allow for method chaining, which simplifies the code and makes it shorter.

## 1.3 Defaulting
One of the core features is the defaulting system in axo, which relies heavily on the type system itself and can be used to ommit writing out a type entirely in most cases.
This can be seen when declaring a new variable
```axo
num = 10 // is of type int
```

or making a new function or structure declaration.

```axo
fn add(a=0, b=0){ret a+b}
// Both arguments default to `int` here.
```

This works for types, as well as __values when a type is defined__.
```axo
fn add(int a, int b){ret a+b}
// Both arguments will default their value to 0 as it is the default for type `int`.
```

Defaulting is done by supplying needed values to the generated C code directly.

## 1.4 Module system
The present module system allows for less confusing work with libraries and external tools. This combined with the presence of namespaces creates a tidy environment to code in.

### 1.4.1 Module declaration
Each module declared in axo requires a module declaration containing all the needed information about a certain module. Most of the fields are optional. The `prefix` field can be used to define a custom prefix that will be used for all module functions. Otherwise a prefix will be created based on the name of the module itself.

TODO: Finish this.

## 1.5 Comptime


## 2. Runtime
From the very begining axo was designed to have a minimal runtime penalty and the implementation delivers on that quite well.

### 2.1 Array related runtime
