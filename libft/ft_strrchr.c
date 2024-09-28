/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:34:26 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/14 17:51:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		s++;
	}
	if (c == '\0')
		ret = (char *)s;
	return (ret);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "Test numéro 1 hohaa";

	printf("Original function: %s\nMy function: %s\n",
	strrchr(str, 'o'), ft_strrchr(str, 'o'));
	return (0);
}
*/
