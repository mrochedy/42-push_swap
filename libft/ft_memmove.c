/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:32:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/06/04 10:12:14 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	overlap_case(unsigned char *u_dest,
	const unsigned char *u_src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i > 0)
	{
		u_dest[i] = u_src[i];
		i--;
	}
	u_dest[0] = u_src[0];
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*u_dest;
	const unsigned char	*u_src;

	if (!dest && !src)
		return (NULL);
	u_dest = dest;
	u_src = src;
	if (u_src < u_dest && u_dest < u_src + n)
		overlap_case(u_dest, u_src, n);
	else
	{
		i = 0;
		while (i < n)
		{
			u_dest[i] = u_src[i];
			i++;
		}
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
	memmove(buffer1, str, sizeof(str));
	ft_memmove(buffer2, str, sizeof(str));
	if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0)
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return 0;
}
*/
