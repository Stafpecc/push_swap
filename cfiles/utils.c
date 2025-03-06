/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:55:13 by tarini            #+#    #+#             */
/*   Updated: 2025/03/06 15:23:50 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_biggest(t_stack *stack)
{
	int		big;
	t_node	*tmp;

	big = (-__INT_MAX__ - 1);
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value > big)
			big = tmp->value;
		tmp = tmp->next;
	}
	return (big);
}

int	find_bits(int biggest_nbr)
{
	int				max_bits;
	unsigned int	nbr;

	max_bits = 0;
	nbr = (unsigned int)biggest_nbr;
	while (nbr > 0)
	{
		nbr >>= 1;
		max_bits++;
	}
	return (max_bits + 1);
}

int	count_nodes(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
