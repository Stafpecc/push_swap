/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:01:26 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 15:09:48 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
} t_stack;


int reverse_rotate(t_stack *stack);
int rra(t_stack *stack);
int rrb(t_stack *stack);
int rrr(t_stack *stack_a, t_stack *stack_b);

int swap(t_stack *stack);
int sa(t_stack *stack);
int sb(t_stack *stack);
int ss(t_stack *stack_a, t_stack *stack_b);

int rotate(t_stack *stack);
int ra(t_stack *stack);
int rb(t_stack *stack);
int rr(t_stack *stack_a, t_stack *stack_b);

int push(t_stack *stack_1, t_stack *stack_2);
int pa(t_stack *stack_a, t_stack *stack_b);
int pb(t_stack *stack_a, t_stack *stack_b);

int validate_argument(char *arg);
int has_duplicates(int argc, char **argv);

t_stack *create_stack();
int peek(t_stack *stack);
int is_empty(t_stack *stack);
void free_stack(t_stack *stack);
int create_elements(t_stack *stack, int value);

void radix_sort(t_stack *stack_a, t_stack *stack_b, int size);

#endif