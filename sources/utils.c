/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:32:17 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/02 14:14:37 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/push_swap.h"

/**
 * @brief Function to calculate the size of a string array.
 * 
 * @param tab Array of character string to count.
 * @return (int) Size of the string array.
 */
int	len_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

/**
 * @brief Function to free the memory of a character string array.
 * 
 * @param tab Array of character string to free.
 */
void	free_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
	{
		free(tab[size]);
		size++;
	}
	free(tab);
}

/**
 * @brief Function to free previously allocated malloc memory and
 * thus avoid memory leaks.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 */
void	free_memory(t_data *data)
{
	free(data->list_original);
	free(data->stack_a);
	free(data->stack_b);
}
