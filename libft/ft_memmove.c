/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:11:54 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/17 12:33:14 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	*new_src;
	unsigned char	*new_dst;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (src >= dst)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		idx = len;
		while (idx > 0)
		{
			new_dst[idx - 1] = new_src[idx - 1];
			idx--;
		}
	}
	return (dst);
}
