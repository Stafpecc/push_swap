/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:55:13 by tarini            #+#    #+#             */
/*   Updated: 2025/03/06 15:07:33 by tarini           ###   ########.fr       */
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

int	initialize_stacks_and_fill(int argc, char **argv, t_stack **stack_a,
	t_stack **stack_b)
{
	int	i;
	int	error;

	error = 0;
	*stack_a = create_stack();
	if (!*stack_a)
		return (printf_ret());
	*stack_b = create_stack();
	if (!*stack_b)
		return (printf_ret_free_stack_a(*stack_a));
	i = argc - 1;
	while (i > 0)
	{
		if (validate_argument(argv[i]) == EXIT_FAILURE
			|| has_duplicates(argc, argv)
			|| create_elements(*stack_a, ft_atoi_overflow(argv[i], &error))
			== EXIT_FAILURE
			|| error == EXIT_FAILURE)
			return (printf_ret_free_all_stack(*stack_a, *stack_b));
		i--;
	}
	if (array_index(*stack_a) == EXIT_FAILURE)
		return (printf_ret_free_all_stack(*stack_a, *stack_b));
	return (EXIT_SUCCESS);
}
