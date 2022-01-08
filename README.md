# get_next_line - @42AbuDhabi

[![42Project Score](https://badge42.herokuapp.com/api/project/kpoquita/get_next_line)](https://github.com/JaeSeoKim/badge42)

The project aims you to code a function that will return a **line** read from a **file descriptor**.

## Function Prototype

```c
char		*get_next_line(int	fd)
```

The program will be compiled in this way:
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx <files>.c
```
Your read must use the BUFFER_SIZE defined during compilation to read from
a file or from stdin. The **xx** will be modified for testing purposes.

## Third-party Tester

[Tripouille](https://github.com/Tripouille/gnlTester)