/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_5.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/13 09:39:35 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 13:41:39 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	*ft_sort_3(int argc, int *stack_a)
{
	if (ft_sorted_check(4, stack_a) == 1)
		return (stack_a);
	else if (stack_a[2] > stack_a[0] && stack_a[0] > stack_a[1])
		stack_a = ft_case_1(stack_a);
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
		stack_a = ft_case_2(argc, stack_a);
	else if (stack_a[0] > stack_a[2] && stack_a[2] > stack_a[1])
		stack_a = ft_case_3(argc, stack_a);
	else if (stack_a[1] > stack_a[2] && stack_a[2] > stack_a[0])
		stack_a = ft_case_4(argc, stack_a);
	else
		stack_a = ft_case_5(argc, stack_a);
	return (stack_a);
}

int	find_smallest(int argc, int *stack)
{
	int	small;
	int	i;
	int	j;

	i = 0;
	j = 1;
	small = 0;
	while (i < argc - 2)
	{
		while (j < argc - 1)
		{
			if (stack[j] < stack[i])
			{
				small = j;
				i = j;
			}
			j++;
		}
		i++;
	}
	return (small);
}

static int	*ft_smallest_to_top(int small, int argc, int *stack_a)
{
	int	real_size;
	int	i;

	i = small;
	real_size = ft_real_size(argc, stack_a);
	if (i < real_size / 2 + 1)
	{
		while (i > 0)
		{
			stack_a = ft_rb(argc, stack_a);
			write(1, "ra\n", 3);
			i--;
		}
	}
	else
	{
		while (real_size - i > 0)
		{
			stack_a = ft_rrb(argc, stack_a);
			write(1, "rra\n", 4);
			i++;
		}
	}
	return (stack_a);
}

int	*ft_create_empty_stack(int argc)
{
	int	*stack_b;
	int	i;

	stack_b = malloc (sizeof(int) * (argc - 1));
	if (!stack_b)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		stack_b[i] = 2147483647;
		i++;
	}
	return (stack_b);
}

int	*ft_sort_5(int argc, int *stack_a)
{
	int	*stack_b;
	int	i;
	int	small;

	stack_b = ft_create_empty_stack(argc);
	i = 0;
	while (i < argc - 4)
	{
		small = find_smallest(argc, stack_a);
		stack_a = ft_smallest_to_top(small, argc, stack_a);
		stack_a = ft_pb(argc, stack_a, stack_b);
		write(1, "pb\n", 3);
		i++;
	}
	stack_a = ft_sort_3(4, stack_a);
	i = 0;
	while (i < argc - 4)
	{
		stack_b = ft_pb(argc, stack_b, stack_a);
		write(1, "pa\n", 3);
		i++;
	}
	free(stack_b);
	return (stack_a);
}
