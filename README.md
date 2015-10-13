# Birdee
Birdee is a new programming language based on LLVM, aiming to support cross-platform execution. However, now it only runs on Windows.  This project is originally based on 'diksam'.
To build or browse Birdee's source code, Visual Studio or Code::Blocks are recommended (both of them can be obtained for free by the official).
"/Birdee/Birdee.sln" is the Visual Studio solution file. And "/Birdee/Birdee/Birdee.cbp" is the Code::Blocks project file. Both project files can generate Birdee's executable file, but some features are only available when Birdee is compiled by MinGW (or GCC).

# How to compile
Birdee can be compiled by two different IDEs, while both ways differs slightly.

## Build Birdee in Visual Studio
You should first fetch and compile LLVM (version 3.4.2). Here is a tutorial to compile a static LLVM library which is needed by Birdee. 
[a tutorial for compiling LLVM into a  static lib(Chinese)](http://blog.csdn.net/myjisgreat/article/details/46486723)
There are still some more things to do after you get the static library "libLLVMLite.lib".
 * Link/Copy the directory "llvm-3.4.2.src/include" to the same directory holding the root directory of the source code of Birdee. (For example, if the Birdee source code is in directory 'Birdee-src', and the parent directory of 'Birdee-src' is 'codes', then put the 'include' directory into 'codes')
 * After using cmake to configure the LLVM source code, you will get a VisualStudio Project directory. Link/Copy the directory "include" in the project directory to the same diectory above, re-naming as 'include2'.
 * Link/Copy the static library "libLLVMLite.lib" to the to the same diectory above.
Then open the Visual Studio solution file "/Birdee/Birdee.sln". Now you should be able to compile and run Birdee with Visual Studio!