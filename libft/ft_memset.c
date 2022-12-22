/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:04:25 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/09 14:45:32 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	size_t			idx;

	d = (unsigned char *)b;
	idx = 0;
	while (idx < len)
	{
		d[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}
