/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:29:34 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/17 12:07:06 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;
	size_t	idx;
	size_t	len_s;

	letter = (char)c;
	idx = 0;
	len_s = ft_strlen(s) + 1;
	if ((char)c == 0)
		return ((char *) s + ft_strlen(s));
	while (idx <= len_s && s[idx])
	{
		if (s[idx] == letter)
			return ((char *) s + idx);
		idx++;
	}
	return (NULL);
}
