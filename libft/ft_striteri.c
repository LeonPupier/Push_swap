/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:31:37 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/16 16:09:49 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		idx;

	idx = 0;
	if (s && f)
	{
		while (s[idx])
		{
			f(idx, &s[idx]);
			idx++;
		}
	}
}
