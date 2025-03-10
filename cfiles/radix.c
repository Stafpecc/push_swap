/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:27:47 by tarini            #+#    #+#             */
/*   Updated: 2025/03/10 17:13:52 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_three(t_stack *stack)
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

static void	sort_four(t_stack *stack_a, t_stack *stack_b)
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

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
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

static void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	biggest_nbr;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	biggest_nbr = find_biggest(stack_a);
	max_bits = find_bits(biggest_nbr);
	size = count_nodes(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->top->index >> i) & 1))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b && stack_b->top)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = count_nodes(stack_a);
	if (!sorted(stack_a) && size <= 3)
		sort_three(stack_a);
	else if (!sorted(stack_a) && size <= 4)
		sort_four(stack_a, stack_b);
	else if (!sorted(stack_a) && size <= 5)
	{
		sort_five(stack_a, stack_b);
		if (stack_b->top && stack_b->top->next && stack_b->top->index
			< stack_b->top->next->index)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (!sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
