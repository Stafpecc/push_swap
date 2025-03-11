/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:27:47 by tarini            #+#    #+#             */
/*   Updated: 2025/03/11 14:32:09 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	radix_sort_pass(t_stack *stack_a, t_stack *stack_b, int bit,
	int size)
{
	int	j;
	int	pushed;

	pushed = 0;
	j = 0;
	while (j < size)
	{
		if (!((stack_a->top->index >> bit) & 1))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		j++;
	}
	while (pushed--)
		pa(stack_a, stack_b);
}

static void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;

	if (sorted(stack_a))
		return ;
	max_bits = find_bits(find_biggest(stack_a));
	size = count_nodes(stack_a);
	i = 0;
	while (i < max_bits)
	{
		radix_sort_pass(stack_a, stack_b, i, size);
		if (sorted(stack_a))
			break ;
		i++;
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = count_nodes(stack_a);
	if (!sorted(stack_a) && size <= 2)
		sort_two(stack_a);
	else if (!sorted(stack_a) && size <= 3)
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
