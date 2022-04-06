/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 09:46:14 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/01 16:54:27 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	*ft_case_1(int *stack_a)
{
	stack_a = ft_sb(stack_a);
	write(1, "sa\n", 3);
	return (stack_a);
}

int	*ft_case_2(int argc, int *stack_a)
{
	stack_a = ft_sb(stack_a);
	write(1, "sa\n", 3);
	stack_a = ft_rrb(argc, stack_a);
	write(1, "rra\n", 4);
	return (stack_a);
}

int	*ft_case_3(int argc, int *stack_a)
{
	stack_a = ft_rb(argc, stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

int	*ft_case_4(int argc, int *stack_a)
{
	stack_a = ft_sb(stack_a);
	write(1, "sa\n", 3);
	stack_a = ft_rb(argc, stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

int	*ft_case_5(int argc, int *stack_a)
{
	stack_a = ft_rrb(argc, stack_a);
	write(1, "rra\n", 4);
	return (stack_a);
}
