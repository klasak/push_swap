/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_operations2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 11:39:09 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/04 19:06:25 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	*ft_sb(int *stack)
{
	int	temp;

	if (stack[0] == 2147483647 || stack[1] == 2147483647)
		return (stack);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return (stack);
}

int	*ft_rap(int argc, int *stack)
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
	write(1, "ra\n", 3);
	return (stack);
}

int	*ft_pbp(int argc, int *stack_a, int *stack_b)
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
	write(1, "pb\n", 3);
	return (stack_a);
}
