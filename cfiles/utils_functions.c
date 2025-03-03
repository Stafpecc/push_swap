/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:05:43 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 16:02:57 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int push(t_stack *stack, int value)
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

int pop(t_stack *stack)
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

int swap(t_stack *stack)
{
    if (!stack || !stack->top || !stack->top->next)
        return (EXIT_FAILURE);
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
    return (EXIT_SUCCESS);
}

int rotate(t_stack *stack)
{
    if (!stack || !stack->top || !stack->top->next)
        return (EXIT_FAILURE);
    t_node *first = stack->top;
    t_node *last = stack->top;
    while (last->next)
        last = last->next;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
    stack->bottom = first;
    return (EXIT_SUCCESS);
}

int reverse_rotate(t_stack *stack)
{
    if (!stack || !stack->top || !stack->top->next)
        return (EXIT_FAILURE);
    t_node *prev = NULL;
    t_node *current = stack->top;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    current->next = stack->top;
    stack->top = current;
    prev->next = NULL;
    stack->bottom = prev;
    return (EXIT_SUCCESS);
}