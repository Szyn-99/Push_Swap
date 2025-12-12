/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/12 12:17:18 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*copy;
	t_list *copy_b;
	char	*concat;

	if (!(ac >= 2))
		return (ft_putstring("nothing to do"), 0);
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	copy = NULL;
	concat = concatenated_string(av);
	if(!concat)
		printf("failed");
	
	
	initialise_list(&stack_a, concat);
	free(concat);
	init_index(stack_a);
	binary_radix_sort(&stack_a, &stack_b);
	copy_b = stack_b;
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);

}
