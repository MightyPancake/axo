##### Motivation
Since my early days of programming one of the most liked characteristics of coding was having some imposed limitations and making things from scratch, which is most likely why I really enjoy low-level languages.
I really like the philosophy of being really close to the final assembly, while staying human readible. I also like how it provides just basic concepts, but the rest is up to the user.
Learning low-level languages can be beneficial to both efficiency and enjoyment. Not only does it allow for a deep understanding of the underlying problems, but overcoming them with more limited and traditional, low-level tools can be fun and generally feel rewarding.
Besides, the potential speed gain can drastically matter.

###### Good, but Old Standard
For over 50 years, the C language has been the gold standard when it comes to low-level languages. Nowadays, many languages aim to become "the next C," but as it turns out, it's really difficult to beat C. Its age is both its biggest downside and its biggest strength. On one hand, the syntax and possibilities built into the language itself seem limited, but on the other hand, its toolset has been refined for half a century. The amount of reusable code is immense. It's no coincidence that most languages have bindings to C and not to other languages. It acts as a bridge and has become a unique staple of programming.

###### C's Double-Edged Sword
Because of its simplicity, C is treated as a great language for beginners in low-level programming. No classes, no polymorphism, no interfaces; just pure logic.
However, it's really hard to deliver a simple and clean language without underdelivering some essential features that make everyday programming easier.
For starters, C doesn't have a module system nor does it have namespaces. Its standard library is also very minimalistic, which is somewhat understandable for the design because it's up to the user to define the data structures up to the task.
And that's generally a good thing, that's exactly what C aims for; total control for the programmer, but there are a few things that can really grind the gears of some programmars of todays era.

###### Tooling and libraries
Lacking a simple standard implementation for hashmaps or even dynamic tables or sets is one of the biggest caveats one has to tackle while working with C. Again, it works just fine if you aim for absolute control, but sometimes you just need something to work relatively soon in the development process and having to implement data structures from scratch can slow down developement by a lot.
Having no package manager also doesn't help with this issue and that's the final nail in the coffin that is C tooling; having to search the web for simple data structure implementations manually can be really exhausting.


###### Defaults
The extension of this problem can be generally brought to the lack of good defaults. While one could solve the issues related to tooling by just providing an extension of the standard library, but the lack of defaults is the problem of the design itself.
One obvious example of this which can be seen very early on when working with C is the lack of default parameters in functions. Some functions take in pointers, but accept NULL, while other take flags. Because of that a large part of the code looks like this:

```c
t result = some_func(&value, 2, NULL, NULL, some_lib_default_flag, 0);
```

while in reality, it could look like this:

```c
result = some_func(&value, 2)
```


##### Objects
Objects are a touchy subject; some programmers hate them, others couldn't work without them. While I do like grouping functions by the type of structure they proccess, some mechanisms like polymorphism or inheritence has to be done correctly and frankly, that's rarely the case.
Therefore, I didn't want any of that. What I wanted is the object method syntax (and syntax only), which would allow for method chaining. I'll disccuss this further while talking about syntax in the next chapter.
