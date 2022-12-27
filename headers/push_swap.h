/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:56:24 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/22 14:08:30 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Define
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librairies
# include <limits.h>
# include <stdlib.h>

// Headers
# include "../libft/libft.h"

// Stack Operations
enum {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

// Structure list data
typedef struct s_data {
	int	*stack_a;
	int	*stack_b;
	int	*list_index;
	int	len_stack;
}	t_data;

// numbers_gestion.c

int		extract_numbers(t_data *data, char **list_str);
int		exist_in_list(t_data *data, int nb, int max);
int		recover_list_index(t_data *data);
int		is_sorted(t_data *data);

// sort.c

int		sort_operations(t_data *data, int mode);
void	sort_small_stack(t_data *data);
void	sort_big_stack(t_data *data);

// operations.c

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// utils.c

void	free_memory(t_data *data);

#endif