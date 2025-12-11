/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:25:32 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 23:51:20 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rotate_reverse(t_list **stack)
{
    if(!stack || !*stack || !(*stack)->next)
        return ;
    t_list *first_node = NULL;
    t_list *last_node = NULL;
    t_list *before_last_node = NULL;
    
    before_last_node = *stack;
    while(before_last_node->next-e)
        before_last_node = before_last_node->next;
    before_last_node= NULL;
    last_node = ft_lstlast(*stack);
    first_node = *stack;
    *stack = last_node;
    last_node->next = first_node;
}



void op_rotate_reverse_a(t_list **stack_a)
{
    op_rotate_reverse(stack_a);
    ft_putstring("ra\n");
}
void op_rotate_reverse_b(t_list **stack_b)
{
    op_rotate_reverse(stack_b);
    ft_putstring("rb\n");
}
void op_rotate_reverse_r(t_list **stack_a, t_list **stack_b)
{
    op_rotate_reverse(stack_a);
    op_rotate_reverse(stack_b);
    ft_putstring("rr\n");
}