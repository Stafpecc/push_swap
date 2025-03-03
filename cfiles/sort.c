/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:45:33 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 16:03:37 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_stack *create_stack()
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->bottom = NULL;
    return stack;
}

int peek(t_stack *stack)
{
    if (!stack->top)
        return (INT_MIN);
    return (stack->top->value);
}

int is_empty(t_stack *stack)
{
    return stack->top == NULL;
}

void free_stack(t_stack *stack)
{
    while (!is_empty(stack))
        pop(stack);
    free(stack);
}