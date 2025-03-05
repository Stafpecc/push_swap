/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:27:21 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 14:41:00 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int swap(t_stack *stack)
{
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
    return (EXIT_SUCCESS);
}

int sa(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (swap(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("sa\n");
	return (EXIT_SUCCESS);
}

int sb(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (swap(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("sb\n");
	return (EXIT_SUCCESS);
}

int ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next || !stack_b ||
		!stack_b->top || !stack_b->top->next)
		return (EXIT_FAILURE);
	if (swap(stack_a) == EXIT_FAILURE || swap(stack_b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("ss\n");
	return (EXIT_SUCCESS);
}