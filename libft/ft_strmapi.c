/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:35:25 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 13:29:17 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	new_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
#include <stdio.h>
char	increment_letters(unsigned int i, char c)
{
	int	a;

	a = i;
	i = a + i - a;
	return (c + 1);
}

int	main(void)
{
	char	str[] = "Sdrs";

	printf("%s\n", ft_strmapi(str, &increment_letters));
	return (0);
}
*/
