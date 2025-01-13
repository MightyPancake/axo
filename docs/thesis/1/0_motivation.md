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
