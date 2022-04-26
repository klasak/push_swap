/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapping.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 10:41:18 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 14:22:22 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	*ft_mapping(int argc, int *stack_a)
{
	int	*stack_new;
	int	i;
	int	small;

	stack_new = ft_create_empty_stack(argc);
	i = 0;
	while (i < argc - 1)
	{
		small = find_smallest(argc, stack_a);
		stack_new[small] = i;
		stack_a[small] = 2147483647;
		i++;
	}
	free(stack_a);
	return (stack_new);
}
