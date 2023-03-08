/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 16:06:36 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*  
    Fonction qui gérent les mouvements du joueur.
    La premiere ligne permet de verifier si les touches appuyee correspondent
	bien au : WSAD afin d'incrementer le nombre de mouvements. 
    Ensuite elle printe le nombre de mouvement dans le terminal. 
    La fonction va ensuite gerer les mouvements a executer en fonction de la
	case sur laquelle le player a ete deplacé.
*/
void	player_move(int key, t_game_params *game)
{
	put_move_on_screen(game);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		game->moves++;
	if (game->map.map[game->pos_y][game->pos_x] == 'M')
		game_over(game);
	else if (game->map.map[game->pos_y][game->pos_x] == 'E')
		exit_game(game);
	else
	{
		if (game->map.map[game->pos_y][game->pos_x] == 'C')
		{
			game->items++;
			game->map.map[game->pos_y][game->pos_x] = '0';
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor,
			game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player,
			game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
	}
	return ;
}
/*
    Fonction qui gere si la sortie est atteignable ou pas en fonction des 
    items collectes. Si tout les items ne sont pas collecte, la sortie n'est
    pas possible et elle affiche un message a l'ecran.
    Si tout les objects sont collecte, elle envoie vers la fonction winner.
*/

void	exit_game(t_game_params *game)
{
	if (game->items == game->map.items)
		winner(game);
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player, game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
		mlx_string_put(game->mlx_ptr, game->win_ptr,
			(game->map.columns / 2) * IMG_SIZE, 10, 0xFFFFFF,
			"Objects manquant\n");
	}
	return ;
}

/* 
	Fonction qui permet de gerer les mouvements a effectuer lorsque le player
 	touche un ennemie. 
*/
void	game_over(t_game_params *game)
{
	game->process = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player_down,
		game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.game_over,
		(game->map.columns / 2) * IMG_SIZE - 76,
		(game->map.lignes / 2) * IMG_SIZE - 40);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		(game->map.columns / 2) * IMG_SIZE - 96,
		game->map.lignes * IMG_SIZE, 0xFFFFFF, "APPUYER SUR ESC POUR FERMER");
}

/* 
	Fonction qui permet de gerer les mouvements a effectuer lorsque le player
	termine le jeu avec succès. 
*/
void	winner(t_game_params *game)
{
	game->process = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.winner,
		(game->map.columns / 2) * IMG_SIZE - 76,
		(game->map.lignes / 2) * IMG_SIZE - 40);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		(game->map.columns / 2) * IMG_SIZE - 96, game->map.lignes * IMG_SIZE,
		0xFFFFFF, "APPUYER SUR ESC POUR FERMER");
}

/*
    Fonction qui permet d'afficher le nombre de mouvements sur la fenêtre du jeu
*/
void	put_move_on_screen(t_game_params *game)
{
	char	*nb_moves;
	int		y;
	int		x;
	int		width;
    char   *temp;

	y = 0;
	x = 0;
	width = 0;
    temp = ft_itoa(game->moves + 1);
	nb_moves = ft_strjoin("Nombre de deplacements: ", temp);
	ft_printf("Nombre de mouvements: %d\r", game->moves);
	while (game->map.map[y][x] != '\n')
	{
		define_sprite(game, width, y, x);
		width += IMG_SIZE;
		x++;
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 0, 10, 0xFFFFFF, nb_moves);
    free (temp);
	free (nb_moves);
}
