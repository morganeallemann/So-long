/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 14:27:41 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
    Fonction permettant d'afficher une nouvelle fenetre en fonction de la
	largeur et la hauteur definie en parametre.
*/
int	window_init(t_game_params *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_l,
			game->win_h, "SO_LONG");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (1);
	}
	return (0);
}

/*
    Fonction permettant d'afficher la map a l'ecran.
*/
int	put_map_on_windows(t_game_params *game)
{
	int	y;
	int	x;
	int	width;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		width = 0;
		while (game->map.map[y][x] && game->map.map[y][x] != '\n')
		{
			define_sprite(game, width, y, x);
			width += IMG_SIZE;
			x++;
		}
		y++;
	}
	return (0);
}
