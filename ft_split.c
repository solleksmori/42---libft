/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillen <lguillen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:39:16 by lguillen          #+#    #+#             */
/*   Updated: 2024/11/08 14:56:41 by lguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeme(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**malloc_strs(char **dest, char const *s, char c, int i)
{
	int	j;
	int	len;

	j = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		dest[j] = malloc(len + 1);
		if (dest[j] == NULL)
		{
			ft_freeme(dest, j);
			return (NULL);
		}
		j++;
	}
	return (dest);
}

static int	count_strs(char const *s, char c)
{
	int	i;
	int	count;

	if (!*s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**strs_to_arr(char **dest, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			dest[j][k] = s[i];
			i++;
			k++;
		}
		dest[j][k] = '\0';
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		count;

	if (!s)
		return (NULL);
	count = count_strs(s, c);
	dest = malloc ((count + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	malloc_strs(dest, s, c, 0);
	strs_to_arr(dest, s, c);
	return (dest);
}
