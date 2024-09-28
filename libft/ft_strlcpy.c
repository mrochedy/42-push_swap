/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:34:30 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/30 10:12:03 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "HAHAho +!:/ como va?\0";
	char	dst1[25] = "\0";
	char	dst2[25] = "\0";

	printf("Original function: ret: %lu | dst: %s\n\
My function: ret: %lu | dst: %s\n",
	strlcpy(dst1, src, 25), dst1, ft_strlcpy(dst2, src, 25), dst2);
	return (0);
}
*/
