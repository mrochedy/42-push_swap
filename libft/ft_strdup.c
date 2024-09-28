/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:09:14 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/30 12:18:26 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str[] = "hahahi blablou/:";

	printf("Original function: %s\nMy function: %s\n",
	strdup(str), ft_strdup(str));
}
*/
