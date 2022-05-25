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

void	hex_converter(unsigned long long n)
{
	int	i;

	i = 0;	
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

int	hex_upper_lower(unsigned long long n, const char *s, int j)
{
	int	temp;
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * len_n16(n));
	if (!arr)
		return (0);
	if (n == 0)
		return (write(1, "0", 1));
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			arr[i++] = (temp + '0');
		else if (s[j + 1] == 'X')
			arr[i++] = (temp - 10 + 'A');
		else if (s[j + 1] == 'x')
			arr[i++] = (temp - 10 + 'a');
		n = n / 16;
	}
	//free(arr);
	return (ft_putchar_rev(1, len_n16(n)));
}
