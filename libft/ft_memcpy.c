/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:21:51 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 12:40:02 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*u_dest;
	const unsigned char	*u_src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	u_dest = dest;
	u_src = src;
	while (i < n)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str[100];
	char	buffer1[100];
	char	buffer2[100];

	memset(str, 'A', sizeof(str));
	memcpy(buffer1, str, sizeof(str));
	ft_memcpy(buffer2, str, sizeof(str));
	if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0)
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return 0;
}
*/
