/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:51:30 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/16 16:06:13 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_separator(char const *s, char c)
{
	size_t	idx;
	size_t	count;

	idx = 0;
	count = 0;
	while (s[idx])
	{
		if (s[idx] != c)
		{
			idx++;
			count++;
			while (s[idx] && s[idx] != c)
				idx++;
		}
		else
			idx++;
	}
	return (count);
}

static void	*ft_free_tab(char **tab)
{
	while (*tab != NULL)
	{
		free(*tab);
		tab++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_assign_value(char **tab, char const *s, char c)
{
	size_t	idx;
	size_t	idx_start;
	size_t	idx_tab;

	idx = 0;
	idx_tab = 0;
	while (s[idx])
	{
		idx_start = idx;
		if (s[idx] != c)
		{
			idx++;
			while (s[idx] && s[idx] != c)
				idx++;
			tab[idx_tab] = ft_substr(s, idx_start, idx - idx_start);
			if (!tab[idx_tab])
				return (ft_free_tab(tab));
			idx_tab++;
		}
		else
			idx++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**tab;

	if (!s)
		return (NULL);
	count = ft_count_separator(s, c);
	tab = malloc(sizeof(char *) *(count + 1));
	if (!tab)
		return (NULL);
	tab[count] = NULL;
	tab = ft_assign_value(tab, s, c);
	return (tab);
}
