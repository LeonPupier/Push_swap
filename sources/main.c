/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:53:15 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/02 13:47:06 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/push_swap.h"

/**
 * @brief Body of the program, the goal is to sort the integer passes into
 * arguments of the program as quickly as possible.
 * 
 * @param argc Number of arguments provided to the program.
 * @param argv List of char* containing program arguments.
 * @return (int) Returns EXIT_SUCCESS if the program went well,
 * EXIT_FAILURE otherwise.
 */
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	data.len_stack_default = argc - 1;
	if (!extract_numbers(&data, argv))
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	if (!recover_list_index(&data))
		return (free(data.list_original), write(2, "Error\n", 6), EXIT_FAILURE);
	data.stack_b = ft_calloc(sizeof(int), data.len_stack_a);
	if (data.stack_b == NULL)
		return (free(data.list_original), free(data.stack_a), \
			write(2, "Error\n", 6), EXIT_FAILURE);
	data.len_stack_b = 0;
	if (is_sorted(&data))
		return (free_memory(&data), EXIT_SUCCESS);
	if (data.len_stack_a <= 5)
		sort_small_stack(&data);
	else
		sort_big_stack(&data);
	return (free_memory(&data), EXIT_SUCCESS);
}
