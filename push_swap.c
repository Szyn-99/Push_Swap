/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:06 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 19:27:47 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char *av[])
{
    // if(!(ac >= 2))
    //     return ft_putstring("nothing to do"), 0;
    int i = 0;
    t_list *stack_a = NULL;
    char *concat = NULL;
    while(av[i] != NULL)
    {
        if(analyse_string(av[i]) == 1)
        {
            concat = ft_strjoin(concat, av[i]);
            if(!concat)
                return 0;
        }
        i++;
    }
    initialise_list(&stack_a,concat);
    init_index(stack_a);
    while(stack_a)
    {
        printf("list -> %d\n", stack_a->value_raw);
        stack_a = stack_a->next;
    }
    
    free(concat);
    ft_lstclear(&stack_a);
}