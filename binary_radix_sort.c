/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:19:14 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/12 12:19:40 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	binary_radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_bss	radix;
	int		bit_max;
	int		index_max;

	radix.size = ft_lstsize(*stack_a);
	radix.bits_to_shift = 0;
	bit_max = 0;
	index_max = radix.size - 1;
	while ((index_max >> bit_max) != 0)
		bit_max++;
	while (radix.bits_to_shift < bit_max)
	{
		radix.i = 0;
		while (radix.i < radix.size)
		{
			if ((((*stack_a)->value_index >> radix.bits_to_shift) & 1) == 0)
				op_push_b(stack_b, stack_a);
			else
				op_rotate_a(stack_a);
			radix.i++;
		}
		while (*stack_b)
			op_push_a(stack_a, stack_b);
		radix.bits_to_shift++;
	}
}
