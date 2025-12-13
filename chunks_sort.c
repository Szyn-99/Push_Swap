/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:22:11 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/13 15:05:45 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunks_size(t_list *stack, t_ChS *chunks)
{
	int	size;

	size = ft_lstsize(stack);
	chunks->size = size;
	if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	return (45);
}

int	find_max(t_list *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->value_index >= max)
			max = stack->value_index;
		stack = stack->next;
	}
	return (max);
}
int	find_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->value_index == value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

void	chunks_sort(t_list **stack_a, t_list **stack_b)
{
	t_ChS	chunks;

	chunks.start = 0;
	chunks.end = chunks_size(*stack_a, &chunks);
	while (*stack_a)
	{
		if ((*stack_a)->value_index < chunks.start)
		{
			op_push_b(stack_b, stack_a);
			op_rotate_b(stack_b);
			chunks.end++;
			chunks.start++;
		}
		else if (chunks.start <= (*stack_a)->value_index
			&& (*stack_a)->value_index <= chunks.end)
		{
			op_push_b(stack_b, stack_a);
			chunks.start++;
			chunks.end++;
		}
		else
			op_rotate_a(stack_a);
	}
	while (*stack_b)
	{
		chunks.max_index = find_max(*stack_b);
		chunks.position = find_position(*stack_b, chunks.max_index);
		if (chunks.position <= chunks.size / 2)
		{
			while ((*stack_b)->value_index != chunks.max_index)
				op_rotate_b(stack_b);
		}
		else
		{
			while ((*stack_b)->value_index != chunks.max_index)
				op_rotate_reverse_b(stack_b);
		}
		op_push_a(stack_a, stack_b);
	}
}
