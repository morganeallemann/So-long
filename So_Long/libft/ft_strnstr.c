/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:49:26 by malleman          #+#    #+#             */
/*   Updated: 2022/10/31 14:32:38 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	char	*str1;
	char	*to_find;

	i = 0;
	str1 = (char *)haystack;
	to_find = (char *)needle;
	if (to_find[0] == '\0')
		return (str1);
	while (str1[i] != '\0' && i < len)
	{
		a = 0;
		while (i + a < len && (str1[i + a] == to_find[a]))
		{
			if (to_find[a + 1] == '\0')
				return (&str1[i]);
			a++;
		}
		i++;
	}
	return (NULL);
}
