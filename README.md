# man ft_printf
```sh
NAME
     ft_printf -- formatted output

SYNOPSIS
     ft_printf format [arguments ...]

DESCRIPTION
     The `ft_printf` utility formats and prints its arguments. The `format` is a
     character string which contains two types of objects: plain characters,
     which are simply copied to standard output and character escape sequences
     which are converted and copied to the standard output.
```



Conversions included:
| Specifier | `%c` | `%s` | `%p` | `%d` | `%i` |`%u` | `%x` | `%X` | `%%` |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

 * %c Prints a single character.
 * %s Prints a string (as defined by the common C convention).
 * %p The void * pointer argument has to be printed in hexadecimal format.
 * %d Prints a decimal (base 10) number.
 * %i Prints an integer in base 10.
 * %u Prints an unsigned decimal (base 10) number.
 * %x Prints a number in hexadecimal (base 16) lowercase format.
 * %X Prints a number in hexadecimal (base 16) uppercase format.
 * %% Prints a percent sign.

# Usage

1. At the root of the repository simply run `make` to compile the library.

2. To use the `ft_printf` include the `ft_printf.h` in your `.c` file/files.
```c
/* main.c */
#include "./headers/ft_printf.h"

int main(void)
{
    ft_printf("%s %s!\n", "Hello", "World");
    return (0);
}
```

3. Compile your `.c` file/files with the `libprintf` library.
```text
gcc main.c -L. -lftprintf
./a.out
Hello World!
```

# Testing
Tests use [Unity Test](https://github.com/ThrowTheSwitch/Unity) for `unit testing` and my [malloc_failer](https://github.com/Stte/malloc_failer) which fails mallocs one by one to see if mallocs are properly protected.

To run the tests simply run `make -C ./test` at the root folder. That takes care of building the libraries, running the `unit tests`, making the docker image, starting the docker container and running the `malloc_failer`. 

After that is done you can also run: 
- `make ft_printf -C ./test` to re-run the `unit tests`.
- `make run_failer -C ./test` to re-run the `malloc_failer`.

