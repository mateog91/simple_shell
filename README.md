# simple_shell  🐚

## Menu 📝

- Description
- Installation requirements
- How to install
- Features
- Built-ins
- Example of use
- Authors

## Description  👁️‍🗨️

**Simple shell** is a simple command line interpreter that has the ability to read commands from standard input and perform the corresponding execution.
This simple_shell is a simplified version of sh an implement standard functions and system calls like : `execve, exit, fork, getline, malloc, perror, stat, wait, write.`

## Installation requirements 📥

For this program to run, we suggest you use it in **Ubuntu 20.04.2 LTS (Focal Fossa)** version linux enviroment, and for compiling, use **gcc 9.3.0 version** with the following command to take all .c files inside the dir:

```gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh```

## How to install 💻
-   Inside a system like was required before,  clone the repository typing:  ``git clone https://github.com/mateog91/simple_shell.git``
-  move to directory simple_shell.
-   Compile.
-   Run the shell either in interactive mode using  `./hsh` or in not interactive mode using as follow ``echo "ls -lhta" | ./hsh ``

## Features 🔧

This simple_shell is designed to run commands like sh, but it doesn't have the same functionalities. below is a list of the implementations it has.

- ✅ use the  `PATH`
- ✅ implement built-ins
- ✅ handle commands with arguments
- ✅ Implement the  `exit`  built-in, that exits the shell
- ✅ Implement the  `env`  **built-in**, that prints the current environment
- ✅ Handle `Ctrl+C` signal
- 🔲 Implement new_getline function
- 🔲 Implement new_strtok function
- 🔲 Implement the `setenv` and `unsetenv` builtin commands
- 🔲 Implement the builtin command `cd`
- 🔲 Handle the commands separator  `;`
- 🔲 Handle the  `&&`  and  `||`  shell logical operators
- 🔲 Implement the  `alias`  builtin command
- 🔲 Handle variables replacement
- 🔲 Handle the  `$?`  variable
- 🔲 Handle the  `$$`  variable
- 🔲 Handle comments (`#`)
- 🔲 Implement the  `help`  built-in.
- 🔲 Implement the history built-in, without any argument


## Built-ins 🏢

- ✅ `exit`
- ✅ `env`
- 🔲 `setenv`
- 🔲 `unsetenv`
- 🔲 `cd`
- 🔲 `help`
- 🔲 `history`


## Example of use
```
vagrant@ubuntu-focal:~/holberton/simple_shell$ alias shell='gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh'
vagrant@ubuntu-focal:~/holberton/simple_shell$ shell
$ ls -lhta
total 108K
-rwxrwxr-x  1 vagrant vagrant  23K Aug 23 01:52 hsh
drwxrwxr-x  4 vagrant vagrant 4.0K Aug 23 01:52 .
drwxrwxr-x  8 vagrant vagrant 4.0K Aug 23 01:48 .git
drwxrwxr-x  2 vagrant vagrant 4.0K Aug 23 01:47 images
-rw-rw-r--  1 vagrant vagrant 3.4K Aug 22 23:29 shell.c
-rw-rw-r--  1 vagrant vagrant 2.2K Aug 22 01:22 shell.h
-rw-rw-r--  1 vagrant vagrant  280 Aug 22 01:10 functions_print_errors.c
-rw-rw-r--  1 vagrant vagrant  796 Aug 22 00:19 executable_function.c
-rw-rw-r--  1 vagrant vagrant 1.1K Aug 21 23:54 builtin.c
-rw-rw-r--  1 vagrant vagrant 1006 Aug 21 22:10 functions_print.c
-rw-rw-r--  1 vagrant vagrant  498 Aug 21 22:01 functions_strings_basic.c
-rw-rw-r--  1 vagrant vagrant 1.7K Aug 21 18:10 functions_memory.c
-rw-rw-r--  1 vagrant vagrant 1.4K Aug 21 17:35 functions_main.c
-rw-rw-r--  1 vagrant vagrant 2.1K Aug 21 17:20 functions_strings_malloc.c
-rw-rw-r--  1 vagrant vagrant  726 Aug 21 03:29 handling_env.c
drwxrwxr-x 12 vagrant vagrant 4.0K Aug 21 02:34 ..
-rw-rw-r--  1 vagrant vagrant 1.2K Aug 20 01:56 find_command_path.c
-rw-rw-r--  1 vagrant vagrant  696 Aug 20 01:53 handling_path.c
-rwxrwxrwx  1 vagrant vagrant  119 Aug 16 13:26 generate-authors.sh
-rw-rw-r--  1 vagrant vagrant   73 Aug 16 13:25 AUTHORS
-rw-rw-r--  1 vagrant vagrant    3 Aug 15 23:10 .gitignore
-rw-rw-r--  1 vagrant vagrant    7 Aug 15 15:27 README.md
$ exit
vagrant@ubuntu-focal:~/holberton/simple_shell$
```
## Authors

Mateo Garcia  |  [GitHub](https://github.com/mateog91)

Sebastian Gonzalez |  [GitHub](https://github.com/JuanSebastianGB)
