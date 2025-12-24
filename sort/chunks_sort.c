/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:22:11 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/24 18:08:43 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	detect_pattern(t_list *stack, int size)
{
	int	count;
	int	diff;

	count = 0;
	while (stack && stack->next)
	{
		diff = stack->value_index - stack->next->value_index;
		if (diff < 0)
			diff = -diff;
		if (diff > 1 && diff < 5)
			count++;
		stack = stack->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

int	chunks_size(t_list *stack, t_ChS *chunks)
{
	int	size;

	size = ft_lstsize(stack);
	chunks->size = size;
	if (size <= 100)
		return (16);
	else if (size <= 500)
		return (37);
	else
		return (42);
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
	int	node_position;

	node_position = 0;
	while (stack)
	{
		if (stack->value_index == value)
			return (node_position);
		node_position++;
		stack = stack->next;
	}
	return (-1337);
}

void	chunk_sort_norminette(t_list **stack_a, t_list **stack_b, t_ChS *chunks)
{
	while (*stack_b)
	{
		chunks->size_now = ft_lstsize(*stack_b);
		chunks->max_index = find_max(*stack_b);
		chunks->position = find_position(*stack_b, chunks->max_index);
		if (chunks->position <= chunks->size_now / 2)
		{
			while ((*stack_b)->value_index != chunks->max_index)
				op_rotate_b(stack_b, 2);
		}
		else
		{
			while ((*stack_b)->value_index != chunks->max_index)
				op_rotate_reverse_b(stack_b, 0x001);
		}
		op_push_a(stack_a, stack_b, 21);
	}
}

void	chunks_sort(t_list **stack_a, t_list **stack_b)
{
	t_ChS	chunks;
	int		pattern;

	chunks.start = 0;
	chunks.end = chunks_size(*stack_a, &chunks) - 1;
	pattern = detect_pattern(*stack_a, chunks.size);
	while (*stack_a)
	{
		if ((*stack_a)->value_index < chunks.start)
		{
			op_push_b(stack_b, stack_a, 0x01010);
			op_rotate_b(stack_b, 2);
			chunks.end++;
			chunks.start++;
		}
		else if (chunks.start <= (*stack_a)->value_index
			&& (*stack_a)->value_index <= chunks.end)
		{
			op_push_b(stack_b, stack_a, 0x01010);
			chunks.start++;
			chunks.end++;
		}
		else if (pattern)
			op_rotate_reverse_a(stack_a, 0);
		else
			op_rotate_a(stack_a, 0000);
	}
	chunk_sort_norminette(stack_a, stack_b, &chunks);
}
