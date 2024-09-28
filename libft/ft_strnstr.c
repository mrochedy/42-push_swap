/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:30:22 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 14:04:36 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && !len)
		return ((char *)big);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	big[] = "Foo Bar Baz";
	char	little[] = "Bar";

	printf("Original function: %s\nMy function: %s\n",
	strnstr(big, little, 5), ft_strnstr(big, little, 5));
}
*/
