/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:10:45 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 15:09:58 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int printf_ret(void)
{
    ft_printf("Error\n");
    return (EXIT_FAILURE);	
}

int main(int argc, char **argv)
{
    int i;
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (printf_ret());
    stack_a = create_stack();
    if (!stack_a)
        return (printf_ret());
    stack_b = create_stack();
    if (!stack_b)
    {
        free_stack(stack_a);
        return (printf_ret());
    }
    i = 1;
    while (i < argc)
    {
        if (validate_argument(argv[i]) == EXIT_FAILURE
            || has_duplicates(argc, argv))
        {
            free_stack(stack_a);
            return (printf_ret());
        }
        create_elements(stack_a, ft_atoi(argv[i]));
        i++;
    }
    radix_sort(stack_a, stack_b, argc - 1);
    free_stack(stack_a);
    free_stack(stack_b);
    return (EXIT_SUCCESS);
}
