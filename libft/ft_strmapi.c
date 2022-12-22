/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:43:36 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/17 10:46:08 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	int		size;
	char	*new_s;

	if (!s || !f)
		return (NULL);
	idx = 0;
	size = ft_strlen(s);
	new_s = malloc(sizeof(char) * (size + 1));
	if (!new_s)
		return (NULL);
	while (s[idx])
	{
		new_s[idx] = f(idx, s[idx]);
		idx++;
	}
	new_s[size] = '\0';
	return (new_s);
}
