/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 15:50:21 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 15:22:59 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	parts(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[k] != '\0')
	{
		if (s[k] != c && (s[k + 1] == c || s[k + 1] == '\0'))
			i++;
		k++;
	}
	return (i);
}

static int	ft_lenght(char const *s, char c, int k)
{
	int	d;

	d = 0;
	while (s[k] != c && s[k] != '\0')
	{
		d++;
		k++;
	}
	return (d);
}

void	*free_each(char **array)
{
	int	j;

	j = 0;
	while (array[j])
	{
		free(array[j]);
		j++;
	}
	free(array[j]);
	free(array);
	return (NULL);
}

static char	**allocate(char const *s, char c, int i, char **array)
{
	int		j;
	int		k;
	int		l;

	j = 0;
	k = 0;
	while (j < i)
	{
		l = 0;
		while (s[k] == c)
			k++;
		array[j] = (char *)malloc(sizeof(char) * ft_lenght(s, c, k) + 1);
		if (!array[j])
			return (free_each(array));
		while (s[k] != c && s[k] != '\0')
		{
			array[j][l] = s[k];
			l++;
			k++;
		}
		array[j][l] = '\0';
		j++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	if (!s)
		return (NULL);
	i = parts(s, c);
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (NULL);
	array = allocate(s, c, i, array);
	return (array);
}
