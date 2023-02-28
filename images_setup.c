/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/02/15 16:39:10 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
    Fonction permettant d'initaliser les variables de ma structure img_params.
    Les paths de mes sprites sont definies dans mon .h
*/
void    images_init(t_game_params *game)
{
    game->img.img_l = IMG_SIZE;
    game->img.img_h = IMG_SIZE;
    game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR, &game->img.img_l, &game->img.img_h);
    game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, &game->img.img_l, &game->img.img_h);
    game->img.items = mlx_xpm_file_to_image(game->mlx_ptr, ITEMS, &game->img.img_l, &game->img.img_h);
    game->img.player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &game->img.img_l, &game->img.img_h);
    game->img.player_down = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_DOWN, &game->img.img_l, &game->img.img_h);
    game->img.cat_front = mlx_xpm_file_to_image(game->mlx_ptr, CAT_FRONT, &game->img.img_l, &game->img.img_h);
    game->img.cat_right = mlx_xpm_file_to_image(game->mlx_ptr, CAT_RIGHT, &game->img.img_l, &game->img.img_h);
    game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, &game->img.img_l, &game->img.img_h);
    game->img.game_over = mlx_xpm_file_to_image(game->mlx_ptr, GAMEOVER, &game->img.img_l, &game->img.img_h);
    game->img.winner = mlx_xpm_file_to_image(game->mlx_ptr, WINNER, &game->win_l, &game->win_h);
}

/*
    Fonction permettant de remplacer chaque caracter de ma map.ber par la sprites qui lui est attribuee.
*/

void    define_sprite(t_game_params *game, int width, int y, int x)
{
    if(game->map.map[y][x] == '1')
    {
         mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, width, y * IMG_SIZE);
         mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall, width, y * IMG_SIZE);
    }
    else if(game->map.map[y][x] == '0')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, width, y * IMG_SIZE);
    else if(game->map.map[y][x] == 'P')
    { 
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, width, y * IMG_SIZE);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, width, y * IMG_SIZE);
    }
    else if(game->map.map[y][x] == 'C')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, width, y * IMG_SIZE);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.items, width, y * IMG_SIZE);
    }
    else if (game->map.map[y][x] == 'M')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, width, y * IMG_SIZE);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.cat_front, width, y * IMG_SIZE);
    }
    else if (game->map.map[y][x] == 'E')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, width, y * IMG_SIZE);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, width, y * IMG_SIZE);
    }
}