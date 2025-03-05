/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:27:47 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 19:46:56 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_three(t_stack *stack)
{
	int	biggest;

	biggest = find_biggest(stack);
	if (stack->top->index == biggest)
		ra(stack);
	else if (stack->top->next->index == biggest)
		ra(stack);
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = count_nodes(stack_a);
	while (size--)
	{
		if (stack_a->top->index == 0 || stack_a->top->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (stack_a->top->index > stack_a->top->next->index)
		sa(stack_a);
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
		while (stack_b->top)
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
	else if (!sorted(stack_a) && size <= 5)
		sort_five(stack_a, stack_b);
	else if (!sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
