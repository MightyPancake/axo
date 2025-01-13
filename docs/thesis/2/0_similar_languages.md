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

