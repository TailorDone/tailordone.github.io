//
//  main.cpp
//  Libraries
//
//  Created by Taylor Dunn on 9/21/20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // Libraries contain classes, structs, and functions that solve a particular problem
    // SFML
    // What's in a library? Header files. You might get cpp files. They can give the compiled cpp. (compile to .o and then link to make a library)
    // 3 types of libraries :
    // 1) Header only #include ....
    // 2) Source Libraries. Headers and source code (cpp). Small libraries. Copy the files to your project.
    // 3) Compiled libs, headers and "compiled library". on macOS this has a .a or .dylib (windows .lib, .dll, linux .so)
    // Build systems help us work with libraries. Program that calls the compiler and the linker on the files with the appropriate command line flags
    // "Make" provide a "makefile" which describes your project (source files, libraries, paths to where things live, compiler options)
    // CMake tool for making Makefiles. and xcodeprojects, visual studio projects, etc.
    // Package manager. We want to use SFML works with images and audio. SFML will use libpng, libjpeg, libvorbiz, libflac
    // We are going to use homebrew
    // Install libs I need with PM. Create build system project file. Write/run code.
    //Installing $ brew
    // brew search jpeg -> shows brew packages related to jpeg
    // brew update && brew upgrade && brew cleanup
    return 0;
}
