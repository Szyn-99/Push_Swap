/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:50:51 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 22:20:51 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlength(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstring(char *s)
{
	write(1, &s, ft_strlength(s));
}

char	*ft_strdup(char *s)
{
	size_t	size;
	size_t	i;
	char	*dup;

	size = ft_strlength(s);
	i = 0;
	dup = (char *)malloc(size + 1);
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return ((ft_strdup(s1)));
	result = (char *)malloc(ft_strlength(s1) + ft_strlength(s2) + 2);
	i = -1;
	if (!result)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	result[i++] = ' ';
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (free(s1), result);
}
