/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:25 by tarini            #+#    #+#             */
/*   Updated: 2025/03/06 15:24:42 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	printf_ret(void)
{
	ft_printf("Error\n");
	return (EXIT_FAILURE);
}

int	printf_ret_free_all_stack(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (printf_ret());
}

int	printf_ret_free_stack_a(t_stack *stack_a)
{
	free_stack(stack_a);
	free(stack_a);
	return (printf_ret());
}

int	ret_free_success(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (EXIT_SUCCESS);
}