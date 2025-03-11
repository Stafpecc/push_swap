/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:45:33 by tarini            #+#    #+#             */
/*   Updated: 2025/03/11 15:03:23 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

int	create_elements(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (EXIT_FAILURE);
	new_node->value = value;
	new_node->next = stack->top;
	if (array_index(stack) == EXIT_FAILURE)
	{
		free(new_node);
		return (EXIT_FAILURE);
	}
	stack->top = new_node;
	if (!stack->bottom)
		stack->bottom = new_node;
	return (EXIT_SUCCESS);
}

int	peek(t_stack *stack)
{
	if (!stack->top)
		return ((-__INT_MAX__ - 1));
	return (stack->top->value);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (stack == NULL)
		return ;
	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL;
}
