/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:46:49 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/14 16:44:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	idx;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / count < size)
		return (NULL);
	mem = malloc(sizeof(char) * (count * size));
	if (!mem)
		return (NULL);
	idx = 0;
	while (idx < (count * size))
	{
		mem[idx] = 0;
		idx++;
	}
	return ((void *)mem);
}
