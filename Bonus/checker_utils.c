/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:17:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/20 01:50:38 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_string_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	grade_operations(t_list *stack)
{
	t_list	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value_raw > current->next->value_raw)
			return (0);
		current = current->next;
	}
	return (1);
}

int	operations_executor(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_string_cmp(operation, "sa\n") == 0)
		return (op_swap_a(stack_a, 0x539), 1);
	else if (ft_string_cmp(operation, "sb\n") == 0)
		return (op_swap_b(stack_b, 0x539), 1);
	else if (ft_string_cmp(operation, "ss\n") == 0)
		return (op_swap_ss(stack_a, stack_b, 0x539), 1);
	else if (ft_string_cmp(operation, "pa\n") == 0)
		return (op_push_a(stack_a, stack_b, 0x539), 1);
	else if (ft_string_cmp(operation, "pb\n") == 0)
		return (op_push_b(stack_b, stack_a, 0x539), 1);
	else if (ft_string_cmp(operation, "ra\n") == 0)
		return (op_rotate_a(stack_a, 0x539), 1);
	else if (ft_string_cmp(operation, "rb\n") == 0)
		return (op_rotate_b(stack_b, 0x539), 1);
	else if (ft_string_cmp(operation, "rr\n") == 0)
		return (op_rotate_rr(stack_a, stack_b, 0x539), 1);
	else if (ft_string_cmp(operation, "rra\n") == 0)
		return (op_rotate_reverse_a(stack_a, 0x539), 1);
	else if (ft_string_cmp(operation, "rrb\n") == 0)
		return (op_rotate_reverse_b(stack_b, 0x539), 1);
	else if (ft_string_cmp(operation, "rrr\n") == 0)
		return (op_rotate_reverse_r(stack_a, stack_b, 0x539), 1);
	return (0);
}
