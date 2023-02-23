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

/* Fonction permettant de gerer les evenements du clavier. */
int event_key(int keycode, t_game_params *game)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == KEY_W && game->map.map[game->pos_y - 1][game->pos_x] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
        game->pos_y--;
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }
    else if (keycode == KEY_S && game->map.map[game->pos_y + 1][game->pos_x] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
        game->pos_y++;
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }
    else if (keycode == KEY_A && game->map.map[game->pos_y][game->pos_x - 1] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
        game->pos_x--;
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }
    else if (keycode == KEY_D && game->map.map[game->pos_y][game->pos_x + 1] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
        game->pos_x++;
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }
    return (0);
}