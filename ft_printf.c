/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/17 17:38:27 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_func(unsigned int n)
{
	char	*num;
	int		len;

	len = len_n10(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	unsigned_func_2(unsigned int n)
{
	char	*num;
	int		out_len;

	out_len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		num = unsigned_func(n);
		out_len = out_len + ft_putstr(num);
	}
	return (out_len);
}

int	get_specifier(va_list arg, const char *string, int i)
{
	if (string[i + 1] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if ((string[i + 1] == 'd') || (string[i + 1] == 'i'))
		return (ft_putchar(va_arg(arg, int)));
	else if (string[i + 1] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (string[i + 1] == 'p')
		return (hex_converter(va_arg(arg, unsigned long long)));
	else if (string[i + 1] == 'u')
		return (unsigned_func_2(va_arg(arg, unsigned int)));
	else if (string[i + 1] == 'x')
		return (hex_upper_lower(va_arg(arg, unsigned long long), string, i));
	else if (string[i + 1] == 'X')
		return (hex_upper_lower(va_arg(arg, unsigned long long), string, i));
	else if (string[i + 1] == '%')
		return (ft_putchar(string[i + 1]));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(arg, string);
	while (string[i])
	{
		if ((string[i] == '%') && (ft_strchr("cspdiuxX%", string[i + 1])))
		{
			ret = ret + get_specifier(arg, string, i);
			i++;
		}
		else
			ret = ret + write(1, &string[i], 1);
		i++;
	}
	va_end(arg);
	return (ret);
}
