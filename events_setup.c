/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 14:56:17 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Fonction qui permet d'initialiser la position du joueur et la stocker dans
	les variable pos_y et pos_x.
*/
void	player_init(t_game_params *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->pos_y = y;
				game->pos_x = x;
			}
			x++;
		}
		y++;
	}
}

/*  
    Fonction permettant de gerer les evenements du clavier. 
    La fonction gère la fermeture de la fenêtre si la touche ESC est appuyée.
    La variable de structure game->process est initialisé de base a 0 et 
	passe a 1 uniquement si le joueur gagne ou perd afin de bloquer
	les mouvements. 
    Pour chaque événements la fonction rajoute un floor sur la case de base, 
	excepté pour l'EXIT ou elle rajoute une case EXIT.
    La fonction gère également le fait que le joueur ne peux pas avancer dans 
	les murs avec la condition =! 1 donc au Wall.
    Elle appelle pour finir la fonction player_move qui elle définira les 
	mouvements a éxecuter en fonction de la touche appuyée.
 */
int	event_key(int keycode, t_game_params *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (game->map.map[game->pos_y][game->pos_x] != 'E' && game->process <= 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor,
			game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
	if (game->map.map[game->pos_y][game->pos_x] == 'E' && game->process <= 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit,
			game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
	if (keycode == KEY_W && game->map.map[game->pos_y - 1][game->pos_x] != '1'
			&& game->process <= 0)
		game->pos_y--;
	else if (keycode == KEY_S && game->map.map[game->pos_y + 1][game->pos_x]
			!= '1' && game->process <= 0)
		game->pos_y++;
	else if (keycode == KEY_A && game->map.map[game->pos_y][game->pos_x - 1]
			!= '1' && game->process <= 0)
		game->pos_x--;
	else if (keycode == KEY_D && game->map.map[game->pos_y][game->pos_x + 1]
		!= '1' && game->process <= 0)
		game->pos_x++;
	if (game->process <= 0)
		player_move(keycode, game);
	return (0);
}
