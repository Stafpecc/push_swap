/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:27:47 by tarini            #+#    #+#             */
/*   Updated: 2025/03/06 14:46:27 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	stack->bottom = first;
	return (EXIT_SUCCESS);
}

int	ra(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (rotate(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("ra\n");
	return (EXIT_SUCCESS);
}

int	rb(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (EXIT_FAILURE);
	if (rotate(stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rb\n");
	return (EXIT_SUCCESS);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next || !stack_b
		|| !stack_b->top || !stack_b->top->next)
		return (EXIT_FAILURE);
	if (rotate(stack_a) == EXIT_FAILURE || rotate(stack_b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("rr\n");
	return (EXIT_SUCCESS);
}
