/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:10:45 by tarini            #+#    #+#             */
/*   Updated: 2025/03/10 16:58:02 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (initialize_stacks_and_fill(argc, argv, &stack_a, &stack_b)
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	sort_stack(stack_a, stack_b);
	return (ret_free_success(stack_a, stack_b));
}
