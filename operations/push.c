/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:37:12 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 23:01:23 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_push(t_list **stack_d, t_list **stack_s)
{
    if(!stack_s ||!*stack_s)
        return;
    t_list *tmp = (*stack_s)->next;
    (*stack_s)->next = *stack_d;
    *stack_d = *stack_s;
    *stack_s = tmp;
}

void op_push_a(t_list **stack_a, t_list **stack_b)
{
    op_push(stack_a, stack_b);
    ft_putstring("pa\n");
}

void op_push_b(t_list **stack_b, t_list **stack_a)
{
    op_push(stack_b, stack_a);
    ft_putstring("pb\n");
}
