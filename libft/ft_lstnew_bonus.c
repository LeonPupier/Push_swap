/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:14:01 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/16 16:08:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
