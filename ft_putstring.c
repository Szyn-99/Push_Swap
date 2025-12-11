/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:40:48 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 16:43:00 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlength(char *s)
{
    size_t i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void ft_putstring(char *s)
{
    write(1, &s , ft_strlength(s));
}