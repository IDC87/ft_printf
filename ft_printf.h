/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:26:11 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/25 17:55:23 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdarg.h>

//LIBFT Functions

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int	itoa_size(int n);
char	*convertion(char *str, int n, int len, int j);
char	*ft_itoa(int n);


//ft_Printf functions

int		ft_printf(const char *string, ...);
int		get_specifier(va_list arg, const char *string, int i);
int		ft_putchar(char c);
int ft_putchar_num(int n);
size_t	ft_strlen(const char *s);
int		len_n16(unsigned long long n);
int		len_n10(unsigned int n);
int		ft_putchar_rev(unsigned long long n, int len);
int		ft_putstr(char *s);
int    put_hex_p(unsigned long long n);
void		hex_converter(unsigned long long n);
int		hex_upper_lower(unsigned long long n, const char *s, int j);
char	*unsigned_func(unsigned int n);
int		unsigned_func_2(unsigned int n);
//int		main(void);

#endif
