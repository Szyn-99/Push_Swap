/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:11:37 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/15 18:50:20 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_list(t_list **stack_a, char *concat)
{
	char	**raw_values;
	int		i;
	int		raw_val_n;
	t_list	*node;

	raw_values = ft_split(concat, ' ');
	if (!raw_values)
	{
		return ;
	}
	i = -1;
	while (raw_values[++i] != NULL)
	{
		raw_val_n = ft_atoi(raw_values[i]);
		node = ft_lstnew(raw_val_n);
		if (!node)
		{
			clear_strings(raw_values);
			ft_lstclear(stack_a);
			return ;
		}
		ft_lstadd_back(stack_a, node);
	}
	clear_strings(raw_values);
}

void	generate_index_util(int *array, int size)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	while (x < size - 1)
	{
		y = 0;
		while (y < size - 1)
		{
			if (array[y] > array[y + 1])
			{
				n = array[y];
				array[y] = array[y + 1];
				array[y + 1] = n;
			}
			y++;
		}
		x++;
	}
}

void	get_index_util(t_list *stack_a, int list_size, int *array)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i = 0;
		while (i < list_size)
		{
			if (stack_a->value_raw == array[i])
				stack_a->value_index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
	free(array);
}

int	sorted_input_guard(int array[], int list_size, t_list **clear)
{
	int	i;

	i = 0;
	while (i < list_size - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			break ;
	}
	if (i == list_size - 1)
		return (free(array), ft_lstclear(clear), 0);
	return (1);
}

void	init_index(t_list **stack_a)
{
	int		list_size;
	int		i;
	int		*array;
	t_list	*copy;

	copy = *stack_a;
	list_size = ft_lstsize(*stack_a);
	array = malloc(sizeof(int) * list_size);
	if (!array)
		return ;
	copy = *stack_a;
	i = 0;
	while (i < list_size)
	{
		array[i] = copy->value_raw;
		copy = copy->next;
		i++;
	}
	if (!sorted_input_guard(array, list_size, stack_a))
		return ;
	generate_index_util(array, list_size);
	if (!duplicate_detector(array, list_size, stack_a))
		return ;
	get_index_util(*stack_a, list_size, array);
}
