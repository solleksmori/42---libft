/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillen <lguillen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:18:45 by lguillen          #+#    #+#             */
/*   Updated: 2024/11/08 14:08:05 by lguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	total;

	total = size * nmemb;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (total / size != nmemb)
		return (NULL);
	dest = malloc (total);
	if (dest == NULL)
		return (NULL);
	ft_memset (dest, '\0', total);
	return (dest);
}
