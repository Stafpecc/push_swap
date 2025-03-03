/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:27:47 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 19:28:08 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int get_max_bits(t_stack *stack)
{
    int max = peek(stack);
    int bits = 0;
    t_node *current = stack->top;
    
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

void radix_sort(t_stack *stack, int size)
{
    int max_bits = get_max_bits(stack);
    int i, j, num;
    t_stack *stack_b = create_stack();
    
    for (i = 0; i < max_bits; i++)
    {
        int count = size;
        while (count--)
        {
            num = peek(stack);
            if ((num >> i) & 1)
                rotate(stack);
            else
                push(stack_b, pop(stack));
        }
        while (!is_empty(stack_b))
            push(stack, pop(stack_b));
    }
    free_stack(stack_b);
}