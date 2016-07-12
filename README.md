# Birdee
Birdee is a new programming language based on LLVM, aiming to support cross-platform execution. However, now it only runs on Windows and Linux.  This project is originally based on 'diksam'.
To build or browse Birdee's source code, Visual Studio or Code::Blocks are recommended (both of them can be obtained for free by the official).
"/Birdee/Birdee.sln" is the Visual Studio solution file. And "/Birdee/Birdee/Birdee.cbp" and "/Birdee/Birdee/Birdee_linux.cbp" are the Code::Blocks project files. Both kinds of project files can generate Birdee's executable file, but some features (such as multithreading) are only available when Birdee is compiled by MinGW (or GCC on Linux).

## Pre-built binary
See [Wiki](https://github.com/Menooker/Birdee/wiki)

## How to build
See How_to_build_me.md

## How to run
After building Birdee, Birdee can be started by command line (e.g. cmd or bash). The command line arguments are as follows.

### To compile libraries
```bash
 Birdee -l PATH/TO/SOURCE/FILE PATH/TO/OUTPUT/LIB/FILE
```
The argument "-l" makes Birdee compile the source code into a library. If you want to declare some functions which are implemented by the runtime (this situation may occur when you are compiling a "system" library like "Remote.bdl"), you have to use "-ls" argument instead of "-l"

### To compile a source file only
```bash
 Birdee -c PATH/TO/SOURCE/FILE PATH/TO/OUTPUT/EXECUTABLE/FILE
```

### To compile and execute a source file
```bash
 Birdee -e PATH/TO/SOURCE/FILE PATH/TO/OUTPUT/EXECUTABLE/FILE
```

### To run as slave mode
```bash
 Birdee -s LOCAL_PORT_NUMBER PATH/TO/A/DIRECTORY
```
In this mode, Birdee will run as slave mode and wait for the connection from a master node.
LOCAL_PORT_NUMBER is the port number the slave to listen. PATH/TO/A/DIRECTORY is the path to a directory to store the executable files received from the master node

### Extra arguments
There are some more options to choose by appending extra arguments to the arguments above.
#### Extra Arguments available under execution mode ("-e","-s")
 * "-debug"
  Enable MCJIT of LLVM. Makes GDB see you own program's symbols and line numbers. However, this argument also disables multithreading because MCJIT dosen't work well with TLS. 
 * "-nocache"
  Disable distributed memory cache when accessing shared memory. Note that the cache is enabled by default. Moreover, master nodes and slave nodes should use the same cache argument.
 * "-mem BACKEND"
  Select the distributed shared memory backend. Replace "BACKEND" with "memcached" or "cmemcached" in the command. If "memcached" is chosen, the fine-grained memcached backend (one key for one value/variable in Birdee) is selected. If "cmemcached" is chosen, the coarse-grained memcached backend (one key for multiple value/variable in Birdee, fast in chunk operation) is selected. "cmemcached" is the default selection.
 * "-opt N"
  Select the optimization level. N is in [0,3], corresponds to -O0 to -O3 of GCC.

#### Extra Arguments available under compilation mode ("-e","-c","-l","-ls")
 * "-disasm"
  Print the disasembly of LLVM IR to stderr after compilation
 * "-asm2file PATH/TO/OUTPUT/FILE"
  Output the disasembly of LLVM IR to PATH/TO/OUTPUT/FILE
