#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include   <unistd.h>
# include   <stdlib.h>
#include    <stdarg.h>
# include   <stdio.h>

int    ft_printf(const char *, ...);
int     ft_putchar(char c);
size_t	ft_strlen(const char *s);
int len_n16(unsigned long long n);
int len_n10(unsigned int n);
int ft_putchar_rev(int *arr, int len);
int ft_putstr(const char *s);
int hex_converter(unsigned long long n);
int hex_Upper_lower(unsigned long long n, const char *s, int j);


#endif