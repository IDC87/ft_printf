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
	int	temp;
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * len_n16(n));
	if (!arr)
		return (0);
	if (n == 0)
		return (write(1, "0", 1));
	write(1, "0x", 2);
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			arr[i++] = (temp + '0');
		else
			arr[i++] = (temp - 10 + 'a');
		n = n / 16;
	}
	free(arr);
	return (ft_putchar_rev(arr, len_n16(n)));
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
	free(arr);
	return (ft_putchar_rev(arr, len_n16(n)));
}
