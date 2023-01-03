/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:12:23 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/03 13:16:16 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	sa(t_data *data)
{
	int	temp;

	temp = data->stack_a[data->len_stack_a - 1];
	data->stack_a[data->len_stack_a - 1] = data->stack_a[data->len_stack_a - 2];
	data->stack_a[data->len_stack_a - 2] = temp;
}

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	pa(t_data *data)
{
	if (data->len_stack_b == 0)
		return ;
	data->stack_a[data->len_stack_a] = data->stack_b[data->len_stack_b - 1];
	data->stack_b[data->len_stack_b - 1] = EMPTY;
	data->len_stack_b -= 1;
	data->len_stack_a += 1;
}

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	pb(t_data *data)
{
	if (data->len_stack_a == 0)
		return ;
	data->stack_b[data->len_stack_b] = data->stack_a[data->len_stack_a - 1];
	data->stack_a[data->len_stack_a - 1] = EMPTY;
	data->len_stack_a -= 1;
	data->len_stack_b += 1;
}

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	ra(t_data *data)
{
	int	last;
	int	i;

	last = data->stack_a[data->len_stack_a - 1];
	i = data->len_stack_a + 1;
	while (--i > 0)
		data->stack_a[i] = data->stack_a[i - 1];
	data->stack_a[i] = last;
}

/**
 * @brief Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	rra(t_data *data)
{
	int	first;
	int	i;

	first = data->stack_a[0];
	i = -1;
	while (++i < data->len_stack_a)
		data->stack_a[i] = data->stack_a[i + 1];
	data->stack_a[data->len_stack_a - 1] = first;
}
