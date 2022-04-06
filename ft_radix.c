/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_radix.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/01 14:18:45 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/06 09:52:39 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <unistd.h>

static int	*ft_clean_stack_b(int argc, int *stack_b, int *stack_mapped)
{
	while (stack_b[0] != 2147483647)
	{
		ft_pb(argc, stack_b, stack_mapped);
		write(1, "pa\n", 3);
	}
	return (stack_mapped);
}

static int	*ft_radix_sort(int argc, int *stack_m, int max_digit, int *stack_b)
{
	int	digit;
	int	i;
	int	div;
	int	reminder;

	digit = 1;
	while (digit <= max_digit)
	{
		div = ft_power(digit);
		i = 0;
		while (i < argc - 1)
		{
			reminder = stack_m[0] % div;
			if (reminder >= 0 && reminder <= ((div / 2) - 1))
				ft_pbp(argc, stack_m, stack_b);
			else
				ft_rap(argc, stack_m);
			i++;
		}
		stack_m = ft_clean_stack_b(argc, stack_b, stack_m);
		digit++;
	}
	return (stack_m);
}

int	*ft_radix(int argc, int *stack_a)
{
	int	*stack_digits;
	int	*stack_sorted;
	int	max_digit;
	int	*stack_b;

	stack_digits = ft_digits(argc, stack_a);
	max_digit = ft_find_max(argc, stack_digits);
	stack_b = ft_create_empty_stack(argc);
	stack_sorted = ft_radix_sort(argc, stack_a, max_digit, stack_b);
	free(stack_digits);
	free(stack_b);
	return (stack_sorted);
}
