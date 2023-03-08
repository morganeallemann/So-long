/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_game_param(t_game_params *game)
{
	perror("ERREUR: Les elements doivent etre: P = 1, C >= 1, E = 1\n");
	ft_free(game->map.map);
	exit(EXIT_FAILURE);
}

void	error_map_format(t_game_params *game)
{
	perror("ERREUR: La map n'est pas un rectangle !\n");
	ft_free(game->map.map);
	exit(EXIT_FAILURE);
}

void	error_wall(t_game_params *game)
{
	perror("ERREUR: La map n'est pas fermee par des murs !\n");
	ft_free(game->map.map);
	exit(EXIT_FAILURE);
}

void	error_extension(t_game_params *game)
{
	perror("ERREUR: Fichier pas valable\n");
	ft_free(game->map.map);
	exit(EXIT_FAILURE);
}
