/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:45:33 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 15:10:51 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int pop(t_stack *stack)
{
    if (!stack || !stack->top)
        return (EXIT_FAILURE);
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = stack->top->next;
    if (!stack->top)
        stack->bottom = NULL;
    free(temp);
    return (value);
}

t_stack *create_stack()
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->bottom = NULL;
    return stack;
}

int create_elements(t_stack *stack, int value)
{
    t_node *new_node;
    
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (EXIT_FAILURE);
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    if (!stack->bottom)
        stack->bottom = new_node;
    return (EXIT_SUCCESS);
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