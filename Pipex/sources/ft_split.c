/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:21:10 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 01:30:01 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char const *s, char c)
{
	int		count_word;
	int		i;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count_word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count_word);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	grab_word(char **tab, int tab_index, char const *s, size_t len)
{
	tab[tab_index] = ft_substr(s, 0, len);
	if (!tab[tab_index])
	{
		ft_free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start_word;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start_word = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start_word)
			if (!grab_word(tab, j++, &s[start_word], i - start_word))
				return (NULL);
	}
	tab[j] = NULL;
	return (tab);
}
