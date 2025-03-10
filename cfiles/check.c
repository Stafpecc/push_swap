/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:28:22 by tarini            #+#    #+#             */
/*   Updated: 2025/03/10 16:56:37 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	validate_argument(char *arg)
{
	int		j;
	long	num;
	int		error;

	error = 0;
	j = 0;
	if (arg[j] == '-' || arg[j] == '+')
		j++;
	if (arg[j] == '\0')
		return (EXIT_FAILURE);
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			return (EXIT_FAILURE);
		j++;
	}
	num = ft_atoi_overflow(arg, &error);
	return (error);
}

int	has_duplicates(int argc, char **argv)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 1;
	while (i < argc)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
