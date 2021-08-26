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
## Flowchart
![alt text](https://lucid.app/publicSegments/view/9debc2df-0aa7-4f1e-8746-9888b176693e/image.jpeg)

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
```bash
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
For a non interactive use, meaning, using the simple shell from the outside and pipeline to the standard input, it can be used this way:
```bash
echo ls -lhta | ./hsh
total 196K
drwxrwxr-x  3 vagrant vagrant 4.0K Aug 26 20:46 .
-rwxrwxr-x  1 vagrant vagrant  23K Aug 26 20:46 hsh
-rw-r--r--  1 vagrant vagrant  12K Aug 26 19:21 .function_others.c.swp
-rw-r--r--  1 vagrant vagrant  16K Aug 26 19:11 .functions_main.c.swp
-rw-r--r--  1 vagrant vagrant  12K Aug 26 19:11 .shell.c.swp
drwxrwxr-x  8 vagrant vagrant 4.0K Aug 26 19:09 .git
-rw-rw-r--  1 vagrant vagrant 4.1K Aug 26 19:09 README.md
-rw-rw-r--  1 vagrant vagrant 1.6K Aug 26 19:09 shell.c
-rw-rw-r--  1 vagrant vagrant 2.5K Aug 26 19:09 shell.h
drwxr-xr-x 19 vagrant vagrant 4.0K Aug 26 19:09 ..
-rw-rw-r--  1 vagrant vagrant 1.7K Aug 26 05:32 functions_memory.c
-rw-rw-r--  1 vagrant vagrant 1.4K Aug 26 04:49 function_others.c
-rw-rw-r--  1 vagrant vagrant 1014 Aug 26 04:49 function_strtok.c
-rw-rw-r--  1 vagrant vagrant 5.1K Aug 26 04:12 functions_main.c
-rw-rw-r--  1 vagrant vagrant  556 Aug 26 03:35 functions_print_errors.c
-rw-rw-r--  1 vagrant vagrant 4.0K Aug 26 02:18 man_1_simple_shell.1
-rw-rw-r--  1 vagrant vagrant 3.7K Aug 26 02:10 man_1_simple_shell.1.md
-rwxr-xr-x  1 vagrant vagrant   25 Aug 26 01:47 example
-rwxrwxr-x  1 vagrant vagrant  23K Aug 25 15:00 a.out
-rw-rw-r--  1 vagrant vagrant  759 Aug 25 14:59 executable_function.c
-rw-rw-r--  1 vagrant vagrant 1.4K Aug 25 14:57 builtin.c
-rw-rw-r--  1 vagrant vagrant  937 Aug 25 06:19 functions_print.c
-rwxr-xr-x  1 vagrant vagrant 1.9K Aug 25 04:49 pruebas.sh
-rw-rw-r--  1 vagrant vagrant 1.2K Aug 25 02:59 find_command_path.c
-rw-rw-r--  1 vagrant vagrant  498 Aug 25 02:59 functions_strings_basic.c
-rw-rw-r--  1 vagrant vagrant 2.1K Aug 25 02:59 functions_strings_malloc.c
-rw-rw-r--  1 vagrant vagrant  726 Aug 25 02:59 handling_env.c
-rw-rw-r--  1 vagrant vagrant  696 Aug 25 02:59 handling_path.c
-rw-rw-r--  1 vagrant vagrant   73 Aug 16 13:57 AUTHORS
-rw-rw-r--  1 vagrant vagrant    3 Aug 15 23:04 .gitignore
```
An example when a function is not found would look like this:
```bash
vagrant@ubuntu-focal:~/simple_shell$ shell
$ hello world
./hsh: 1: hello: not found
$ 
```
From the not interactive:
```
vagrant@ubuntu-focal:~/simple_shell$ echo "hello world" | ./hsh
./hsh: 1: hello: not found
```

## Bugs:
The exit values are not the same as the *sh* shell that this simple shell emulates. It is in current progress to fix.


## Authors
Mateo Garcia  |  [GitHub](https://github.com/mateog91)

Sebastian Gonzalez |  [GitHub](https://github.com/JuanSebastianGB)
