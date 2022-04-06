/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapping.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 10:41:18 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/06 09:50:09 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_power(int digit)
{
	int	result;
	int	i;

	i = 1;
	result = 2;
	while (i < digit)
	{
		result = 2 * result;
		i++;
	}
	return (result);
}

int	*ft_digits(int argc, int *stack)
{
	int	i;
	int	j;
	int	*stack_digits;

	i = 0;
	stack_digits = ft_create_empty_stack(argc);
	while (i < argc - 1)
	{
		j = 1;
		while (ft_power(j) <= stack[i])
			j++;
		stack_digits[i] = j;
		i++;
	}
	return (stack_digits);
}

int	ft_find_max(int argc, int *stack)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 1;
	max = stack[0];
	while (i < argc - 2)
	{
		while (j < argc - 1)
		{
			if (stack[j] > stack[i])
			{
				max = stack[j];
				i = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}
