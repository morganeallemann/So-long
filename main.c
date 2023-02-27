/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/02/15 16:39:10 by malleman         ###   ########.fr       */
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
		put_map_on_windows(&game);
		mlx_key_hook(game.win_ptr, event_key, &game);
			
		mlx_loop(game.mlx_ptr);
		free(game.mlx_ptr);
		if(game.map.map)
			ft_free(game.map.map);
	}
}
