/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:51:06 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/15 10:06:00 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	unsigned char	*array;

	i = 0;
	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	array = malloc(total_size);
	if (!array)
		return (NULL);
	while (i < total_size)
		array[i++] = 0;
	return ((void *)array);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str;

	str = ft_calloc(18446744073709551615, 18446744073709551615);
	printf("%s\n", str);
	return (0);
}
*/
