/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:01:26 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 16:17:45 by tarini           ###   ########.fr       */
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

/**
 * @brief Pushes a value onto the stack.
 * 
 * @param stack A pointer to the stack.
 * @param value The value to be pushed onto the stack.
 */
int push(t_stack *stack, int value);

/**
 * @brief Pops a value from the stack.
 * 
 * @param stack A pointer to the stack.
 * @return The value popped from the stack.
 */
int pop(t_stack *stack);

/**
 * @brief Swaps the top two elements of the stack.
 * 
 * @param stack A pointer to the stack.
 */
int swap(t_stack *stack);

/**
 * @brief Rotates the stack upwards.
 * 
 * The top element becomes the bottom element.
 * 
 * @param stack A pointer to the stack.
 */
int rotate(t_stack *stack);

/**
 * @brief Rotates the stack downwards.
 * 
 * The bottom element becomes the top element.
 * 
 * @param stack A pointer to the stack.
 */
int reverse_rotate(t_stack *stack);

/**
 * @brief Sorts the stack.
 * 
 * @param stack A pointer to the stack.
 */
int sort_stack(t_stack *stack);

t_stack *create_stack();
void free_stack(t_stack *stack);
int peek(t_stack *stack);
int is_empty(t_stack *stack);


#endif