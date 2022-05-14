/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:26:11 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/14 13:39:07 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdarg.h>
# include	<stdio.h>

int		ft_printf(const char *string, ...);
int	    get_specifier(va_list arg, const char *string, int i);
int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		len_n16(unsigned long long n);
int		len_n10(unsigned int n);
int		ft_putchar_rev(int *arr, int len);
int		ft_putstr(const char *s);
int		hex_converter(unsigned long long n);
int		hex_upper_lower(unsigned long long n, const char *s, int j);
char	*unsigned_func(unsigned int n);
int     unsigned_func_2(unsigned int n);
int main();


#endif
