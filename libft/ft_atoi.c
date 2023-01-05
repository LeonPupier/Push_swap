/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:19:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/05 13:42:36 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_conv(long long int res)
{
	if (res > INT_MAX)
		return (res - LLONG_MAX - 1);
	else if (res < INT_MIN)
		return (res - LLONG_MIN);
	else
		return (res);
}

long long	ft_atoi(const char *str)
{
	long long int	result;
	int				idx;
	int				sign;

	result = 0;
	idx = 0;
	sign = 1;
	if (!ft_strncmp(str, "-2147483648", 11))
		return (-2147483648);
	if (str[idx] == '+' || str[idx] == '-')
	{	
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		if ((int)result != (((int)result * 10 + (str[idx] - 48)) / 10))
			return (2147483649);
		result = result * 10 + str[idx] - 48;
		idx++;
	}
	if (str[idx] || (str[idx - 1] < '0' || str[idx - 1] > '9'))
		return (2147483649);
	return ((long)ft_conv(result * sign));
}
