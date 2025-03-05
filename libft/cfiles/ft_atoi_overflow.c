/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:25 by tarini            #+#    #+#             */
/*   Updated: 2025/03/05 19:46:13 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(const char *str, int sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (sign);
}

int	ret_error(int *error)
{
	*error = 1;
	return (0);
}

int	ft_atoi_overflow(const char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = ft_sign(str, sign);
	while (*str >= '0' && *str <= '9')
	{
		if (result > (INT_MAX - (*str - '0')) / 10)
			return (ret_error(error));
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < (-__INT_MAX__ - 1))
		return (ret_error(error));
	return ((int)result);
}
