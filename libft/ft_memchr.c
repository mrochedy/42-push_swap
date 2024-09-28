/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:43:12 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/29 18:59:39 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*u_s;

	i = 0;
	u_s = s;
	while (i < n)
		if (u_s[i++] == (unsigned char)c)
			return ((void *)&s[i - 1]);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "Test numéro 1";

	if (memcmp(memchr(str, 't', sizeof(str)),
	ft_memchr(str, 't', sizeof(str)), sizeof(str)) == 0)
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return (0);
}
*/
