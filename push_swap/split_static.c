/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_static.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:55:19 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/23 14:48:02 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	wordcount(char const *s, char c)
{
	int		i;
	bool	world;

	i = 0;
	while (*s)
	{
		world = false;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!world)
			{
				++i;
				world = true;
			}
			++s;
		}
	}
	return (i);
}

static char	*get_next_word(char *s, char c)
{
	static int	position = 0;
	char		*word;
	int			word_len;
	int			i;

	word_len = 0;
	i = 0;
	while (s[position] == c)
		++position;
	while ((s[position + word_len]) != c && s[position + word_len])
		++word_len;
	word = malloc((size_t)word_len * sizeof(char) + 1);
	if (word == NULL)
		return (NULL);
	while ((s[position] != c) && s[position])
		word[i++] = s[position++];
	word[i] = '\0';
	return (word);
}

char	**split_static(char *s, char c)
{
	int		count_words;
	char	**result;
	int		i;

	i = 0;
	count_words = wordcount(s, c);
	if (!count_words)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(count_words + 2));
	if (result == NULL)
		return (NULL);
	while (count_words-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (result[i] == NULL)
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(s, c);
	}
	result[i] = NULL;
	return (result);
}
