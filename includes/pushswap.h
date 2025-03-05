/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:01:26 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 19:26:33 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ███████  ██    ██ ███████ ██   ██      ███████ ██     ██  █████  ██████  
// ██    ██ ██    ██ ██      ██   ██      ██      ██     ██ ██   ██ ██   ██ 
// ███████  ██    ██ █████   ███████      █████   ██  █  ██ ███████ ██████  
// ██       ██    ██      ██ ██   ██           ██ ██ ███ ██ ██   ██ ██
// ██        ██████  ███████ ██   ██      ███████  ███ ███  ██   ██ ██

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

/* ************************************************************************** */
/*                              ROTATE REVERSE                                */
/* ************************************************************************** */

int		reverse_rotate(t_stack *stack);
int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                                 SWAP                                       */
/* ************************************************************************** */

int		swap(t_stack *stack);
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                                ROTATE                                      */
/* ************************************************************************** */

int		rotate(t_stack *stack);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                                 PUSH                                       */
/* ************************************************************************** */

int		push(t_stack *stack_1, t_stack *stack_2);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                               VALIDATION                                   */
/* ************************************************************************** */

int		validate_argument(char *arg);
int		has_duplicates(int argc, char **argv);

/* ************************************************************************** */
/*                               STACK UTILS                                  */
/* ************************************************************************** */

t_stack	*create_stack(void);
int		peek(t_stack *stack);
int		is_empty(t_stack *stack);
void	free_stack(t_stack *stack);
int		create_elements(t_stack *stack, int value);

/* ************************************************************************** */
/*                               SORTING                                      */
/* ************************************************************************** */

void	sort_stack(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                            SORTING UTILS                                   */
/* ************************************************************************** */

int		find_biggest(t_stack *stack);
int		count_nodes(t_stack *stack);
int		find_bits(int biggest);
int		sorted(t_stack *stack);
int		array_index(t_stack *stack);

#endif
