/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:21:59 by malleman          #+#    #+#             */
/*   Updated: 2022/10/31 10:57:59 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(dst);
	if (dstsize <= count)
		return (dstsize + ft_strlen(src));
	while (count + 1 < dstsize && src[i] != '\0')
	{
		dst[count] = src[i];
		count++;
		i++;
	}
	dst[count] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
/*
int main()
{
        char x[] = "Hello";
        char y[] = "Salut";
        printf("%zu\n", ft_strlcat(x, y, 4));
        return(0);
}
*/
