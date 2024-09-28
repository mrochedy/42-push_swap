/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:15:11 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 14:03:33 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if ((!dst || !src) && !dstsize)
		return (0);
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dst_len + 1)
	{
		while (src[i] && dst_len + i < dstsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	if (dstsize < dst_len)
		return (dstsize + src_len);
	else
		return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "HAHAho +!:/ como va?\0";
	char	dst1[50] = "Test";
	char	dst2[50] = "Test";

	printf("Original function: ret: %lu | dst: %s\n\
My function: ret: %lu | dst: %s\n",
	strlcat(dst1, src, 10), dst1, ft_strlcat(dst2, src, 10), dst2);
	return (0);
}
*/
