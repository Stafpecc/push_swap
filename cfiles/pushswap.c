/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:10:45 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 19:28:21 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int printf_ret(void)
{
    ft_printf("Error\n");
    return (EXIT_FAILURE);	
}

int main(int argc, char **argv)
{
    int i;
    t_stack *stack;

    if (argc < 2)
        return (printf("Error\n"), EXIT_FAILURE);

    stack = create_stack();
    if (!stack)
        return (printf("Error\n"), EXIT_FAILURE);
    
    for (i = 1; i < argc; i++)
    {
        if (validate_argument(argv[i]) == EXIT_FAILURE || has_duplicates(argc, argv))
            return (free_stack(stack), printf("Error\n"), EXIT_FAILURE);
        push(stack, ft_atoi(argv[i]));
    }
    radix_sort(stack, argc - 1);
    
    free_stack(stack);
    return EXIT_SUCCESS;
}
