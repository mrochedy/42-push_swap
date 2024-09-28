/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:32:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/14 17:40:35 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("Original function: %d\nMy function: %d\n",
	isprint('~' + 1), ft_isprint('~' + 1));
	return (0);
}
*/
