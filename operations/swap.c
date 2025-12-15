/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:08 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/15 18:59:00 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_swap(t_list **stack)
{
	int	swap;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	swap = (*stack)->value_raw;
	(*stack)->value_raw = (*stack)->next->value_raw;
	(*stack)->next->value_raw = swap;
	swap = (*stack)->value_index;
	(*stack)->value_index = (*stack)->next->value_index;
	(*stack)->next->value_index = swap;
}

void	op_swap_a(t_list **stack_a)
{
	op_swap(stack_a);
	ft_putstring_fd("sa\n", 1);
}

void	op_swap_b(t_list **stack_b)
{
	op_swap(stack_b);
	ft_putstring_fd("sb\n", 1);
}

void	op_swap_ss(t_list **stack_a, t_list **stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
	ft_putstring_fd("ss\n", 1);
}
