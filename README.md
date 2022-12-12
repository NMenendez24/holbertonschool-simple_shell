# holbertonschool-simple_shell
This repo contains the shell proyect for Holberton School

>Index

- [Objective](#objective)
- [Description](#description)
- [Flowchart](#flowchart)

## Objective

Recreate a simple shell. That a command interpreter is an interface between the user and GNU/Linux, UNIX. That provides us with an environment that allows us to introduce commands into the system and for it to recognize them.

### Learning Objetive

<li>How does a shell work?

It is a program that is used to enter commands typed by a user into the terminal and translates them as a set of instructions so that they can be understood by the operating system. It manages the interaction between the user and the operating system by requesting input from the user, interpreting that input for the operating system, and handling any output from the operating system.
<li>What is a pid and a ppid?

All processes have a PID attribute, which is the process number that identifies it in the system, there is also an attribute called PPID. This number corresponds to the PID number of the parent process.
<li>How to manipulate the environment of the current process?

Some of the system calls that allow us to manipulate processes are:
<b>fork</b> Creates a new process. <b>exec</b> Allows a process to execute a new program. <b>wait</b> Allows a parent process to synchronize its execution with the exit call of a process son. <b>exit</b> Terminates the execution of a process.
<li>What is the difference between a function and a system call?

Unlike library functions in a programming language, system calls are specific to the operating system. a system call is used as a library function. However, its execution implies the invocation of an operating system service. System calls are one of several ways to extend the functions provided by the kernel.
<li>How to create processes?

To create a new process, the fork system call is used. This call causes the process to
The execution is divided into two processes. The process that executes the branch is known as the parent process and the
The newly created process is called a child process.
After executing this system call, the two processes will have identical copies of their user-level context. the
The only difference will be that the integer value returned by the branch for the parent process is the PID of the child process, whereas
which for the child process is 0.
<li>How does the shell use the PATH to find the programs?

On Linux, Path is an environment variable that tells the shell and other programs which directories to look in for executable files. It consists of a colon-separated list of absolute paths to the directories containing the executables. Commands passed to the shell are looked up and compared to those in the path to execute them.
<li>How to execute another program with the execve system call?

execve(name, argv, envp);

where name is a pointer to the name of the file to be executed, argv is a pointer to an array of pointers, each pointing to an argument, and envp is a pointer to an array of pointers, each pointing to an environment string.
<li>How to suspend the execution of a process until one of its children terminates?

wait(status);

The wait system call waits for a process to finish. Normally, it is executed by a parent process to wait for
for a child process to terminate its execution.
Upon execution, it returns the PID of the child process in question and sets the provided exit status to state.
for this one. Returns –1 if there is no child process of the calling process. We can say that the function
wait() is used for synchronization of the two processes (parent and child) that are running concurrently.
<li>What is EOF / “end-of-file”?

It is an integer type constant that is the return sent by different functions for extracting information from files when reaching the end of the file and there is no more data. It is an indicator or flag that there is no more information to retrieve from a data source.

### General Requirements

<li>Allowed editors: vi, vim, emacs
<li>All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
<li>All your files should end with a new line
<li>Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
<li>Your shell should not have any memory leaks
<li>No more than 5 functions per file
<li>All your header files should be include guarded
<li>Use system calls only when you need to


## Description

A shell interface gives the user a prompt, in this case we established a "$ ", after which the command is entered. Everything that the user types after the command is called an "argument". After search for it in the PATH environmental variable for a directory that contains an executable file by that name.

### Description File 

<b>shell.h</b> - libraries and function prototypes.

<b>simple_shell.c</b> - the main function: command interpreter.

<b>function.c</b> - _getenv function: gets a environmental variable, _getcommand function: search for the path of a command, _argcounter: counts arguments, _printenv function: prints the environment.

<b>string_function.c</b> - _strcat function: concatenate the string,  _strlen function: the length of a string,  _strcpy function: copy a string,  _strcmp function: compares two string,  _strdup function: duplicate a string.

<b>string_function2.c</b> - _puts function: prints a string, _putchar function: write a character in stdout, _putsnl function: prints a string with a new line at the end

<b>man_simple_shell</b> - man page of the simple_shell

<b>AUTHORS</b> - contributors to the repository


## Flowchart
![Flowchart](https://i.imgur.com/m3siVWr.png)
