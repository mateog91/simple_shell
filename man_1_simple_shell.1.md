% HSH(1P) IEEE/The Open Group "POSIX Programmer's Manual"
% Juan Sebastian Gonzalez - Mateo Garcia
% 2021

# PROLOGUE
This shell is small copy of sh.\
This manual page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or the interface may not be implemented on Linux.

# NAME
hsh - a simple command interpreter (shell)

# SYNOPSIS
Interactive mode
hsh [*argument* ...]

not interactive - reads commands from a file or script
hsh [*command_file* [*argument* ... ]]

# DESCRIPTION
The hsh utility is a command language interpreter that shall execute commands read from a command line string, the standard input, or a specified file. The application shall ensure that the commands to be executed are expressed in the language described in Chapter 2, Shell Command Language.\
Display a prompt and wait for the user to type a command. A command line always ends with a new line.\
The prompt is displayed again each time a command has been executed.\
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.\
Handle commands with arguments.

It does not:

 * Handle special characters : ", ', `,\\, *, &, \#
 * Be able to move the cursor

# OPTIONS
This shell does not handle any of the options of sh (--a, -b, -C, -e, -f, -m, -n, -o).

# ENVIRONMENT VARIABLES
The following environment variables shall affect the execution of *sh*:

*ENV*
: This variable, when and only when an interactive shell is invoked, shall be subjected to parameter expansion (see Section 2.6.2, Parameter Expansion) by the shell and the resulting value shall be used as a pathname of a file containing shell commands to execute in the current environment.  The file need not be executable. If the expanded value of ENV is not an absolute pathname, the results are unspecified.  ENV shall be ignored if the real and effective user IDs or real and effective group IDs of the process are different.

*PATH*
: Establish a string formatted as described in the Base. Definitions volume of POSIX.1‐2017, Chapter 8, Environment Variables, used to effect command interpretation; see Section 2.9.1.1, Command Search and Execution.

# EXIT STATUS

The following exit values shall be returned:

0
: The script to be executed consisted solely of zero or more blank lines or comments, or both.

1-125
: A non-interactive shell detected an error other than
               command_file not found or executable, including but not
               limited to syntax, redirection, or variable assignment
               errors.

126
: A specified command_file could not be executed due to an
               [ENOEXEC] error (see Section 2.9.1.1, Command Search and
               Execution, item 2).

127
: A specified command_file could not be found by a non-
               interactive shell.

Otherwise, the shell shall return the exit status of the last
       command it invoked or attempted to invoke

# APLICATION USAGE

Standard input and standard error are the files that determine
              whether a shell is interactive mode.
	      
Interactive mode:
: While having executed this simple shell, type directly into the command line and press enter.

: ls -la

Non Interactive mode:
: While outside of this shell, make a command or file and pipe it into the standard input.

: echo ls -la | ./hsh


# EXAMPLES

The shell can also be called from a script this way:

echo "./example" | ./hsh

where example is:\
		#!/bin/bash\
		echo ejemplo

This will print into the standard output: "ejemplo"

# SEE ALSO
For any aditional information please refer to the manual of **sh**

# COPYRIGHT
This is a free manual, there are no copyrights for this manual
