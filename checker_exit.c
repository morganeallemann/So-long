/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/08 14:39:48 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Fonction permettant de chercher l'endroit ou se trouve l'exit dans la map
	et stocker sa position dans exit_y, exit_x.
*/
void	exit_init(t_game_params *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'E')
			{
				game->exit_y = y;
				game->exit_x = x;
			}
			x++;
		}
		y++;
	}
}

/*
	Fonction permettant de copier la map envoyee en parametre dans la variable
	**map_for_check afin de pouvoir faire un flood fill dessus et ne pas 
	casser la map initiale.
*/
char	**copy_map(t_game_params *game)
{
	char	**map_for_check;
	int		len;
	int		i;

	i = 0;
	map_for_check = ft_calloc(game->map.lignes + 1, sizeof(char *));
	if (!map_for_check)
		return (NULL);
	while (i < game->map.lignes)
	{
		len = ft_strlen(game->map.map[i]);
		map_for_check[i] = ft_calloc(len + 1, sizeof(char));
		if (!map_for_check)
		{
			ft_free(map_for_check);
			return (NULL);
		}
		ft_memcpy(map_for_check[i], game->map.map[i], len);
		map_for_check[i][len] = '\0';
		i++;
	}
	map_for_check[game->map.lignes] = NULL;
	return (map_for_check);
}

/*
	Fonction flood_fill qui permet de remplacer tout les elements de la map par
	des X sauf les murs afin de verifier que la sortie est atteignable et que 
	tout les items sont collectibles.
*/
void	ft_flood_fill(t_game_params *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map.lignes || x >= game->win_l)
		return ;
	if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == 'E' ||
			map[y][x] == 'M' || map[y][x] == '0')
	{
		map[y][x] = 'X';
		ft_flood_fill(game, map, x - 1, y);
		ft_flood_fill(game, map, x + 1, y);
		ft_flood_fill(game, map, x, y - 1);
		ft_flood_fill(game, map, x, y + 1);
	}
}

/*
	Fonction permettant de compter si il reste encore des items sur la map une
	fois qu'elle a passer dans la fonction floodfill. Si il reste encore des 
	items c'est qu'un objet n'etait pas collectible.
	Elle retourne donc la valeur du nomber d'items trouve.
*/
int	check_items(char **map)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

/*
	Fonction permettant de checker si une Exit donc 'E' se trouve encore dans 
	la map une fois qu'elle a passer dans flood_fill. 
	Si c'est le cas, la sortie n'est pas atteignable et la fonction revoie 1.
	Elle va egalement controler si le nombre d'items renvoier via la fonction
	precedente est bien a 0 sinon elle renvoie 1 et free la map copiee.
	Autrement elle free la map copiee et renvoie 0.
*/
int	check_exit(t_game_params *game)
{
	char	**copied_map;
	int		items;

	exit_init(game);
	copied_map = copy_map(game);
	if (!copied_map)
		return (0);
	ft_flood_fill(game, copied_map, game->pos_x, game->pos_y);
	items = check_items(copied_map);
	if (copied_map[game->exit_y][game->exit_x] != 'X')
	{
		ft_free(copied_map);
		return (1);
	}
	if (items > 0)
	{
		ft_free(copied_map);
		return (1);
	}
	ft_free(copied_map);
	return (0);
}
