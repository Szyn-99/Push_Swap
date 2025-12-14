/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szyn <szyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:21:58 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/14 23:02:28 by szyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if ((9 <= c && c <= 13) || c == 32)
	{
		return (1);
	}
	return (0);
}

int	analyse_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
			i++;
		}
		else if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int duplicate_detector(int array[], int list_size)
{
	int i = 0;
	
	while (i < list_size - 1)
	{
		if (array[i] == array[i + 1])
		{
			write(2, "Duplicate Detected :(\n", 23);
			free(array);
			return 0;
		}
		i++;
	}
	return 1;
}
