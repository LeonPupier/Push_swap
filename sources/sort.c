/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:30:07 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/22 14:17:38 by lpupier          ###   ########.fr       */
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
 * SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR.
 * @return (int) Returns 1 if the sort was performed, 0 otherwise.
 */
int	sort_operations(t_data *data, int mode)
{
	if (mode == SA)
		return (sa(data), ft_printf("sa\n"), 1);
	else if (mode == SB)
		return (sb(data), ft_printf("sb\n"), 1);
	else if (mode == SS)
		return (sa(data), sb(data), ft_printf("ss\n"), 1);
	else if (mode == PA)
		return (pa(data), ft_printf("pa\n"), 1);
	else if (mode == PB)
		return (pb(data), ft_printf("pb\n"), 1);
	else if (mode == RA)
		return (ra(data), ft_printf("ra\n"), 1);
	else if (mode == RB)
		return (rb(data), ft_printf("rb\n"), 1);
	else if (mode == RR)
		return (ra(data), rb(data), ft_printf("rr\n"), 1);
	else if (mode == RRA)
		return (rra(data), ft_printf("rra\n"), 1);
	else if (mode == RRB)
		return (rrb(data), ft_printf("rrb\n"), 1);
	else if (mode == RRR)
		return (rra(data), rrb(data), ft_printf("rrr\n"), 1);
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
	(void)data;
}

/**
 * @brief Function for sorting the stack of the structure
 * if its size is greater than 5 elements.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	sort_big_stack(t_data *data)
{
	(void)data;
}
