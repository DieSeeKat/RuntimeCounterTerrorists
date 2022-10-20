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
## Google Test
### Installing g++ (MSYS2 MinGW)
1)  Navigate to https://www.msys2.org/ and download the installer
2)  Open MinGW64 terminal and run the following commands. (Type yes/y for all prompts)
    - pacman -Syu
    - pacman -Su
    - `pacman -S mingw-w64-x86_64-gcc`

      32-Bit:
      - `pacman -S mingw-w64-i686-gcc`
    - `pacman -S mingw-w64-x86_64-gdb`
      
      32-Bit:
      - `pacman -S mingw-w64-i686-gdb`
3) Add MinGW64 bin folder to path. If the default installation values were used, it should be located at 
    > `C:\msys64\mingw64\bin`
    
        Change as needed with different install locations or if 32-bit installation 
        was used.
---
### Installing Bazel:
    1) Using choco (Installed with nodejs by default)
        - Open cmd as administrator
        - Run `choco install bazel`
        - When prompted, enter `a` for 'yes to all' 
    2) Using npm (untested)
        - Run npm install -g bazel
---
### Setting up build environment:
    Download bazel files needed from 
    > https://drive.google.com/file/d/1JE14Qsq-5ExL5Cbw_WdedO1KjBWxJeNS/view?usp=sharing

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
  
  Navigate to the directory that contains the WORKSPACE and BUILD files
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