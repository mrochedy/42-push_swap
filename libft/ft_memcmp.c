/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:22:10 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/14 17:35:00 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	i = 0;
	u_s1 = s1;
	u_s2 = s2;
	while (i < n)
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("Original function: %d\nMy function: %d\n",
	memcmp(s2, s3, 4), ft_memcmp(s2, s3, 4));
	return (0);
}
*/
