/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 20:32:32 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*copy;
	char	*concat;

	// if(!(ac >= 2))
	//     return (ft_putstring("nothing to do"), 0);
	i = 0;
	stack_a = NULL;
	copy = NULL;
	concat = NULL;
	while (av[i] != NULL)
	{
		if (analyse_string(av[i]) == 1)
		{
			concat = ft_strjoin(concat, av[i]);
			if (!concat)
				return (0);
		}
		i++;
	}
	initialise_list(&stack_a, concat);
	init_index(stack_a);
	copy = stack_a;
	while (stack_a)
	{
		printf("value -> %d\nindex -> %d\n", stack_a->value_raw,
			stack_a->value_index);
		stack_a = stack_a->next;
	}
	free(concat);
	ft_lstclear(&copy);
}
