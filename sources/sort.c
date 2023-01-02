/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:30:07 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/02 10:42:54 by lpupier          ###   ########.fr       */
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
 * SA, PA, PB, RA.
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
	if (data->len_stack_a == 4)
	{
	}
	if (data->len_stack_a == 5)
	{
	}
}

/**
 * @brief Function to sort an integer list of 3 elements.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	sort_stack_3(t_data *data)
{
	if (data->stack_a[2] > data->stack_a[0])
	{
		sort_operations(data, PB);
		sort_operations(data, RA);
		sort_operations(data, PA);
		sort_operations(data, RA);
	}
	if (data->stack_a[2] > data->stack_a[1])
		sort_operations(data, SA);
	if (data->stack_a[1] > data->stack_a[0])
	{
		sort_operations(data, PB);
		sort_operations(data, RA);
		sort_operations(data, PA);
	}
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
