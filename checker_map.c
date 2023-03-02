/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/03/01 16:39:10 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
    Fonction permettant de controler que la map comprenne les elements necessaires.
    Elle va incrementer les variables en fonction des caracteres qu'elle trouve lors du parsing de la map.
    Si les variables ne corresponde pas au nombre obligatoire, elle retournera 1.
*/
int map_valid_items_and_player_exit(t_game_params *game)
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
                game->map.player++;
            if (game->map.map[y][x] == 'C')
                game->map.items++;
            if (game->map.map[y][x] == 'E')
                game->map.exit++;
            if (game->map.map[y][x] == 'M')
                game->map.ennemies++;
            x++;
        }
        y++;
    }
    if (game->map.player != 1 || game->map.items < 1 || game->map.exit != 1)
        return (1);
    else
        return (0);
}
/*
    Fonction permettant de controler que la map est bien entouree de murs.
    Elle va controler dabord la ligne 1 jusqu'a la fin, si la ligne est ok elle controlera que le premier caractere de la ligne et le dernier soit des murs.
    Elle fera ensuite un controle de la derniere ligne en faisant revenir la variable x a 0. 
    Si tout est ok elle renvoie 0, autrement 1.
*/
int map_valid_wall(t_game_params *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(game->map.map[y])
    {
        while(game->map.map[0][x] != '\n')
        {
            if (game->map.map[0][x] != '1')
                return (1);
            x++;
        }
        x--;
        if (game->map.map[y][0] != '1' || game->map.map[y][x] != '1')
            return (1);
        y++;
    }
    y--;
    while (x > 0)
    {
        if(game->map.map[y][x] != '1')
            return (1);
        x--;
    }
    return (0);
}

/* 
    Fonction permettant de verifier que la map est bien un rectangle.
    Elle va chaqe fois comparer la ligne en cours avec la premiere ligne. 
    Si tout ok elle renvoie 0, autrement 1.
*/
int map_valid_format(t_game_params *game)
{
    int y;
    int len;

    y = 0;
    len = 0;
    if (!game->map.map[0][0])
        return (1);
    while (game->map.map[y])
    {
        len = ft_strlen(game->map.map[y] - 1);
        if (len != game->map.columns && game->map.map[y] == NULL)
            return (1);
        y++;
    }
    return (0);
}

/*
    Fonction permettant de verifier que l'extension passee en parametre est la bonne. 
    Une variable char *temp est cree. Le i est egal a la fin de la premiere ligne. 
    Elle va ensuite ajouter dans temp les caracteres jusuq'au . 
    Si la variable temp est bien = a .reb elle renvoie 0, autrement 1.
*/
int map_valid_extension(char *map)
{
    char    *temp;
    int     i;
    int     j;

    i = ft_strlen(map);
    j = 0;
    temp = malloc(sizeof(char *) * i - 1);
    while (map[i] != '.')
    {
        temp[j] = map[i];
        i--;
        j++;
    }
    if (map[i] != '.' || temp[j - 3] != 'r' || temp[j - 2] != 'e' || temp[j - 1] != 'b')
        return (1);
    free (temp);
    return (0);
}

/*
    Fonction permettant d'appeler toutes les fonctions de check. 
    Elle appelera la fonction suivante que si la fonction precedente est valide. Sinon elle renvoie 1.
*/
int map_all_check(char *map, t_game_params *game)
{
    int check;

    check = 0;
    if (map_valid_extension(map) == 0)
    {   
        if (map_valid_format(game) == 0)
        {
            if(map_valid_wall(game) == 0)
                check = map_valid_items_and_player_exit(game);
            else 
                return (1);
        }
        else
            return (1);
    }
    if (check != 0)
        return (1);
    else
        return (0);
}