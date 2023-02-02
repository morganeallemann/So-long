/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:10:00 by malleman          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:09 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_find_set(char c, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		x;
	char	*strim;

	x = 0;
	i = 0;
	j = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ft_find_set(s1[i], set))
		i++;
	while (j > i && (ft_find_set(s1[j - 1], set)))
		j--;
	strim = (char *)malloc(sizeof(char) * (j - i) + 1);
	if (strim == NULL)
		return (NULL);
	while (i < j)
	{
		strim[x] = s1[i];
		i++;
		x++;
	}
	strim[x] = '\0';
	return (strim);
}
