/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:21 by lpupier           #+#    #+#             */
/*   Updated: 2023/01/02 13:46:33 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
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
	int			len;
	long long	nb;

	if (data->len_stack_default == 1)
		return (extract_one_argument(data, list_str[1]));
	data->list_original = malloc(sizeof(int) * data->len_stack_default);
	if (data->list_original == NULL)
		return (0);
	len = 0;
	while (len < data->len_stack_default)
	{
		nb = ft_atoi(list_str[len + 1]);
		if (nb > INT_MAX || nb < INT_MIN || exist_in_list(data, nb, len))
			return (free(data->list_original), 0);
		data->list_original[data->len_stack_default - 1 - len] = nb;
		len++;
	}
	return (1);
}

/**
 * @brief Function to parse the character string if the program
 * has only one additional argument.
 * 
 * @param data Data structure containing my variables (see push_swap.h).
 * @param str Character string corresponding to the second argument of **argv.
 * @return (int) Returns 1 if the parsing went well, 0 otherwise.
 */
int	extract_one_argument(t_data *data, char *str)
{
	int		len;
	long	nb;
	char	**list_arg;

	list_arg = ft_split(str, ' ');
	if (list_arg == NULL)
		return (0);
	data->len_stack_default = len_tab(list_arg);
	data->list_original = malloc(sizeof(int) * data->len_stack_default);
	if (data->list_original == NULL)
		return (free_tab(list_arg), 0);
	len = 0;
	while (len < data->len_stack_default)
	{
		nb = ft_atoi(list_arg[len]);
		if (nb > INT_MAX || nb < INT_MIN || exist_in_list(data, nb, len))
			return (free(data->list_original), 0);
		data->list_original[data->len_stack_default - 1 - len] = nb;
		len++;
	}
	free_tab(list_arg);
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
int	exist_in_list(t_data *data, long nb, int max)
{
	long	count;

	count = 0;
	while (count < max)
	{
		if (data->list_original[data->len_stack_default - count] == nb)
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
	data->len_stack_a = data->len_stack_default;
	data->stack_a = ft_calloc(sizeof(int), data->len_stack_a);
	if (data->stack_a == NULL)
		return (0);
	while (count < data->len_stack_a)
	{
		x = 0;
		y = 0;
		while (y < data->len_stack_a)
		{
			if (data->list_original[y] < data->list_original[count])
				x++;
			y++;
		}
		data->stack_a[count] = x;
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
	backup = data->stack_a[0];
	while (count < data->len_stack_a)
	{
		if (data->stack_a[count] > backup)
			return (0);
		backup = data->stack_a[count];
		count++;
	}
	return (1);
}
