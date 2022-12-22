/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:37 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/17 12:00:10 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	idx = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (new_s1[idx] && new_s2[idx]
		&& new_s1[idx] == new_s2[idx] && idx < n - 1)
		idx++;
	return (new_s1[idx] - new_s2[idx]);
}
