/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:52:29 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 13:55:06 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

/*
#include <stdio.h>
void	increment_letters(unsigned int i, char *c)
{
	int	a;

	a = i;
	i = a + i - a;
	*c = *c + 1;
}

int	main(void)
{
	char	str[] = "Sdrs";

	ft_striteri(str, &increment_letters);
	printf("%s\n", str);
	return (0);
}
*/
