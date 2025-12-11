/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:46:01 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/10/29 19:11:04 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (count);
}

static void	*ft_free_leak(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*ft_half_split(char const *s, int start, int length)
{
	int		t;
	char	*current_word;

	t = 0;
	current_word = (char *)malloc(length + 1);
	if (!current_word)
	{
		return (NULL);
	}
	while (t < length)
	{
		current_word[t] = s[start + t];
		t++;
	}
	current_word[t] = '\0';
	return (current_word);
}

static int	ft_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		words_total;
	char	**words;
	int		index;
	int		i;

	if (!s)
		return (NULL);
	words_total = ft_count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (words_total + 1));
	index = -1;
	i = 0;
	if (!words)
		return (NULL);
	while (++index < words_total)
	{
		while (s[i] && s[i] == c)
			i++;
		words[index] = ft_half_split(s, i, ft_word_len(&s[i], c));
		if (!words[index])
			return (ft_free_leak(words));
		i = ft_word_len(&s[i], c) + i;
	}
	words[index] = NULL;
	return (words);
}
