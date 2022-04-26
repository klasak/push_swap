/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 13:48:50 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 15:45:39 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

static int	ft_sort(int argc, int *stack_a)
{
	if (argc == 4)
		stack_a = ft_sort_3(argc, stack_a);
	else if (argc == 6)
		stack_a = ft_sort_5(argc, stack_a);
	else
	{
		stack_a = ft_mapping (argc, stack_a);
		stack_a = ft_radix(argc, stack_a);
	}
	free(stack_a);
	return (0);
}

static int	ft_check_input2(int argc, int *stack_a)
{
	if (ft_sorted_check(argc, stack_a) == 1)
	{
		free(stack_a);
		return (0);
	}
	if (ft_duplicates(argc, stack_a) == 1)
	{
		write(0, "Error\n", 6);
		free(stack_a);
		return (-1);
	}
	ft_sort(argc, stack_a);
	return (0);
}

static int	*ft_create_stack(int argc, char *argv[])
{
	int	*stack_a;
	int	i;

	stack_a = malloc (sizeof(int) * (argc - 1));
	if (!stack_a)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	return (stack_a);
}

static int	ft_check_input(int argc, char *argv[])
{
	int	*stack_a;

	if (ft_check_only_sign(argc, argv) == 1)
	{
		write(0, "Error\n", 6);
		return (-1);
	}
	if (ft_check_dig_or_sign(argc, argv) == 1)
	{
		write(0, "Error\n", 6);
		return (-1);
	}
	if (ft_min_max(argc, argv) == 1)
	{
		write(0, "Error\n", 6);
		return (-1);
	}
	stack_a = ft_create_stack(argc, argv);
	ft_check_input2(argc, stack_a);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**temp;
	int		i;

	if (argc < 2)
		return (-1);
	temp = NULL;
	i = 1;
	if (argc == 2)
	{
		argc = 1 + parts(argv[1], ' ');
		temp = ft_split(argv[1], ' ');
		ft_check_input(argc, temp);
		free_each(temp);
	}
	else
		ft_check_input(argc, argv + 1);
	return (0);
}
