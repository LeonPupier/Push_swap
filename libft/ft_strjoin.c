/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:06:31 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/14 13:24:55 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_total;
	char	*new_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_total = ft_strlen(s1) + ft_strlen(s2);
	new_s1 = malloc(sizeof(char) * (size_total + 1));
	if (!new_s1)
		return (NULL);
	ft_strlcpy(new_s1, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_s1, s2, size_total + 1);
	return (new_s1);
}
