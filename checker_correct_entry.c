/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_correct_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 14:22:54 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Fonction qui permet de gerer si une lettre qui n'est pas gerer apparait 
	dans la map et renvoie un message d'erreur si c'est le cas.
*/
void	check_valid_map_char(t_game_params *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x] && game->map.map[y][x] != '\n')
		{
			if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0' &&
					game->map.map[y][x] != 'P' && game->map.map[y][x] != 'M' &&
					game->map.map[y][x] != 'C' && game->map.map[y][x] != 'E')
			{
				perror("La map comprend des elements non pris en charge !\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return ;
}
