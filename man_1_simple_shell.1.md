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

# EXIT STATUS

# APLICATION USAGE
