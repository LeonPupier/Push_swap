/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:32:17 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/22 14:06:49 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/push_swap.h"

/**
 * @brief Function to free previously allocated malloc memory and
 * thus avoid memory leaks.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	free_memory(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data->list_index);
}
