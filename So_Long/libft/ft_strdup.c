/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:51:20 by malleman          #+#    #+#             */
/*   Updated: 2022/10/31 16:13:28 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		a;

	a = ft_strlen(s);
	ptr = malloc(sizeof(char) * (a + 1));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (i < a)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
