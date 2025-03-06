/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:10:45 by tarini            #+#    #+#             */
/*   Updated: 2025/03/06 15:06:49 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	printf_ret(void)
{
	ft_printf("Error\n");
	return (EXIT_FAILURE);
}

static int	printf_ret_free_all_stack(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (printf_ret());
}

static int	printf_ret_free_stack_a(t_stack *stack_a)
{
	free_stack(stack_a);
	free(stack_a);
	return (printf_ret());
}

static int	ret_free_success(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (printf_ret());
	if (initialize_stacks_and_fill(argc, argv, &stack_a, &stack_b)
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	sort_stack(stack_a, stack_b);
	return (ret_free_success(stack_a, stack_b));
}
