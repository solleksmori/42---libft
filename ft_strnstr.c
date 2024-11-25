/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillen <lguillen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:06:54 by lguillen          #+#    #+#             */
/*   Updated: 2024/11/11 12:58:34 by lguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] != '\0' && b < len)
	{
		l = 0;
		while (big[b + l] == little[l] && (b + l) < len)
		{
			if (little[l + 1] == '\0')
				return ((char *)big + b);
			l++;
		}
		b++;
	}
	return (NULL);
}
