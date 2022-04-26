/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit_or_sign.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/12 15:27:16 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 11:51:26 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_isdigit_or_sign(int c)
{
	if (c < '+' || (c > '+' && c < '-') || (c > '-' && c < '0') || c > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_check_only_sign(int argc, char *argv[])
{
	int		i;
	char	*string;

	i = 0;
	while (i < argc - 1)
	{
		string = argv[i];
		if (string[0] == '+' && string[1] == '\0')
			return (1);
		else if (string[0] == '-' && string[1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
