/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:14:15 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/12 00:06:15 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = NULL;
	last_node = NULL;
	first_node = *stack;
	*stack = (*stack)->next;
	first_node->next = NULL;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
}

void	op_rotate_a(t_list **stack_a)
{
	op_rotate(stack_a);
	ft_putstring("ra\n");
}

void	op_rotate_b(t_list **stack_b)
{
	op_rotate(stack_b);
	ft_putstring("rb\n");
}

void	op_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	op_rotate(stack_a);
	op_rotate(stack_b);
	ft_putstring("rr\n");
}
