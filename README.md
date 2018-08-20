Integer Multifind

Objective:
This project aims to create a program that uses multiple threads to find an integer value in several (݊ n ≥ 1) files with integer values in different quantities.
All this operation - reading the files and location of the value - should occur using 2, 4, 8 or 16 threads, at the discretion of the user. The program must be written to the Linux operating system and must use the POSIX Threads library.

Contributors:
* [Andrey Okamura](https://github.com/okamuratoshi)
* [Gustavo Polli](https://github.com/gapolli)
* [Mateus Santos](https://github.com/mateuspim)

Compilation:
At the Terminal or other Shell interpreter, type the following
```
make
```
Obs.: After the compilation is successful, clean the garbage with the following command
```
make clean
```

Usage:
At the Terminal or other Shell interpreter, type the following
```
./multifind 16 123 arq1.in arq2.in arq3.in
```
where
* 16 is the number of threads to be created in the execution;
* 123 is the integer to find;
* arq1.in, arq2.in and arq3.in are the text files to be explored.
