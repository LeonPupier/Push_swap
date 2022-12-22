/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:20:44 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/17 13:14:16 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	idx_n;

	idx = 0;
	if (!len && !haystack)
		return (NULL);
	else if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[idx] && idx < len)
	{
		if (haystack[idx] == needle[0])
		{
			idx_n = 1;
			while ((haystack[idx + idx_n] == needle[idx_n]
					&& needle[idx_n]) && (idx + idx_n < len))
				idx_n++;
			if (!needle[idx_n])
				return ((char *) haystack + idx);
		}
		idx++;
	}
	return (NULL);
}
