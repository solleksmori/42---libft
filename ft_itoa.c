/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillen <lguillen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:41:28 by lguillen          #+#    #+#             */
/*   Updated: 2024/11/07 16:15:57 by lguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count += 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	temp;
	int			count;
	char		*dest;

	temp = n;
	count = ft_count(n);
	dest = (char *) malloc ((count + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	if (temp == 0)
		dest[0] = '0';
	if (temp < 0)
	{	
		temp = -temp;
		dest[0] = '-';
	}
	while (count > 0 && temp != 0)
	{
		dest[count - 1] = temp % 10 + '0';
		temp /= 10;
		count--;
	}
	return (dest);
}
