/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:13:01 by tarini            #+#    #+#             */
/*   Updated: 2025/03/06 14:46:57 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	prev = NULL;
	current = stack->top;
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

int	rra(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (reverse_rotate(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rra\n");
	return (EXIT_SUCCESS);
}

int	rrb(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (reverse_rotate(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rrb\n");
	return (EXIT_SUCCESS);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
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

// int smart_rotate(t_stack *stack_a, t_stack *stack_b)
// {
// 	//rotate ou reverse rotate 
// }