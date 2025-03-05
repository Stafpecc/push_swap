/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:30:31 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 15:04:38 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int push(t_stack *stack_1, t_stack *stack_2)
{
    t_node *tmp;

    tmp = stack_1->top;
    stack_1->top = stack_1->top->next;
    tmp->next = stack_2->top;
    stack_2->top = tmp;
    return (EXIT_SUCCESS);
}

int pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (EXIT_FAILURE);
	if (push(stack_b, stack_a) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("pa\n");
	return (EXIT_SUCCESS);
}

int pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (EXIT_FAILURE);
	if (push(stack_a, stack_b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("pb\n");
	return (EXIT_SUCCESS);
}
