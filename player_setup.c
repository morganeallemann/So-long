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

void    player_init(t_game_params *game)
{
    int x;
    int y;

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