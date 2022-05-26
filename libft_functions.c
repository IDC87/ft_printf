/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:52:26 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/26 15:21:18 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	str = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	itoa_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	n = -n;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*convertion(char *str, int n, int len, int j)
{
	int	z;

	z = 0;
	while (len-- != j)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{	
	int		len;
	int		j;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = 0;
	if (n < 0)
		j = 1;
	len = itoa_size(n) + j;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	n = n * (((n < 0) * -2) + 1);
	convertion(str, n, len, j);
	return (str);
}
