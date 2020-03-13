# Notes
---
## Programming in Unix
- Programs request services from the OS through system calls.
- A __system call__ is a direct entry point into the kernel.
- The __kernel__ is a set of software modules that they perform in privileged way, meaning that they have full control over the system resources.
- C library functions may or may not invoke calls to the system.

## Manual pages
The manual pages cna be consulted with the `man` command.
```sh
man [section] keyword # manual for command keyword
man -k keyword # search for keyword
```

## System calls and C library functions
When using system calls or C library functions, it's useful to check the manpage to know the necessary header files, function prototype, parameters and return value of the function.

## Program compilation
The C compiler (`gcc` or `cc`) translates source programs into C in object modules or in executable modules.

Compiling is done in multiple steps:
- the pre-processor expands macros and includes header files
- compiler goes through the code translating it into assembly of the target machine and after into machine code
- the result is an object module consisting of machine code and unresolved reference tables
- the object module is then linked with other modules in order to create an executable where all the references are resolved

## Program development

#### Header Files
- In order to program in C, we need header files that contain constant definitions and system calls declarations or to the language library.
- Most of these headers are located in `/usr/include` and its subdirectories
- It's possible to specify other directories in which header files can be searched, in addition to the standard directories, using the compilation flag `-I`
    ```sh
    gcc -I/usr/path/to/include -o prog prog.c
    ```
- To search header files containing certain definitions or functions prototypes the `grep` command can be used
    ```sh
    grep _SC_CLK_TCK /usr/include/*.h
    ```

#### Library files
- Library - collection of precompiled functions that have been written to be reusable
- The standard libraries are located in: `/lib` or `/usr/lib` or `/usr/local/lib`
- The name of the libraries always start with `lib`. The rest of the name indicates the type of library
(ex: `libc`, indicates the C library, and `libm`, the mathematical library). The last part of the name indicates the type of library:
  - `.a` - static library
    - if there are multiple programs that use the same library function, then when programs are running "simultaneously" there will be several copies of the function in memory
  - `.so` or `.sa` - shared library
    - the code of the library functions can be shared by several programs
  - In Linux, by omission, the shared libraries are used. To force the use of the static libraries the option `-static` must be included when invoking the C compiler.

## Program Startup
When the OS is asked to execute a new program, it starts by executing a routine called C startup (in the case of C language). This routine:
- fetches the command line arguments from the kernel and environment variables
- opens and makes 3 "files" available to the program (standard input, standard output, standard error)
- invokes the program's `main()` function

## Main Function
Can be defined in multiple forms:
```c
int  -+            +-> (void)
      |            |
      +--> main() -+-> (int argc)
      |            |
void -+            +-> (int argc, char *argv[])
                   |
                   +-> (int argc, char *argv[], char *envp[])
```
- `argc` - number of command line arguments, including the name of the program executed
- `argv` - array of pointers to strings, pointing the parameters passed to the program
- `envp` - array of pointers to strings, pointing out program environment variables

## Terminating a process
- Normal termination:
  - execute `return` in the `main()` function
  - invoke `exit()`
  - invoke `_exit()`
- Abnormal termination:
  - invoke `abort()`
  - when receiving certain signals (untreatable)

### Termination with `exit()`
```c
#include <stdlib.h>
void exit(int status);
```
- Exits the program immediately returning the exit code `status` to the OS.
- Frees all resources assigned to the program and __closes open files__ and transfers data that has not yet ben saved to disk

##### `status`
- Most OS allow testing the exit status of the last process executed
  - ex: `$ echo $?` (in Bourne and Korn `shell`); `$status` in C `shell`
- Usual values:
  - 0 - if no error occurred
  - <> 0 (greater or less) - if an error occurred

### Termination with `_exit()`
```c
#include <stdlib.h>
void _exit(int status);
```
- Exits the program immediately returning the exit code `status` to the OS.
- Frees all resources assigned to the program, quickly
- __Data that has not yet been saved may be lost__

The `status` is undefined if:
- `exit()` or `_exit()` are invoked without specifying `status`
- `main()` returns without specifying the return value
- `main()` reach the end without returning, `exit` or `_exit`

## Function `atexit()`
The function `exit()` can execute, before finishing, a series of routines (*handlers*), previously registered for execution at the end of the program.
- These routines are performed in **reverse** order of registration
- The __registration__ of these handlers is done through the `atexit()` function

```c
       _exit()  +-----------------+    exit()                         +--------------+
    +-----------| other functions |-·-·-·-·+             |+----------→|   atexit()   |
    |           +-----------------+        |             | +----------|   handler    |
    |             ↑        |               ·             | |          +--------------+
    |             |        |               |             | |          +--------------+
    |             |        |               ·             | |  +------→|   atexit()   |
    |           3 |        | 4             |             | |  | +-----|   handler    |
    |             |        | return        ·             | |  | |     +--------------+
    |             |        ↓               ↓             ↑ ↓  ↑ ↓            .
    |   _exit() +------------+          +-------------------------+          .
    |   +-------|   main()   |-·-·-·-·-→|           exit()        |          .
    |   |       +------------+          +-------------------------+
    |   |         ↑        |               ↑          |       ↑ ↓
    |   |       2 |        | 5             |          |       | |  7  +--------------+
    |   |         |        | return        | 6        |       | +----→|   cleanup    |
    |   |         |        ↓               | exit()   |       +-------|              |
    |   |       +-------------+            |          |         8     +--------------+
    |   |       |  C startup  |------------+          |
    |   |       +-------------+                       | 9
    |   |         ↑                                   | _exit()
    |   |       1 | exec()                            |
    ↓   ↓         |                                   ↓
+----------------------------------------------------------------------------------------------+
|                                       Operating System                                       |
+----------------------------------------------------------------------------------------------+
```

## Error handling
- In general, calls to the system return a special value when an error occurs, for example:
  - negative value (often -1)
  - null pointer
- The type of error that occurred is placed in a global variable `errno`, of type `int`
- The value of this variable must be analysed __immediately__ after the call that caused the error
- The file `errno.h` defines:
  - the variable `errno`
  - constants for each value `errno` can assume
  ```c
  #define EPERM     1   /* Not owner */
  #define ENOENT    2   /* No such file or directory */
  #define ESRCH     3   /* No such process */
  ...
  ```

C Library functions, useful when errors occur:
```c
#include <stdio.h>
void perror(const char *msg);
```
- Shows the `msg` string, followed by `:`, followed by a description of the last error that occurred in a system call
- If there is no error to report, it shows the string `Error 0`

```c
#include <string.h>
char *strerror(int errnum);
```
- This function returns a pointer to a string which contains a description of the error whose code was passed in `errnum` argument (which is typically the value of `errno`)

## Measuring execution times
```c
#include <sys/times.h>
clock_t times(struct tms *buf);

/*
Fills the structure whose address is provided in buf
Returns the current system time passed, measured from an arbitrary instant (ex: system startup, the instant depends on the version of the OS)
*/
```
```c
struct tms {
    clock_t tms_utime;  /* CPU time spent on process code */
    clock_t tms_stime;  /* CPU time spent on system code called by the process */
    clock_t tms_cutime; /* CPU time of children (own code) */
    clock_t tms_cstime; /* CPU time of children (system code) */
```
All times are measured in clock ticks.  
The number of ticks per second can be determined using `sysconf()`:
```c
ticks_seg = sysconf(_SC_CLK_TCK);
```
---
## Console, Files and Directories
### Files
File-related system calls allow to manipulate flat files, directories and special files, including:
- files on disk
- terminals
- printers
- facilities for intercommunication between processes, such as pipes and sockets

### File descriptors
- For the kernel all open files are referred to using descriptors
- When creating a file or opening an existing file, the kernel returns a descriptor to the processor that created or opened the file
- This descriptor is one of the arguments of the calls that allow reading or writing to the file
- A descriptor is an integer, non-negative, usually small. Descriptors can take values between `0` and `OPENMAX`
- By convention, Unix shells associate the first 3 descriptors with special files:
  - 0 - standard input
  - 1 - standard output
  - 2 - standard error
- These descriptors are defined in `unistd.h` through constants: `STDIN_FILENO`, `STDOUT_FILENO`, `STDERR_FILENO`

  For example, the `printf()` function always writes using descriptor 1 and the `scanf()` function always reads using the descriptor 0
- When a file is closed, the corresponding descriptor is released and can be reused when a new file is opened
- A file can be opened several times and therefore can have several descriptors associated with it

Each file descriptor has a set of associated properties:
- a file pointer (cursor) indicating the position of the file where the next `read`/`write` operation will be performed
  - set to `0` (zero) when the descriptor is created
  - advances automatically after each `read`/`write` operation
- a flag indicating whether the descriptor should be automatically closed if the process calls one of the `exec()` functions
- a flag that indicates if what is written for the file should be added at the end of the file

There are other properties that only apply to special files, such as pipes and sockets:
- a flag indicating whether a process should block if it tries to read from a file when it is empty
- a number that indicates the identifier of a process or group of processes to which the `SIGIO` signal should be sent if there is data in the file

### Console
- The console (keyboard + screen) is seen by most OS's as one or more files where you can read or write text
- These files are usually opened by the C startup routine
- The standard C library includes several functions for reading and writing directly to these files:
  - `printf()`, `scanf()`, `getchar()`, `putchar()`, ...
- It is also possible to access those peripherals through OS's services
  - Unix doesn't defined special services for reading and writing on the console
  - Generic services for reading and writing files must be used

```c
+----------+                            +------------+
|  Screen  |                            |  Keyboard  |
+----------+                            +------------+
        ↑                                   |
        |                                   |
+-------|-----------------------------------|------------------
|       |                                   ↓                 |
|  +---------------+   if echo active  +--------------+       |
|  | output buffer |←------------------| input buffer |       |
|  +---------------+                   +--------------+       |
|          ↑                                   |              |
|          |          Operating System         |              |
+----------|-----------------------------------|--------------+
           |                                   ↓
        write()                              read()

```

Unix console operating modes:
- canonical mode (cooked):
  - there are a series of special input characters that are processed by the console and are not transmitted to the program you are reading
    - ex: `ctrl-U`, `ctrl-H`, `ctrl-S`, `ctrl-Q`
    - many of these characters are programmatically changeable
  - the entry is only passed to the program when `Return` is pressed
- primary mode (raw):
  - there is no prior processing of the characters entered
  - they are passed one by one to the program

Change of console features in Unix:
```c
#include <termios.h>

int tcgetattr()
```
