#include "push_swap.h"


int max_index(t_list *stack)
{
    int max = 0;
    while(stack)
    {
        if(stack->value_index >= max)
            max = stack->value_index;
        stack = stack->next;
    }
    return max;
}

int find_max_position(t_list *stack, int max)
{
    int position = 0;
    while(stack)
    {
        if(stack->value_index == max)
            return position;
        position++;
        stack = stack->next;
    }
    return -1;
}

void chunks_(t_list **stack_a, t_list **stack_b)
{
    t_ChS hunk;
    hunk.size = ft_lstsize(*stack_a);
    if(hunk.size <= 100)
        hunk.end = 13;
    else if (hunk.size <= 500)
        hunk.end = 37;
    else
        hunk.end = 42;
    hunk.start = 0;
    hunk.end = hunk.end - 1;

    while(*stack_a)
    {
        if((*stack_a)->value_index < hunk.start)
        {
            op_push_b(stack_b, stack_a);
            op_rotate_b(stack_b);
            hunk.start++;
        }
        else if((*stack_a)->value_index >= hunk.start && (*stack_a)->value_index <= hunk.end)
        {
            op_push_b(stack_b, stack_a);
            hunk.start++;
            hunk.end++;
        }
        else
            op_rotate_a(stack_a);
    }

    while(*stack_b)
    {
        hunk.size_now = ft_lstsize(*stack_b);
        hunk.max_index = max_index(*stack_b);
        hunk.position = find_max_position(*stack_b, hunk.max_index);
        if(hunk.position < hunk.size_now / 2)
        {
            while((*stack_b)->value_index != hunk.max_index)
                op_rotate_b(stack_b);
        }
        else
        {
            while((*stack_b)->value_index != hunk.max_index)
                op_rotate_reverse_b(stack_b);
        }
        op_push_a(stack_a, stack_b);
    }
    
}