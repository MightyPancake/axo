# Getting started
In this section, you'll learn how to correctly install axo whether you're a total beginner and have never even touched programming or you already use arch 😉

If at any point you feel lost, remember you can always reach out for some help!

If you consider yourself an expert, please [skip to this part of the page](starting?id=the-diy-road).

Otherwise, continue with the next section.

## Installing from a release
Head over to the release page of axo and pick the version you wish to have installed. If you can't decide. just go with the latest. Then after the download finishes, you have to unpack the downloaded archive somewhere on your drive using a tool like winRAR or 7zip.
You'll then need to set up the environmental variable called PATH. It essentially tells your computer where to look for programs by their name. You need to add the extracted directory path (it should have a program named `axo` or `axo.exe` depending on your system in it) to the PATH variable.
Once you've done that, you should be good to go! [Click here to learn what to do next](starting?id=it-lives).

## The DIY road
This is easier if you're already somewhat acquainted with the use of a terminal. To build axo you'll need the following programs:
- [git](https://git-scm.com/)
- [make](https://www.gnu.org/software/make/)
- [bison](https://www.gnu.org/software/bison/)
- [flex](https://ftp.gnu.org/old-gnu/Manuals/flex-2.5.4/html_mono/flex.html)
- a C compiler ([gcc](https://gcc.gnu.org/), [clang](https://clang.llvm.org/) etc.)

**Please make sure you have them before proceeding!**

To build the project just use `make`:
```terminal
>|info| make build
|Generating lexer...
|Generating parser...
|Building the compiler... 
|success|Compiler built!
```
Your terminal should mostly match this (blue lines are your inputted commands).
If that's what you see; congratulations, you made it!


# IT LIVES

To check if your axo installation worked correctly. Open the upper-mentioned directory in your favorite terminal and try:
```terminal
>|info|./axo info
|>ᑢᑔ<  v.0.0.0
|cc: gcc
|keep_c: true
|timer: true
|color_support: limited
|ascii_only: false
>|
```

That's the information about your current axo configuration, you can learn how to change it here.

You're very close to using axo! The last useful thing that comes in really handy is making sure our computer can see the compiler by adding the directory we're currently in!
Here's how to do it on [Windows](https://learn.microsoft.com/en-us/previous-versions/office/developer/sharepoint-2010/ee537574(v=office.14)), [MacOS](https://pimylifeup.com/macos-path-environment-variable/) and [Linux](https://www.baeldung.com/linux/path-variable).

After that's out of the way, go ahead and test if you can call `axo` from outside of its directory. If you can, you're all set and ready to go!

Click here to go to the next article and start writing your first lines of axo code!

