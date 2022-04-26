/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_input_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 11:55:23 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 11:51:14 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dig_or_sign(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;
	char	*string;

	i = 0;
	while (i < argc - 1)
	{
		string = argv[i];
		j = 1;
		k = 0;
		k += ft_isdigit_or_sign(string[0]);
		while (string[j] != '\0')
		{
			k += ft_isdigit(string[j]);
			j++;
		}
		if (k < j)
			return (1);
		i++;
	}
	return (0);
}

int	ft_duplicates(int argc, int *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	ft_atoi_long(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = neg * (-1);
	}
	if (neg == -1 || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

int	ft_min_max(int argc, char *argv[])
{
	int		i;
	int		k;
	long	long_number;

	i = 0;
	k = 0;
	while (i < argc - 1)
	{
		long_number = ft_atoi_long(argv[i]);
		if (long_number < -2147483648 || long_number > 2147483647)
			k++;
		if (k > 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_sorted_check(int argc, int *stack)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < argc - 2)
	{
		if (stack[i] < stack[i + 1])
			k++;
		i++;
	}
	if (k == i)
		return (1);
	return (0);
}
