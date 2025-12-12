/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:25:32 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/12 10:51:23 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_rotate_reverse(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*before_last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = NULL;
	last_node = NULL;
	before_last_node = NULL;
	before_last_node = *stack;
	first_node = *stack;
	while (before_last_node->next->next)
		before_last_node = before_last_node->next;
	last_node = ft_lstlast(*stack);
	before_last_node->next = NULL;
	last_node->next = first_node;
	*stack = last_node;
}

void	op_rotate_reverse_a(t_list **stack_a)
{
	op_rotate_reverse(stack_a);
	ft_putstring("rra\n");
}

void	op_rotate_reverse_b(t_list **stack_b)
{
	op_rotate_reverse(stack_b);
	ft_putstring("rrb\n");
}

void	op_rotate_reverse_r(t_list **stack_a, t_list **stack_b)
{
	op_rotate_reverse(stack_a);
	op_rotate_reverse(stack_b);
	ft_putstring("rrr\n");
}
