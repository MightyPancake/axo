# General info
The axo programming language is statically typed and compiled to C which then gets compiled to the output program.

It's designed around a few fundamental concepts:
  1. Deafults - Types and values have some natural defaults.
  2. Chaining - You can chain operations together. It's somewhat functional in this aspect.
  3. Less is more - The languages design makes it so you can do complex stuff in less bytes of code.


# Types

## Primitives

All primitive types are mapped from C.
> [!NOTE]
> Some types got their named changed for convinience purposes! Below is a list of such cases.

| C                 | axo  |
|-------------------|------|
| char              | byte |
| float             | f32  |
| double            | f64  |
| long int          | i64  |
| unsigned int      | u32  |
| unsigned long int | u64  |

## None
None is a replacement for C's `void`. It's just a different type name that reflects the lack of type.

You cannot directly really create `none` typed expression, but you can make pointers to unknown type.

It's also used to specify the lack of return value from a function.

To denote `none` just type it in:
```axo
none
```

## Pointers

Pointers have their syntax changed a bit. Instead of using '*', pointers use '@'. It makes more sense to use the 'at' sign.
To denote a pointer to type `t`, use the following syntax:
```axo
@t
```
As you can see it's even easier to read. It reads 'at t' which is exatly what such type will point at!

## Arrays

### Dimensions
Each axo array will also have a number of dimensions.

### Notation

To denote an array that holds elements of type `t`, use the following syntax:
```axo
//1D array of t
[]t
//2D array of t
[|]t
//3D array of t
[||]t
```
As you can see the '|' operator is used to create spaces inside the brackets '[]' to tell how many dimensions there are in a given array type.

### Pseudo fields

Each array has the following pseudo fields that you can access:
  1. data - Pointer to data of the array.
  2. len - Pointer of length equal to field 'dims'.
  3. dims - Amount of dimensions.
  4. dynamic - `true` if array is dynamic, false otherwise.
  5. static - `true` if array is static, false otherwise.
  6. cap - Capacity of the current array pointer. Can be changed using `cap(n)` method.
  7. empty - Wether an array is empty. Read only.
  8. first - Gets the first element.
  9. last - Gets the last element.

> [!Attention] Static arrays cannot have their elements changed or data resized! They're only meant for reading!

> [!NOTE] Some of these fields are read only for dynamic arrays, but all fields are read-only for static arrays.


## Function pointers
Function pointers can be used for a type that specifies a pointer of a function signature.

You denote functions pointer types like this:
```axo
//Function that takes in t1, t2 and returns rt.
(rt fn t1, t2)

```

If the function returns nothing you can either say it returns `none` or just ommit the return type:
```axo
//These 2 will result in the same type
(none fn)
(fn)
```

## Structures
Structures work just like you'd expect them to work. To declare a structure use the following syntax:
```axo
//Declare a struct type
struct my_struct(
  int a,
  b=3.14,
  int c=12
)
```
The code illustrates that there are 3 ways of declaring a field in a struct. Each differs in behaviour from others:
  1. Provide type - Creates a field with given type and sets the default value to the default of the given type.
  2. Provide default value - Same, but sets the field default value to the provided one and gets the type from it.
  3. Provide default value and type - Best solution, manually provide both.


### Enums
Enums are as straightforward as they're expected to be:
```axo
//Declare an enum type
enum chess_pieces(
  pawn,
  bishop,
  knight,
  rook,
  king,
  queen
)
//Access it
chess_piece^pawn
```

# Variables
