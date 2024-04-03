# What's axo?

Axo is a statically typed, general-purpose programming language that aims to be a modern take on writing (and using) C code thus making it a cool tool to have when it comes to writing code fast and keeping at from running slow.


## Sample code
```axo
use std

//Main program entry point
fn main([][]byte args){
    //Write each argument
    for each [i], arg in args
        printf("Argument #%d: %s\n", i, arg.data)
    ret 0
}
```

```terminal
    >|info|axo main.axo
    |success|Compiled!
    >|./main Hello world !
    |Argument #0: ./main
    |Argument #1: Hello
    |Argument #2: world
    |Argument #3: !
```

<div style="text-align: center;">
    <img src="images/axo_coding.png" alt="axo playing with c" width="35%"/>
</div>

## Features
Below is a list of just some of the language's numerous features.

### Beginner friendly
One of axo's goals was to make an easy-to-learn and read language that is also fast. It should be really simple to learn, even despite not being dynamic, because of its syntax, shortcuts, and convenience changes over C/C++.

### *C*-mpli-*C*-ty
During development keeping the language as simple as possible was one of (if not **THE**) main features. Axo essentially emphasizes and tries to go with the idea of making things as simple as they should be. Write code and run it. That's what it's all about!

It should be fun; no OOP, no keywords that rot in your brain that are not being used 99% of the time, and overcomplicated build and test systems. Just you, simple syntax, speed, and the wind blowing in your hair... (Unless you're bold, but the point remains).
<div style="text-align: center;">
    <img src="images/axo_c.png" alt="axo playing with c" width="35%"/>
</div>


### Reusiblity
Axo's official implementation is a C transpiler. The generated code can be saved, looked upon, and modified. There's also support for just directly compiling the result to a program using one of the supported C compilers or plugging your own.
It's really easy to grasp how the axo's meta glue code works and build upon it.
Thus, it's extremely simple to use existing C code in your axo projects!

## State
Currently, the project is in its very early stages. There are a ton of bugs and things are not checked or guaranteed to work! The syntax might *(and most likely will)* change. Most things should work though. If you encounter any issues, please let me know either on GitHub (which is preferred) or Discord!

## What axo *isn't*
Keep in mind that axo doesn't claim to be faster or even on pair with C in terms of runtime speed. Altough most of the code should be really as fast as C. **Axo doesn't and will never claim to be faster/better.**

## Credits
Axo language is almost enitrely made by Filip Król. I wouldn't be able to make it so far without some of my best buddies though, here's just some of them:
- [UNSUA design](https://www.instagram.com/unsuadesign/) - for a sick-lookin logo and brand book.
- [People from the Random Soup organization](https://randomsoup.org/) - endless support and feedback regarding everything.

I honestly cannot state how much these people were when it came to this project, so a big round of applause for each single one of you who made it to this small list 🎉