/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:20:22 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/02 17:23:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_base(long long unsigned int nbr, long long unsigned int size,
						char *base, int *count)
{
	if (nbr > (size - 1))
		ft_putnbr_base((nbr / size), size, base, count);
	ft_putchar_p(base[nbr % size], count);
}

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == INT_MIN)
	{
		ft_putstr_p("-2147483648", count);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_p('-', count);
		nbr *= -1;
	}
	ft_putnbr_base(nbr, 10, "0123456789", count);
}
