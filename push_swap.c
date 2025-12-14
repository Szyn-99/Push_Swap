/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szyn <szyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/14 22:56:57 by szyn             ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*concat;

	if (!(ac >= 2))
		return (ft_putstring("nothing to do"), 0);
	stack_a = NULL;
	stack_b = NULL;
	concat = concatenated_string(av);
	if (!concat)
		return (write(2, "Invalid Arguments\n", 19), 1);
	initialise_list(&stack_a, concat);
	if (!stack_a)
		return (free(concat), write(2, "Failed to Initiliase\n", 22), 1);
	init_index(&stack_a);
	t_list *copy;
	copy = stack_a;
	while(copy)
	{
		printf("value %d ------------ index %d\n", copy->value_raw, copy->value_index);
		copy = copy->next;
	}
	chunks_sort(&stack_a, &stack_b);
	copy  = stack_a;
	printf("===============================================================================================");
	while(copy)
	{
		printf("value %d ------------ index %d\n", copy->value_raw, copy->value_index);
		copy = copy->next;
	}
	free(concat);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
