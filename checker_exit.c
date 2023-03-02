/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/02 16:39:10 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void copy_map(t_game_params *game)
{
    char    **map_for_check;
    int     y;
    int     x;
    int     i;

    i = 0;
    y = 0;
    map_for_check = ft_calloc(game->map.lignes + 1, sizeof(char *));
    while (game->map.map[y])
    {
        x = 0;
        while (game->map.map[y][x] && game->map.map[y][x] != '/n')
        {
            map_for_check[y][i] = game->map.map[y][x];
            y++;
            x++;
            i++;
        }
        y++;
    }
}