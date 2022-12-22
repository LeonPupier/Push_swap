/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:53:15 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/22 08:56:44 by lpupier          ###   ########.fr       */
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
		return (ft_printf("Error\n"), EXIT_FAILURE);
	data.len_list = argc - 1;
	if (!extract_numbers(&data, argv))
		return (ft_printf("Error\n"), EXIT_FAILURE);
	if (!recover_list_index(&data))
		return (ft_printf("Error\n"), EXIT_FAILURE);
	if (is_sorted(&data))
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
