/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:23:48 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/30 11:44:08 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str1[] = "Test 12";
	char	str2[] = "Testo";

	printf("Original function: %d\nMy function: %d\n",
	strncmp(str1, str2, 20), ft_strncmp(str1, str2, 20));
	return (0);
}
*/
