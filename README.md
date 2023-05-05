#   get_next_line

The `get_next_line` project is a programming task that requires you to write a function that reads a line from a file descriptor (fd) and returns it as a string. The aim of the project is to help you improve your skills in file descriptor manipulation and dynamic memory allocation.

## Function Prototype

The function prototype for `get_next_line` is as follows:

`char *get_next_line(int fd)` 

The function takes a file descriptor as a parameter and returns a pointer to a string containing the next line from the file associated with that file descriptor. The function will return `NULL` if there are no more lines to read or an error occurs.

## Compilation

The program will be compiled in the following way:

`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx <files>.c` 

The `BUFFER_SIZE` macro must be defined during compilation, and it specifies the size of the buffer used for reading from the file descriptor. The `xx` will be replaced with the value used for testing purposes.

## Third-party Tester

You can use the [gnlTester](https://github.com/Tripouille/gnlTester) third-party tester to validate the correctness of your `get_next_line` implementation.

This project is a great opportunity to improve C programming skills, particularly in areas such as file descriptor manipulation, dynamic memory allocation, and error handling.
