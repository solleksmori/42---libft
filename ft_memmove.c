/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillen <lguillen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:14:19 by lguillen          #+#    #+#             */
/*   Updated: 2024/11/11 12:57:57 by lguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	char	*cdest;
	char	*csrc;
	size_t	i;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (cdest < csrc)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}	
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			cdest[i] = csrc[i];
		}
	}
	return (dest);
}
