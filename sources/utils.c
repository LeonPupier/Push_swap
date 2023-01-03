/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:32:17 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/03 11:52:22 by lpupier          ###   ########.fr       */
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
 * @brief Function to find the index of the smallest value of the integer
 * array provided as a parameter by analyzing the first "size" entries.
 * 
 * @param tab Integer array.
 * @param size The size of the number array.
 * @return (int) Returns the index in the array of the smallest value.
 */
int	get_smallest_value(int *tab, int size)
{
	int	idx;
	int	idx_min;

	idx = 0;
	idx_min = 0;
	while (idx < size)
	{
		if (tab[idx] < tab[idx_min])
			idx_min = idx;
		idx++;
	}
	return (idx_min);
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
