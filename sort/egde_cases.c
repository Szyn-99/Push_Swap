/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egde_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:04:45 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/16 22:41:24 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two_numbers(t_list **stack)
{
	if ((*stack)->value_index > (*stack)->next->value_index)
		op_swap_a(stack);
}

void	half_sort_three(int first_value, int second_value, int third_value,
		t_list **stack)
{
	if (first_value < second_value && third_value < second_value
		&& first_value < third_value)
	{
		op_swap_a(stack);
		op_rotate_a(stack);
	}
	else if (first_value < second_value && third_value < second_value
		&& first_value > third_value)
		op_rotate_reverse_a(stack);
	else if (first_value > second_value && third_value > second_value
		&& first_value > third_value)
		op_rotate_a(stack);
	else if (first_value > second_value && second_value > third_value
		&& first_value > third_value)
	{
		op_swap_a(stack);
		op_rotate_reverse_a(stack);
	}
}

void	sort_three_and_two_numbers(t_list **stack)
{
	int	first_value;
	int	second_value;
	int	third_value;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (!(*stack)->next->next)
	{
		sort_two_numbers(stack);
		return ;
	}
	first_value = (*stack)->value_index;
	second_value = (*stack)->next->value_index;
	third_value = (*stack)->next->next->value_index;
	if (second_value < first_value && second_value < third_value
		&& first_value < third_value)
		op_swap_a(stack);
	else
		half_sort_three(first_value, second_value, third_value, stack);
}

void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	int	smallest_value;
	int	count;
	int	smallest_value_position;
	int	size;

	count = 2;
	while (count != 0)
	{
		size = ft_lstsize(*stack_a);
		smallest_value = find_min_v2(*stack_a);
		smallest_value_position = find_position_v2(*stack_a, smallest_value);
		if (smallest_value_position < size / 2)
		{
			while (smallest_value != (*stack_a)->value_index)
				op_rotate_a(stack_a);
		}
		else
			while (smallest_value != (*stack_a)->value_index)
				op_rotate_reverse_a(stack_a);
		op_push_b(stack_b, stack_a);
		count--;
	}
	sort_three_and_two_numbers(stack_a);
	op_push_a(stack_a, stack_b);
	op_push_a(stack_a, stack_b);
}
