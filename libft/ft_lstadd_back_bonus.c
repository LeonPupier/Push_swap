/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:36:16 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/15 16:45:42 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elt;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			elt = ft_lstlast(*lst);
			elt -> next = new;
		}
	}
}
