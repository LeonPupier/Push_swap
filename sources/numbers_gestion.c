/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:21 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/22 08:51:47 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/**
 * @brief Function to parse the arguments provided to the program by **argv
 * by creating an array of integers in the parameter structure.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @param list_str Array of character strings containing char* type integers.
 * @return (int) Returns 1 if the parsing went well, 0 otherwise.
 */
int	extract_numbers(t_data *data, char **list_str)
{
	int		len;
	long	nb;

	data->list_numbers = malloc(sizeof(int) * data->len_list);
	if (data->list_numbers == NULL)
		return (0);
	len = 1;
	while (len < data->len_list + 1)
	{
		nb = ft_atoi(list_str[len]);
		if (nb == 2147483648 || exist_in_list(data, nb, len - 1) == 1)
			return (0);
		data->list_numbers[len - 1] = nb;
		len++;
	}
	return (1);
}

/**
 * @brief Function to find out if the number "nb" is present in the list of
 * integers passed as a parameter in the "max" first entry of the list.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @param nb Integer to compare to other list entries.
 * @param max Maximum entry of the list already filled.
 * @return (int) Returns 1 if "nb" is present in the list of integers,
 * 0 otherwise.
 */
int	exist_in_list(t_data *data, int nb, int max)
{
	int	count;

	count = 0;
	while (count < max)
	{
		if (data->list_numbers[count] == nb)
			return (1);
		count++;
	}
	return (0);
}

/**
 * @brief Function for retrieving the index of each integer
 * in the list to know their final location in the sorted list.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @return (int) Returns 1 if the recovery of each index of the list
 * of integers is successful, 0 otherwise (malloc error).
 */
int	recover_list_index(t_data *data)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	data->list_index = malloc(sizeof(int) * data->len_list);
	if (data->list_index == NULL)
		return (0);
	while (count < data->len_list)
	{
		x = 0;
		y = 0;
		while (y < data->len_list)
		{
			if (data->list_numbers[y] < data->list_numbers[count])
				x++;
			y++;
		}
		data->list_index[count] = x;
		count++;
	}
	return (1);
}

/**
 * @brief Function to check if the list of integers of the structure
 * passed as a parameter is already sorted.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @return (int) Returns 1 if the integer list is already sorted, 0 otherwise.
 */
int	is_sorted(t_data *data)
{
	int	count;
	int	backup;

	count = 0;
	backup = data->list_index[0];
	while (count < data->len_list)
	{
		if (data->list_index[count] < backup)
			return (0);
		backup = data->list_index[count];
		count++;
	}
	return (1);
}
