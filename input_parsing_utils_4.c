/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szyn <szyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:11:37 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/13 18:21:24 by szyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_strings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
			/* allocation failed for node: free split results and any built list
			   caller owns `concat` and should free it; do not free it here */
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

void	init_index(t_list **stack_a)
{
	t_list	*copy;
	int		list_size;
	int		i;
	int		*array;

	copy = *stack_a;
	list_size = ft_lstsize(*stack_a);
	array = malloc(sizeof(int) * list_size);
	i = 0;
	if (!array)
	{
		return ;
	}
	while (i < list_size)
	{
		array[i] = (*stack_a)->value_raw;
		*stack_a = (*stack_a)->next;
		i++;
	}
	/* sort array */
	generate_index_util(array, list_size);
	/* detect duplicates in the sorted array */
	i = 0;
	while (i < list_size - 1)
	{
		if (array[i] == array[i + 1])
		{
			/* duplicate found: report and exit (free array first) */
			write(2, "Error\n", 6);
			free(array);
			ft_lstclear(&copy);
			exit(1);
		}
		i++;
	}
	/* restore stack pointer and set indices */
	*stack_a = copy;
	get_index_util(*stack_a, list_size, array);
}
