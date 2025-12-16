/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:17:34 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/16 22:26:12 by aymel-ha         ###   ########.fr       */
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
