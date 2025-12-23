/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/23 14:07:35 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	thank_you_norminette(t_main *data, char *av[])
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->concat = concatenated_string(av);
}

int	half_main(t_main *main)
{
	if (main->status == 0)
		return (ft_putstring_fd("Error\n", 2), free(main->concat),
			ft_lstclear(&main->stack_a), 1);
	else if (main->status == 1337)
		return (free(main->concat), ft_lstclear(&main->stack_a), 0);
	else if (main->status == 99)
		return (sorting_ra(&main->stack_a), free(main->concat),
			ft_lstclear(&main->stack_a), 0);
	if (!main->stack_a)
		return (free(main->concat), ft_putstring_fd("Error\n", 2), 1);
	if (control_edge_cases(&main->stack_a, &main->stack_b))
		return (free(main->concat), ft_lstclear(&main->stack_a), 0);
	chunks_sort(&main->stack_a, &main->stack_b);
	return (1);
}

int	main(int ac, char *av[])
{
	t_main	main;

	if (!(ac >= 2))
		return (1);
	thank_you_norminette(&main, av);
	if (main.concat == NULL)
		return (ft_putstring_fd("Error\n", 2), 1);
	main.status = initialise_list(&main.stack_a, main.concat);
	if (main.status == 0)
		return (ft_putstring_fd("Error\n", 2), free(main.concat),
			ft_lstclear(&main.stack_a), 1);
	main.status = init_index(&main.stack_a);
	return (half_main(&main));
}
