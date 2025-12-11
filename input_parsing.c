/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:21:58 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 17:27:48 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int analyse_string(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(!ft_isdigit(str[i]) || !ft_isspace(str[i]))
            return 0;
        i++;
    }
    return 1;
}

