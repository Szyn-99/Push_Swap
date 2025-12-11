/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:11:37 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 19:26:40 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_strings(char **str)
{
    int i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void initialise_list(t_list **stack_a, char *concat)
{
    char **raw_values = ft_split(concat, ' ');
    if(!raw_values)
        return ;
    int i = 0;
    int raw_val_n;
    t_list *node;
    while(raw_values[i] != NULL)
    {
        raw_val_n = ft_atoi(raw_values[i]);
        node = ft_lstnew(raw_val_n);
        if(!node)
        {
            clear_strings(raw_values);
            ft_lstclear(stack_a);
            return ;
        }
        ft_lstadd_back(stack_a, node);
        i++;
    }

    clear_strings(raw_values);
}
void generate_index_util(int *array, int size)
{
    int x = 0;
    int y;
    int n;
    while(x < size-1)
    {
        y = 0;
        while(y < size-1)
        {
            if(array[y] > array[y+1])
            {
                n = array[y];
                array[y] = array[y+1];
                array[y+1] = n;
            }
            y++;
        }
        x++;
    }
}

void init_index(t_list *stack_a)
{
    // t_list **copy = stack_a;
    int list_size = ft_lstsize(stack_a);
    int i = 0;
    int array[list_size];
    while(i < list_size)
    {
        array[i] = stack_a->value_raw;
        stack_a = stack_a->next;
        i++;
    }

    generate_index_util(array, list_size);
    i = 0;
    while(i < list_size)
    {
        printf("arra -> %d\n", array[i]);
        i++;
    }
}