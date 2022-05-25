/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:20:16 by marvin            #+#    #+#             */
/*   Updated: 2022/05/17 17:55:15 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_converter(unsigned long long n)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (n == 0)
		return (write(1, "0", 1));	
	if (n >= 16)
	{
		hex_converter(n / 16);
		hex_converter(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	ret = ret + len_n16(n);
	return (ret);
}

int	hex_converter_lower(unsigned int n)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (n == 0)
		return (write(1, "0", 1));	
	if (n >= 16)
	{
		hex_converter(n / 16);
		hex_converter(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	ret = ret + len_n16(n);
	return (ret);
}

int	hex_converter_upper(unsigned int n)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (n == 0)
		return (write(1, "0", 1));	
	if (n >= 16)
	{
		hex_converter_upper(n / 16);
		hex_converter_upper(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'A');
	}
	ret = ret + len_n16(n);
	return (ret);
}

int put_hex_p(unsigned long long n)
{
	int ret;

	ret = 0;
	ret = ret + write(1, "0x", 2);
	if (n == 0)
		ret = ret + (write(1, "0", 1));
	else
	{
		hex_converter(n);
		ret = ret + len_n16(n);
	}
	return (ret);

}
