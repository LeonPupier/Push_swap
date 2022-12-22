/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:51:30 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/14 16:06:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	int		idx_n;
	char	*new_s;

	if (s == NULL)
		return (NULL);
	idx = 0;
	idx_n = 0;
	if (ft_strlen(s) >= len)
		new_s = malloc(sizeof(char) * (len + 1));
	else
		new_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		return (NULL);
	while (s[idx] && idx < len + start)
	{
		if (idx >= (size_t)start)
		{
			new_s[idx_n] = s[idx];
			idx_n++;
		}
		idx++;
	}
	new_s[idx_n] = '\0';
	return (new_s);
}
