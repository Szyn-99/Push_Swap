/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:21:58 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/22 17:03:26 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_isspace(int c)
{
	if ((10 <= c && c <= 13) || c == 32)
	{
		return (1);
	}
	return (0);
}

int	all_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	analyse_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0' || all_is_space(str))
		return (0);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (!str[i + 1] || !ft_isdigit(str[i + 1]) || (i > 0
					&& !ft_isspace(str[i - 1])))
				return (0);
			i++;
		}
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			return (0);
	}
	return (1);
}

int	duplicate_detector(int array[], int list_size, t_list **stack_a)
{
	int	i;

	i = 0;
	while (i < list_size - 1)
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			ft_lstclear(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}
