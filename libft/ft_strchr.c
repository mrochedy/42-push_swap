/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:21:30 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/14 17:50:21 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "Test numéro 1";

	printf("Original function: %s\nMy function: %s\n",
	strchr(str, 't' + 256), ft_strchr(str, 't' + 256));
	return (0);
}
*/
