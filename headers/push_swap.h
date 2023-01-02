/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:56:24 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/02 14:14:28 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Define
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librairies
# include <stdlib.h>

// Headers
# include "../libft/libft.h"

// Macros
# define EMPTY 0

// Stack Operations
enum {
	SA,
	PA,
	PB,
	RA
};

// Structure list data
typedef struct s_data {
	int	*list_original;
	int	*stack_a;
	int	*stack_b;
	int	len_stack_default;
	int	len_stack_a;
	int	len_stack_b;
}	t_data;

// numbers_gestion.c

int		extract_numbers(t_data *data, char **list_str);
int		extract_one_argument(t_data *data, char *str);
int		exist_in_list(t_data *data, long nb, int max);
int		recover_list_index(t_data *data);
int		is_sorted(t_data *data);

// sort.c

int		sort_operations(t_data *data, int mode);
void	sort_small_stack(t_data *data);
void	sort_stack_3(t_data *data);
void	sort_big_stack(t_data *data);

// operations.c

void	sa(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);

// utils.c

int		len_tab(char **tab);
void	free_tab(char **tab);
void	free_memory(t_data *data);

#endif