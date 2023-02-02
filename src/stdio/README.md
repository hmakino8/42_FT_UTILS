# ft_printf / ft_dprintf
*A function that will mimic the real printf/dprintf.*

## Program name
`libftprintf.a` `libftdprintf.a`

## Prototype
```C
int ft_printf(const char *format, ...);
int ft_dprintf(int fd, const char *format, ...);
```
## Turn in files
`*.c`, `*/*.c`, `*.h`, `*/*.h`, `Makefile`

## Usage
To compile the library, run:
```sh
$ make
```
Test to confirm operation, run:
```sh
$ ./test
```
## Description
- Write a library that contains ft_printf/ft_dprintf, a function that will mimic the real printf/dprintf.
- It must not do the buﬀer management like the real printf.
- It will manage the following conversions: cspdiuxX%.
- It will manage any combination of the following ﬂags: ’-0.*’ and minimum ﬁeld width with all conversions.

## Return value 
- Upon successful return, these functions return the number of characters printed.
- -1 : If an output error is encountered.

