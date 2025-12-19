/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:37:12 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/20 00:02:33 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_push(t_list **stack_d, t_list **stack_s)
{
	t_list	*tmp;

	if (!stack_s || !*stack_s)
		return ;
	tmp = (*stack_s)->next;
	(*stack_s)->next = *stack_d;
	*stack_d = *stack_s;
	*stack_s = tmp;
}

void	op_push_a(t_list **stack_a, t_list **stack_b, int bonus_check)
{
	op_push(stack_a, stack_b);
	if (bonus_check == 0x539)
		return ;
	ft_putstring_fd("pa\n", 1);
}

void	op_push_b(t_list **stack_b, t_list **stack_a, int bonus_check)
{
	op_push(stack_b, stack_a);
	if (bonus_check == 0x539)
		return ;
	ft_putstring_fd("pb\n", 1);
}
