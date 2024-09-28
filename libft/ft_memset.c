/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:38:12 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/29 14:06:44 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_s;

	i = 0;
	u_s = s;
	while (i < n)
		u_s[i++] = (unsigned char)c;
	return (s);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char buffer1[100];
	char buffer2[100];

	memset(buffer1, 'A', sizeof(buffer1));
	ft_memset(buffer2, 'A', sizeof(buffer2));
	if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0)
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return 0;
}
*/
