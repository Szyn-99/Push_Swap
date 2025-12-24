/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:17:34 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/24 18:33:52 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_position_v2(t_list *stack, int value)
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
	return (-42);
}

int	find_min_v2(t_list *stack)
{
	int	min;

	if (!stack)
		return (-13);
	min = stack->value_index;
	while (stack)
	{
		if (stack->value_index <= min)
			min = stack->value_index;
		stack = stack->next;
	}
	return (min);
}

int	detect_pattern(t_list *stack, int size)
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

void	init_chunks_var(t_ChS *chunks, t_list **stack_a)
{
	chunks->start = 0;
	chunks->end = chunks_size(*stack_a, chunks) - 1;
	chunks->pattern = detect_pattern(*stack_a, chunks->size);
}
