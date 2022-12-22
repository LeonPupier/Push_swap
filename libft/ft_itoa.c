/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:44:05 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/16 16:14:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_itoa(int n)
{
	size_t	count;
	size_t	sign;

	count = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	if (sign == 1)
		return (count);
	else
		return (count + 1);
}

static char	*ft_convert_itoa(char *str, int n, size_t count)
{
	size_t	idx;

	idx = count - 1;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[idx] = ((n % 10) + 48);
		n /= 10;
		idx--;
	}
	return (str);
}

static char	*ft_n_is_zero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;

	if (n == 0)
		return (ft_n_is_zero());
	else if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		str[11] = '\0';
		return (str);
	}
	count = ft_count_itoa(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	str = ft_convert_itoa(str, n, count);
	return (str);
}
