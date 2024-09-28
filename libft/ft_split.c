/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:24:46 by mrochedy          #+#    #+#             */
/*   Updated: 2024/06/04 10:12:46 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_everything(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static char	*allocate_strs(char **array, const char *s, char c)
{
	int	i;
	int	word_index;
	int	chars_count;

	i = 0;
	word_index = 0;
	chars_count = 0;
	while (s[i])
	{
		if (s[i++] != c)
			chars_count++;
		else if (chars_count)
		{
			array[word_index] = malloc((chars_count + 1) * sizeof(char));
			chars_count = 0;
			if (!array[word_index++])
				return (NULL);
		}
	}
	if (chars_count)
		return (array[word_index] = malloc((chars_count + 1) * sizeof(char)),
			array[word_index]);
	return ("Correct");
}

static void	fill_array(char **array, const char *s, char c)
{
	int	i;
	int	chars_index;
	int	word_index;

	i = 0;
	chars_index = 0;
	word_index = 0;
	while (s[i])
	{
		if (s[i] != c)
			array[word_index][chars_index++] = s[i];
		else if (chars_index)
		{
			array[word_index][chars_index] = '\0';
			word_index++;
			chars_index = 0;
		}
		i++;
	}
	if (chars_index)
		array[word_index++][chars_index] = '\0';
}

static void	new_word_case(int *count, int *is_new_word)
{
	(*count)++;
	(*is_new_word) = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		is_new_word;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	is_new_word = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i++] == c)
			is_new_word = 1;
		else if (is_new_word)
			new_word_case(&count, &is_new_word);
	}
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (count >= 0)
		array[count--] = NULL;
	if (!allocate_strs(array, s, c))
		return (free_everything(array), NULL);
	return (fill_array(array, s, c), array);
}

/*
#include <stdio.h>
int	main(void)
{
	int		i;
	char	str[] = "--Voici--un-test-----beau---gosse-!";
	char	**array;

	i = 0;
	array = ft_split(str, '-');
	while (array[i])
		printf("%s\n", array[i++]);
	return (0);
}
*/
