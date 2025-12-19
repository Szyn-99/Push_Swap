/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:28:52 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/19 23:51:36 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	operations_processor(t_main *main)
{
	int		operation_status;
	int		operations_grade;
	char	*operations;

	while (1)
	{
		operations = get_next_line(0);
		if (operations == NULL)
			break ;
		operation_status = operations_executor(operations, &main->stack_a,
				&main->stack_b);
		if (operation_status == 0)
			return (ft_putstring_fd("Error\n", 2), free(operations),
				free(main->concat), ft_lstclear(&main->stack_a),
				ft_lstclear(&main->stack_b), 1337);
		free(operations);
	}
	operations_grade = grade_operations(main->stack_a);
	if (operations_grade == 1 && main->stack_b == NULL)
		ft_putstring_fd("OK\n", 1);
	else
		ft_putstring_fd("KO\n", 1);
	return (1);
}

void	thank_you_norminette(t_main *data, char *av[])
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->concat = concatenated_string(av);
}

int	main(int ac, char *av[])
{
	t_main	main;

	if (!(ac >= 2))
		return (1);
	thank_you_norminette(&main, av);
	if (!main.concat)
		return (ft_putstring_fd("Error\n", 2), 1);
	main.status = initialise_list(&main.stack_a, main.concat);
	if (main.status == 0 || main.status == 1337)
		return (ft_putstring_fd("Error\n", 2), free(main.concat),
			ft_lstclear(&main.stack_a), 1);
	main.status = init_index(&main.stack_a);
	if (main.status == 0)
		return (ft_putstring_fd("Error\n", 2), free(main.concat),
			ft_lstclear(&main.stack_a), 1);
	else if (main.status == 1337)
		return (free(main.concat), ft_lstclear(&main.stack_a), 0);
	if (!main.stack_a)
		return (free(main.concat), ft_putstring_fd("Error\n", 2), 1);
	if (operations_processor(&main) == 1337)
		return (1);
	return (ft_lstclear(&main.stack_a), free(main.concat), 0);
}
