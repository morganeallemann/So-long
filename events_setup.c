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
    Fonction permettant de gerer les evenements du clavier. 
    Une variable nb_move est declarée afin de pouvoir afficher le nombre de mouvement sur la fenêtre du jeu. La fonction itoa est appelée afin de transformer le INT de game->moves en char.
    La fonction gère la fermeture de la fenêtre si la touche ESC est appuyée.
    Pour chaque événements la fonction rajoute un floor sur la case de base, excepté pour l'EXIT ou elle rajoute une case EXIT.
    La fonction gère également le fait que le joueur ne peux pas avancer dans les murs avec la condition =! 1 donc au Wall.
    Elle appelle ensuite la fonction mlx_string_put afin d'afficher le nombre de mouvements à l'écran.
    Elle appelle pour finir la fonction player_move qui elle définira les mouvements a éxecuter en fonction de la touche appuyée.
 */
int event_key(int keycode, t_game_params *game)
{
    char *nb_moves;

    if (keycode == KEY_ESC)
    {
        close_game(game);
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
    nb_moves = ft_strjoin("Nombre de deplacements: ", ft_itoa(game->moves + 1));
    mlx_string_put(game->mlx_ptr, game->win_ptr,10, 10, 0xFFFFFF, nb_moves);
    player_move(keycode, game);
    return (0);
}

/*  
    Fonction qui gérent les mouvements du joueur.
    La premiere ligne permet de verifier si les touches appuyee correspondent bien au : WSAD afin d'incrementer le nombre de mouvements. 
    Ensuite elle printe le nombre de mouvement dans le terminal. 
    La fonction va ensuite gerer les mouvements a executer en fonction de la case sur laquelle le player a ete deplacé.
*/
void    player_move(int keycode, t_game_params *game)
{
    if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
        game->moves++;
    ft_printf("Nombre de mouvements: %d\r", game->moves);
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
        {
            game->items++;
            game->map.map[game->pos_y][game->pos_x] = '0';
        }
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    }  
    return ;
}

/* Fonction qui permet de gerer les mouvements a effectuer lorsque le player touche un ennemie. */
void    game_over(t_game_params *game)
{
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player_down, game->pos_x * IMG_SIZE, game->pos_y *IMG_SIZE);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.game_over, (game->map.columns / 2) * IMG_SIZE - 76, (game->map.lignes / 2) * IMG_SIZE - 40);
    mlx_string_put(game->mlx_ptr, game->win_ptr, (game->map.columns / 2) * IMG_SIZE - 96, game->map.lignes * IMG_SIZE, 0xFFFFFF, "APPUYER SUR ESC POUR FERMER");
}

/* Fonction qui permet de gerer les mouvements a effectuer lorsque le player termine le jeu avec succès. */
void    winner(t_game_params *game)
{
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.winner, (game->map.columns / 2) * IMG_SIZE - 76, (game->map.lignes / 2) * IMG_SIZE - 40);
    mlx_string_put(game->mlx_ptr, game->win_ptr, (game->map.columns / 2) * IMG_SIZE - 96, game->map.lignes * IMG_SIZE, 0xFFFFFF, "APPUYER SUR ESC POUR FERMER");
}