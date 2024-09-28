/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:01:01 by mrochedy          #+#    #+#             */
/*   Updated: 2024/06/04 10:13:15 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_to_trim(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

static char	*make_new_str(const char *s1, const char *set, size_t new_len)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc((new_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1[i] && is_to_trim(s1[i], set))
		i++;
	while (j < new_len)
	{
		new_str[j] = s1[i + j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	str_len;
	size_t	to_trim;

	if (!s1 || !set)
		return (NULL);
	str_len = ft_strlen(s1);
	to_trim = 0;
	i = 0;
	while (s1[i] && is_to_trim(s1[i++], set))
		to_trim++;
	i = str_len - 1;
	if (to_trim != str_len)
		while (is_to_trim(s1[i--], set))
			to_trim++;
	return (make_new_str(s1, set, str_len - to_trim));
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "uuu:/!ooeeeeuuTesteee///ueeuu!!!:ouoo";

	printf("%s\n", ft_strtrim(str, "euo:/!"));
	return (0);
}
*/
