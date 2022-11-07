# RuntimeCounterTerrorists

Welcome to the RuntimeCounterTerrorist COS214 Project

## Style Guide

### Naming
- Variables & Parameters - Snake Case (snake_case)
- Functions - Lower Camel Case (lowerCamelCase)
- Classes - Upper Camel Case (UpperCamelCase)
- Constant Variables - Upper Case (UPPER_CASE)

Be descriptive when naming (E.g. instead of int x for a counter, rather have int student_counter)

### Classes
- Each class MUST have a .cpp and .h file (Pure virtual classes excluded)
- Each class must be encapsulated by an IFNDEF, DEF, ENDIF clause.
- Do not rely on transitive includes. Always include all external classes needed in the class where the externals are used.
- When possible, always destruct right after an object's last usage.

### Formatting
Braces, both open and close, go on their own lines (no "cuddled braces"). E.g.:
```
if (true)
{
  //Whatever
}
else 
{
  //Whatever
}
```
# First (and recommended) installation method (Debian-based systems)
Run the following script in order to do the setup for you. This will create all the files needed and install bazel for you. 

<b>Note:</b>  This script does a `sudo apt ** -y` to update all existing and install needed packages. If you don't want this to happen, don't run the script. Read through it first and modify as you see fit.

1) [Download the script from here](https://drive.google.com/file/d/1v0OU8vYQ9wNdssaHUvtPRzT3D3kuLXCe/view?usp=share_link)
2) run `chmod +x setup.sh`
3) run `./setup.sh`
4) `cd RuntimeCounterTerrorists`
5) The project has been set up for you. You can now run the following commands
  - To run the main program: `bazel run main //:main`
  - To run the tests: `bazel test //...`
  - To run a specific test: `bazel test //:system-test` where system-test can be replaced with any other tests you want to run.

# Windows. This has been tested, but is much more unpredictable and difficult to troubleshoot. Use Debian

## Installing g++ (MSYS2 MinGW)
1)  Navigate to https://www.msys2.org/ and download the installer
2)  Open MinGW64 terminal and run the following commands. (Type yes/y for all prompts)
    - `pacman -Syu`
    - `pacman -Su`
    ### 64-Bit 
    - `pacman -S mingw-w64-x86_64-gcc`
    - `pacman -S mingw-w64-x86_64-gdb`
        
    ### 32-Bit (Only if you have a 32-Bit machine)
    - `pacman -S mingw-w64-i686-gcc`
    - `pacman -S mingw-w64-i686-gdb`

3) Add MinGW64 bin folder to path. If the default installation values were used, it should be located at 
    > `C:\msys64\mingw64\bin`
    
        Change as needed with different install locations or if 32-bit installation 
        was used.
---
## Installing Bazel:
  1) Using choco (Can be installed using the NodeJS installer, remember to select optional tools)
        - Open cmd as administrator
        - Run `choco install bazel`
        - When prompted, enter `a` for 'yes to all' 
  2) Using npm (untested)
        - Run npm install -g bazel

## Visual C++ Build Tools 2019
  - Install Visual C++ Built Tools 2019 using [this](https://aka.ms/vs/16/release/vs_buildtools.exe)
  - Select `Desktop Development With C++`
    
    Note: If you get errors when running bazel on the command-line, set the following environment-variable:

        BAZEL_VC
    
        The value of this variable should be set to the location of the VC folder where your Visual C++ Build Tools 2019 was installed. By default this should be 

        C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC

## Important
     Bazel doesn't support spaces in the file path to your project at the time of writing this.
     Place your project in a directory without any spaces.
---
## Setting up build environment:
  Download bazel files needed from [here](https://drive.google.com/file/d/1JE14Qsq-5ExL5Cbw_WdedO1KjBWxJeNS/view?usp=sharing)

  Ensure that your project has the following folder-structure:
  
      - src
          - Alliance
          - Barracks
          - Command
          - Graph
          - . . . 
      - .bazelversion
      - BUILD
      - WORKSPACE
---
### Using bazel
    - Ensure that your copy of the project is up to date with the master-branch
  
  _Navigate to the directory that contains the WORKSPACE and BUILD files or the src folder_
  #### Building:
  -  `bazel build //:main`
  ### Testing:
  - `bazel test //...` (runs all tests in project)
---
## Writing you own tests
```
#include "gtest/gtest.h"

TEST(TestName, TestDescription) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}
```

For further documentation, refer to:
> http://google.github.io/googletest/primer.html
