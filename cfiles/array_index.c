/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:48:49 by tarini            #+#    #+#             */
/*   Updated: 2025/03/11 15:02:29 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_stack_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	current = stack->top;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

static void	sort_array(int *array, int size)
{
	int	swapped;
	int	j;
	int	temp;

	while (1)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
	}
}

static int	*create_sorted_array(t_stack *stack, int size)
{
	int		*array;
	t_node	*current;
	int		i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
	sort_array(array, size);
	return (array);
}

static void	assign_indices(t_stack *stack, int *array, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

int	array_index(t_stack *stack)
{
	int	size;
	int	*array;

	size = get_stack_size(stack);
	array = create_sorted_array(stack, size);
	if (!array)
		return (EXIT_FAILURE);
	assign_indices(stack, array, size);
	free(array);
	return (EXIT_SUCCESS);
}
