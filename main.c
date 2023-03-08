/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 16:26:17 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game_params	game;

	if (ac == 2)
	{
		stock_map(av[1], &game);
		map_init(&game);
		window_init(&game);
		images_init(&game);
		player_init(&game);
		map_all_check(av[1], &game);
		put_map_on_windows(&game);
		mlx_key_hook(game.win_ptr, event_key, &game);
		mlx_hook(game.win_ptr, 17, 0, close_game, (void *)&game);
		mlx_loop(game.mlx_ptr);
		free(game.mlx_ptr);
	}
	else
	{
		perror("ERREUR: Nombre d'arguments incorrects\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
