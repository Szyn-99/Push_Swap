/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/16 22:53:41 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

char	*concatenated_string(char *av[])
{
	int		i;
	char	*le_string;
	int		argument_status;

	i = 1;
	le_string = NULL;
	while (av[i] != NULL)
	{
		argument_status = analyse_string(av[i]);
		if (argument_status == 1)
		{
			le_string = ft_strjoin(le_string, av[i]);
			if (!le_string)
				return (NULL);
		}
		else if (argument_status == 0)
		{
			if (le_string)
				free(le_string);
			return (NULL);
		}
		i++;
	}
	return (le_string);
}

int	control_edge_cases(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
	{
		sort_three_and_two_numbers(stack_a);
		return (1);
	}
	else if (size <= 5)
	{
		sort_five_numbers(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*concat;

	if (!(ac >= 2))
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	concat = concatenated_string(av);
	if (!concat)
		return (ft_putstring_fd("Error\n", 2), 1);
	initialise_list(&stack_a, concat);
	if (!stack_a)
		return (free(concat), ft_putstring_fd("Error\n", 2), 1);
	if (control_edge_cases(&stack_a, &stack_b))
		return (free(concat), ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
	init_index(&stack_a);
	chunks_sort(&stack_a, &stack_b);
	return (free(concat), ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
