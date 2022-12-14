# RuntimeCounterTerrorists

Welcome to the RuntimeCounterTerrorist COS214 Project

## Documentation
[Doxygen](https://dieseekat.github.io/RuntimeCounterTerrorists/index.html) 

[Google Docs](https://docs.google.com/document/d/1wPQdChdRe8x6-FHxGxEzU2a7WrWWuFxytirYL5Gymdk/edit#heading=h.m2bytxe04zha)

[PDF version of Report](https://drive.google.com/file/d/1YzSl-5KMsMeS_QWuaO-gZSi4vK_21L02/view?usp=share_link)

## Video
[Open on Google Drive](https://drive.google.com/file/d/1_sU0letCtILbBXaK2ELVYmQi0-52LZpk/view?usp=share_link)
## UML

![UML](https://user-images.githubusercontent.com/88578565/200355479-e56f8c21-8679-4320-a036-1853f0fbe2b2.jpg)

## The makefile is available [here](https://drive.google.com/file/d/13ipaSk31NMd2V_mTd47VwDohCPgRUSqA/view?usp=share_link) Please use bazel if possible.

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
