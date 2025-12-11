/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:21:58 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 18:51:18 by aymel-ha         ###   ########.fr       */
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
int analyse_string(char *str)
{
    int i = 0;
    while(str[i])
    {
        if((!ft_isdigit(str[i]) && !ft_isspace(str[i])))
            return -42;
        i++;
    }
    return 1;
}

