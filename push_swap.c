/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/12 00:05:46 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*concatenated_string(char *av[])
{
	int		i;
	char	*le_string;
	int		argument_status;

	i = 0;
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
		else
			return (NULL);
		i++;
	}
	return (le_string);
}

int	main(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*copy;
	char	*concat;

	if (!(ac >= 2))
		return (ft_putstring("nothing to do"), 0);
	i = 0;
	stack_a = NULL;
	copy = NULL;
	concat = concatenated_string(av);
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
