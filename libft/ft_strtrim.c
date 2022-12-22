/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:04:07 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/16 16:15:37 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_c_in_s(char *set, char c)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

static char	*ft_len_is_zero(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static char	*loop(char const *s1, char const *set, size_t len_s1, size_t start)
{
	char	*new_s1;
	size_t	idx;

	idx = 0;
	while (s1[idx] && ft_check_c_in_s((char *)set, s1[idx]))
	{
		len_s1--;
		idx++;
	}
	if (len_s1 > 0)
	{
		start = idx;
		idx = ft_strlen(s1) - 1;
		while (s1[idx] && ft_check_c_in_s((char *)set, s1[idx]))
		{
			len_s1--;
			idx--;
		}
	}
	if (len_s1 == 0)
		new_s1 = ft_len_is_zero();
	else
		new_s1 = ft_substr(s1, start, len_s1);
	return (new_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	idx;
	size_t	start_new_s1;
	char	*new_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	idx = 0;
	start_new_s1 = 0;
	new_s1 = loop(s1, set, len_s1, start_new_s1);
	return (new_s1);
}
