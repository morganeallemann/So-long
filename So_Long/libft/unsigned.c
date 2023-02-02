/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:46:36 by malleman          #+#    #+#             */
/*   Updated: 2023/02/02 13:52:03 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	len_nb_u(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*result;
	long int		i;
	unsigned int	nb;

	i = len_nb_u(n);
	nb = n;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	result[i] = '\0';
	while (nb > 0)
	{
		result[i - 1] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (result);
}

int	ft_print_u(unsigned int n)
{
	int		nb_len;
	char	*number;

	nb_len = 0;
	if (n == 0)
		nb_len += write(1, "0", 1);
	else
	{
		number = ft_uitoa(n);
		nb_len = ft_putstr(number);
		free(number);
	}
	return (nb_len);
}
