/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:21:41 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/13 14:22:54 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	letter;
	size_t			idx;
	unsigned char	*new_s;

	letter = (unsigned char)c;
	idx = 0;
	new_s = (unsigned char *)s;
	while (idx < n)
	{
		if (new_s[idx] == letter)
			return ((unsigned char *)&s[idx]);
		idx++;
	}
	return (NULL);
}
