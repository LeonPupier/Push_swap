/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:19:50 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/16 08:28:19 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elt;

	new_lst = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			new_elt = ft_lstnew(f(lst -> content));
			if (!new_elt)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}	
			ft_lstadd_back(&new_lst, new_elt);
			lst = lst -> next;
		}
		return (new_lst);
	}
	return (NULL);
}
