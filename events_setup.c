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

/*  Fonction permettant de gerer les evenements du clavier. 
    Pour chaque événements la fonction rajoute un floor sur la case de base et rajoute l'image du player sur la case suivante en fonction de la touche appuyée.
    La fonction gère également le fait que le joueur ne peux pas avancer dans les murs avec la condition =! 1 donc au Wall.
 */
int event_key(int keycode, t_game_params *game)
{
    char *nb_moves;

    nb_moves = ft_strjoin("Nombre de déplacements: ", ft_itoa(game->moves));
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        exit(EXIT_SUCCESS);
    }
    if (game->map.map[game->pos_y][game->pos_x] != 'E')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    if (game->map.map[game->pos_y][game->pos_x] == 'E')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    if (keycode == KEY_W && game->map.map[game->pos_y - 1][game->pos_x] != '1')
        game->pos_y--;
    else if (keycode == KEY_S && game->map.map[game->pos_y + 1][game->pos_x] != '1')
        game->pos_y++;
    else if (keycode == KEY_A && game->map.map[game->pos_y][game->pos_x - 1] != '1')
        game->pos_x--;
    else if (keycode == KEY_D && game->map.map[game->pos_y][game->pos_x + 1] != '1')
        game->pos_x++;
    mlx_string_put(game->mlx_ptr, game->win_ptr, game->win_h, 10, 0x0000FF00, nb_moves);
    player_move(game);
    return (0);
}

/*  Fonction qui gérent les mouvements vers le haut du joueur. Si la touche W est appuyé la fonction event_key appelera cette fonction. 
    La fonction ajoute un floor sur la case actuel du joueur et rajoute un image player sur la case +1 du haut. 
*/
void    player_move(t_game_params *game)
{
    game->moves++;
    ft_printf("Nombre de mouvements: %d\n", game->moves);
    if (game->map.map[game->pos_y][game->pos_x] == 'M')
        game_over(game); 
    else if (game->map.map[game->pos_y][game->pos_x] == 'E')
    {
        if (game->items >= game->map.items)
            winner(game);
        else
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }
    else
    {
        if (game->map.map[game->pos_y][game->pos_x] == 'C')
            game->items++;
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }  
    return ;
}

void    game_over(t_game_params *game)
{
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player_down, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(EXIT_SUCCESS); 
}

void    winner(t_game_params *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(EXIT_SUCCESS);
}