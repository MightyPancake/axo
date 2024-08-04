#### Introduction

##### The Problem
Learning low-level languages can be beneficial to both efficiency and enjoyment. Not only does it allow for a deep understanding of the underlying problems, but overcoming them with more limited and traditional, low-level tools can be fun and generally feel rewarding.

###### Good, but Old Standard
For over 50 years, the C language has been the gold standard when it comes to low-level languages. Nowadays, many languages aim to become "the next C," but as it turns out, it's really difficult to beat C. Its age is both its biggest downside and its biggest strength. On one hand, the syntax and possibilities built into the language itself seem limited, but on the other hand, its toolset has been refined for half a century. The amount of reusable code is immense. It's no coincidence that most languages have bindings to C and not to other languages. It acts as a bridge and has become a unique staple of programming.

###### C's Double-Edged Sword
Because of its simplicity, C is treated as a great language for beginners in low-level programming. No classes, no polymorphism, no interfaces; just pure logic. However, it's really hard to deliver a simple and clean language without underdelivering some essential features that make everyday programming easier.

##### Proposed Solution
The solution to this problem would be a language that provides all the things C does, but with a few twists and shortcuts. One of the core features of the language is default values and types. In other words, there are places in code where assumptions can make it look less chaotic and speed up coding in general. However, it's always possible to specify things in detail if needed. Given the nature of default values growing where they're needed, it reminded me of the axolotl's ability to regenerate limbs. Thus, the name axo (short for axolotl) was chosen.

The axo programming language attempts to tackle (and possibly solve) things I found really incoherent and inconvenient in C. The goal is rather straightforward: a language that transpiles to C and is well integrated with it, while having a readable, modern syntax that enables many shortcuts without significantly hurting speed.

```diagram
  Compilation Process

  aaxo code ---axo compiler---> C code ---C compiler---> output
```

Of course, compilation speed will suffer since the code has to be compiled twice, but the benefits of writing the same code faster should outweigh this inconvenience. The code is expected to preserve near-C performance wherever possible. Programmers (who will also be referred to as 'users' later on) are expected to know basic low-level techniques, but axo also makes it easy to learn them.

The entry level is not high, but it's possible to write faster code once the user becomes familiar with the language.

###### Pros

- **Easy C interop**: Since everything is translated to C, binding and generally interacting with it will be as easy as it gets.
- **Speed**: Assuming the implementation is done correctly, it's possible to achieve good runtime speed.
- **Ease of implementation**: Transpiling to C means it's possible to skip many optimization steps as they'll be handled by the given C compiler during the second phase of compilation. This means that implementing a working and generally fast implementation will be significantly easier than it would be otherwise.
- **High range of targets**: Because C is a well-supported language in most environments, it will be easy to port axo to other platforms such as Windows, Mac, Web (using WebAssembly), and even Android, as well as any other platform that can run C. Adding additional targets is also easier because most of the work is again done by the second-phase C compiler.

###### Cons

- **Long compilation times**: Because the code is compiled twice to get the output, the time it takes to convert the code into binary output will be elongated accordingly.
- **Dealing with C caveats**: Some things are really tricky to do in C (variable declaration can become quite tricky with more complex data types, for example) and having to implement them backward can be quite a challenge.
- **Future**: Because C is a rather old language, it might not receive new and exciting features as quickly as other modern low-level languages (like Zig or Rust). This necessity for backward compatibility might hold axo back in the future.

##### Summary

In summary, axo is an attempt to modernize C in various ways such as: updating the syntax, enhancing the standard library with more functionality out of the box, syntactically supporting more constructs (such as dynamic arrays), providing a package manager, a simple testing system, and a more powerful macro system than C's preprocessor. The project isn't meant to "become the next C" or surpass it in any way, but rather to work with it and provide a much-needed layer of quality-of-life adjustments. One of the professors at my university called it "TypeScript, but for C," and I agree with that statement.

As a side note, in my opinion, the main difference between these core languages is that C has a good design but just got old, while JavaScript has a well-known reputation for questionable design choices that are somewhat beyond fixing. There have been many attempts to address them, but that's beyond the main topic. Having a new framework or flavor of a language that is meant to be better than the original or previous attempts at fixing it says a lot about the main design itself.

