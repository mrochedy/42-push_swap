/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:32:19 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 13:31:44 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	sub_str_len;
	size_t	i;

	if (!s)
		return (NULL);
	sub_str_len = 0;
	if (start < ft_strlen(s))
		while (s[start + sub_str_len] && sub_str_len < len)
			sub_str_len++;
	sub_str = malloc((sub_str_len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (i < sub_str_len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "Salut je te teste HAHA!";

	printf("%s\n", ft_substr(str, 8, 100));
	return (0);
}
*/
