/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:07:27 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/09 10:52:58 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_dest_len(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	return (i);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = get_dest_len(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

static int	count_chars(int size, char **strs, char *sep)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	while (sep[count])
		count++;
	count *= size - 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		count += j;
		i++;
	}
	return (count);
}

char	*ft_strjoin_argv(int argc, char **argv, char *sep)
{
	int		full_len;
	int		i;
	char	*ret_str;

	i = 1;
	if (argc == 1)
		return (NULL);
	full_len = count_chars(argc, argv, sep);
	ret_str = malloc((full_len + 1) * sizeof(char));
	if (ret_str == NULL)
		return (NULL);
	ret_str[0] = '\0';
	while (i < argc - 1)
	{
		ft_strcat(ret_str, argv[i++]);
		ft_strcat(ret_str, sep);
	}
	ft_strcat(ret_str, argv[i]);
	return (ret_str);
}
