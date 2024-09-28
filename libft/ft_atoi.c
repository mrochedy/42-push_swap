/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:00:32 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/29 19:14:44 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nbr * 10 + nptr[i++] - '0';
	return (sign * nbr);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	str[] = "    \n\t\f   -6835";

	printf("Original function: %d\nMy function: %d\n",
	atoi(str), ft_atoi(str));
	return (0);
}
*/
