/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_operations.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 11:39:09 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/04 10:51:15 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_rb(int argc, int *stack)
{
	int	temp;
	int	i;
	int	real_size;

	real_size = ft_real_size(argc, stack);
	temp = stack[0];
	i = 0;
	while (i < real_size - 1 && stack[i + 1] != 2147483647)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	return (stack);
}

int	ft_real_size(int argc, int *stack)
{
	int	i;

	i = 0;
	while (i < argc - 1 && stack[i] != 2147483647)
		i++;
	return (i);
}

int	*ft_rrb(int argc, int *stack)
{
	int	temp;
	int	i;
	int	real_size;

	real_size = ft_real_size(argc, stack);
	temp = stack[real_size - 1];
	i = real_size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	return (stack);
}

int	*ft_move_by_1(int argc, int *stack)
{
	int	i;

	i = argc - 2;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = 2147483647;
	return (stack);
}

int	*ft_pb(int argc, int *stack_a, int *stack_b)
{
	int	i;

	if (stack_a[0] == 2147483647)
		return (stack_a);
	stack_b = ft_move_by_1(argc, stack_b);
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < argc - 2)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = 2147483647;
	return (stack_a);
}
