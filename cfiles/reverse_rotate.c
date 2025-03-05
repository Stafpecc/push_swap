/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:41:43 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 14:43:51 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int rra(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (reverse_rotate(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rra\n");
	return (EXIT_SUCCESS);
}

int rrb(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (reverse_rotate(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rrb\n");
	return (EXIT_SUCCESS);
}

int rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next || !stack_b
		|| !stack_b->top || !stack_b->top->next)
		return (EXIT_FAILURE);
	if (reverse_rotate(stack_a) == EXIT_FAILURE || reverse_rotate(stack_b)
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rrr\n");
	return (EXIT_SUCCESS);
}
