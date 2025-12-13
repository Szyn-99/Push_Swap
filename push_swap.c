/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szyn <szyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/13 19:29:10 by szyn             ###   ########.fr       */
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
		i++;
	}
	return (le_string);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*concat;
	int		size;

	if (!(ac >= 2))
		return (ft_putstring("nothing to do"), 0);
	stack_a = NULL;
	stack_b = NULL;
	concat = concatenated_string(av);
	if (!concat)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	initialise_list(&stack_a, concat);
	/* initialise_list doesn't free concat on error; caller frees it */
	if (!stack_a)
	{
		free(concat);
		write(2, "Error\n", 6);
		return (1);
	}
	/* set indices (and detect duplicates inside init_index) */
	init_index(&stack_a);
	size = ft_lstsize(stack_a);
	
	if (size > 500)
		binary_radix_sort(&stack_a, &stack_b);
	else
		chunks_sort(&stack_a, &stack_b);
	free(concat);
	while(stack_a)
	{
		printf("raw value = %d\nindex value = %d\n", stack_a->value_raw, stack_a->value_index);
		stack_a = stack_a->next;
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
