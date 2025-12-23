/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:16:49 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/23 13:44:07 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_ra(t_list **stack_a)
{
	int	s_list;
	int	i;

	s_list = ft_lstsize(*stack_a);
	i = 0;
	while (i < s_list)
	{
		op_rotate_a(stack_a, 9);
		i++;
	}
}
