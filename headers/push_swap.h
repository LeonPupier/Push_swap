/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:56:24 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/22 08:28:23 by lpupier          ###   ########.fr       */
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

// Structure list data
typedef struct s_data {
	int	*list_numbers;
	int	*list_index;
	int	len_list;
}	t_data;

// numbers_gestion.c

int	extract_numbers(t_data *data, char **list_str);
int	exist_in_list(t_data *data, int nb, int max);
int	recover_list_index(t_data *data);
int	is_sorted(t_data *data);

#endif