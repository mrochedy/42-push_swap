/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:29:59 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/14 14:33:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	printf("Original function: %d\nMy function: %d\n",
	isalpha(argv[1][0]), ft_isalpha(argv[1][0]));
	return (0);
}
*/