# ft_printf

*This project has been created as part of the 42 curriculum by fiolivei*

## Description

ft_printf is a custom implementation of the C standard library `printf()` function. The goal is to understand variadic functions in C and reproduce the core formatting behaviour of `printf()` without relying on the original.

The function handles a format string with conversion specifiers and a variable number of arguments, printing the result to standard output and returning the total number of characters written.

## Instructions

```bash
make        # build libftprintf.a
make clean  # remove object files
make fclean # remove object files and libftprintf.a
make re     # fclean + all
```

To use the library in another project, include the header and link the archive:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

### Supported conversions

| Specifier | Description | Done |
|---|---|:---:|
| `%c` | Prints a single character | ❌ |
| `%s` | Prints a string | ❌ |
| `%p` | Prints a pointer address in hexadecimal | ❌ |
| `%d` | Prints a decimal (base 10) integer | ❌ |
| `%i` | Prints an integer in base 10 | ❌ |
| `%u` | Prints an unsigned decimal (base 10) integer | ❌ |
| `%x` | Prints a number in hexadecimal lowercase | ❌ |
| `%X` | Prints a number in hexadecimal uppercase | ❌ |
| `%%` | Prints a literal percent sign | ❌ |

## Resources

- [The C Programming Language — Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [man3 — printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [man3 — stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [cppreference.com — Variadic functions](https://en.cppreference.com/w/c/variadic)
- [Claude](https://claude.ai) and [ChatGPT](https://chatgpt.com) were used to generate tests, this readme and eventually explain concepts and assist with debugging.
