/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:30:07 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/03 14:00:49 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/push_swap.h"

/**
 * @brief Desired sorting mode redirection function
 * and display of the log on the terminal.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @param mode Selection of the data packet sorting mode among:
 * SA, PA, PB, RA, RRA.
 * @return (int) Returns 1 if the sort was performed, 0 otherwise.
 */
int	sort_operations(t_data *data, int mode)
{
	if (mode == SA)
		return (sa(data), ft_printf("sa\n"), 1);
	else if (mode == PA)
		return (pa(data), ft_printf("pa\n"), 1);
	else if (mode == PB)
		return (pb(data), ft_printf("pb\n"), 1);
	else if (mode == RA)
		return (ra(data), ft_printf("ra\n"), 1);
	else if (mode == RRA)
		return (rra(data), ft_printf("rra\n"), 1);
	return (0);
}

/**
 * @brief Function for sorting the stack of the structure
 * if its size is between 1 and 5 elements included.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	sort_small_stack(t_data *data)
{
	if (data->len_stack_a == 2)
		sort_operations(data, RA);
	if (data->len_stack_a == 3)
		sort_stack_3(data);
	if (data->len_stack_a == 4 || data->len_stack_a == 5)
		sort_stack_4_5(data, 0);
}

/**
 * @brief Function to sort an integer list of 3 elements.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	sort_stack_3(t_data *data)
{
	int	*stack;

	stack = data->stack_a;
	if (stack[2] > stack[1] && stack[1] < stack[0] && stack[0] > stack[2])
		sort_operations(data, SA);
	else if (stack[2] > stack[1] && stack[1] > stack[0] && stack[0] < stack[2])
	{
		sort_operations(data, SA);
		sort_operations(data, RRA);
	}
	else if (stack[2] > stack[1] && stack[1] < stack[0] && stack[0] < stack[2])
		sort_operations(data, RA);
	else if (stack[2] < stack[1] && stack[1] > stack[0] && stack[0] > stack[2])
	{
		sort_operations(data, SA);
		sort_operations(data, RA);
	}
	else if (stack[2] < stack[1] && stack[1] > stack[0] && stack[0] < stack[2])
		sort_operations(data, RRA);
}

/**
 * @brief Function to sort an integer list of 4 or 5 elements.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @param min Minimum number to search in the list of integers.
 */
void	sort_stack_4_5(t_data *data, int min)
{
	int	idx_min;

	idx_min = get_smallest_value(data->stack_a, data->len_stack_a);
	while (data->stack_a[data->len_stack_a - 1] != min)
	{
		if (idx_min > data->len_stack_a / 2)
			sort_operations(data, RA);
		else
			sort_operations(data, RRA);
	}
	sort_operations(data, PB);
	if (data->len_stack_a == 4)
		sort_stack_4_5(data, 1);
	if (data->len_stack_a == 3)
	{
		sort_stack_3(data);
		sort_operations(data, PA);
	}
	if (data->len_stack_a == 4)
		sort_operations(data, PA);
}

/**
 * @brief Function for sorting the stack of the structure
 * if its size is greater than 5 elements with Radix method.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	sort_big_stack(t_data *data)
{
	int	count;
	int	gap;
	int	number;
	int	temp;

	gap = 1;
	while (!is_sorted(data))
	{
		count = 0;
		temp = data->len_stack_a;
		while (count < temp)
		{
			number = data->stack_a[data->len_stack_a - 1];
			if ((number & gap) == 0)
				sort_operations(data, PB);
			else
				sort_operations(data, RA);
			count++;
		}
		while (data->len_stack_b)
			sort_operations(data, PA);
		gap *= 2;
	}
}
