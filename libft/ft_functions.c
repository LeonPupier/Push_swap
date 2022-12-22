/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:34:23 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/02 17:24:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_p(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) != -1)
		*count = *count + 1;
	else
		*count = -1;
}

void	ft_putstr_p(char *str, int *count)
{
	int	idx;

	idx = 0;
	if (!str)
		return (ft_putstr_p("(null)", count));
	while (str[idx])
	{
		ft_putchar_p(str[idx], count);
		idx++;
	}
}
