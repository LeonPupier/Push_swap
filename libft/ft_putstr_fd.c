/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:00:51 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/14 16:09:44 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;
	size_t	idx;

	if (s)
	{
		size = ft_strlen(s);
		idx = 0;
		while (idx < size)
		{
			ft_putchar_fd(s[idx], fd);
			idx++;
		}
	}
}
