/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:43:55 by malleman          #+#    #+#             */
/*   Updated: 2023/02/02 12:53:20 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_word_len(char *s, char c)
{
	int	i;

	i = 1;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_real_split(char **res, char const *s, char c)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (i < ft_count_word((char *)s, c))
	{
		while (s[j] == c)
			j++;
		word_len = ft_word_len((char *)&s[j], c);
		res[i] = ft_calloc(sizeof(**res), word_len + 1);
		if (res[i] == 0)
			return (0);
		ft_strlcpy(res[i], (char *)&s[j], word_len + 1);
		j += word_len;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	res = ft_calloc(sizeof(*res), ft_count_word((char *)s, c) + 1);
	if (res == 0)
		return (0);
	if (ft_real_split(res, s, c) == 0)
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (NULL);
	}
	return (res);
}
