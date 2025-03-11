/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:11:37 by tarini            #+#    #+#             */
/*   Updated: 2025/03/11 14:14:57 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack->top || !stack->top->next || !stack->top->next->next)
		return ;
	first = stack->top->index;
	second = stack->top->next->index;
	third = stack->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third && first > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	while (count_nodes(stack_a) > 3)
	{
		while (stack_a->top->index != 0)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_0;
	int	pos_1;
	int	min_pos;

	while (count_nodes(stack_a) > 3)
	{
		pos_0 = find_position(stack_a, 0);
		pos_1 = find_position(stack_a, 1);
		if (pos_0 < pos_1)
			min_pos = pos_0;
		else
			min_pos = pos_1;
		while (stack_a->top->index != 0 && stack_a->top->index != 1)
		{
			if (min_pos <= count_nodes(stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
}
