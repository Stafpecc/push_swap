/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:27:47 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 15:10:58 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int get_max_bits(t_stack *stack)
{
    int max;
    int bits = 0;
    t_node *current;
    
    max = peek(stack);
    current = stack->top;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void radix_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
    int max_bits;
    int i;
    int num;
    int count;
    
    max_bits = get_max_bits(stack_a);
    i = 0;
    while (i < max_bits)
    {
        count = size;
        while (count--)
        {
            num = peek(stack_a);
            if ((num >> i) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (!is_empty(stack_b))
            pa(stack_a, stack_b);
        i++;
    }
    free_stack(stack_b);
}