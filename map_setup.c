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
    Fonction permettant de connaitre le nombre de ligne de ma map.ber qui definira la hauteur de ma map. 
    Elle ouvre le fd et check les erreur. 
    Elle va lire chaque lignes du fichier jusqu'a la fin et incrementer la variable nb_line a chaque tour de boucle. 
    Elle renvoie ensuite la variable nb_line une fois que le fichier entier a ete lu. 
*/
int    get_nbr_lines(char *map_fd)
{
    int     fd;
    int     nb_lines;
    char    *temp;

    nb_lines = 0;
    fd = open(map_fd, O_RDONLY);
    if (fd == -1)
    {
        perror("ERROR: Fichier non compatible\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        temp = get_next_line(fd);
        while (temp)
        {
            free(temp);
            temp = get_next_line(fd);
            nb_lines++;
        }
        close(fd);
    }
    return (nb_lines);
}

/*
    Fonction permettant de setup la memoire dynamique de ma map 2D. en gerant les char.
    Elle lit et stock la premiere ligne du fichier dans notre variable lignes.
    Elle boucle tant qu'elle trouve une ligne pour lire tout le fichier et va allouer la memoire pour chaque ligne.
    Elle copie a chaque boucle le caractere de line dans la case correspondante de la matrice map.
*/
void    memset_range_line(int range, int col, int i, t_game_params *game)
{
    char *line;
    
    line = get_next_line(game->map.fd);
    while (line)
    {
        game->map.map[range] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
        if (!game->map.map[range])
            return (ft_free(game->map.map));
        while (line[i])
        {
            game->map.map[range][col] = line[i];
            i++;
            col++;
        }
        game->map.map[range++][col] = '\0';
        col = 0;
        i = 0;
        free(line);
        line = get_next_line(game->map.fd);
    }
    game->map.map[range] = NULL;
}

/*
    Fonction qui permet de stocker les donnees + allouer la memoire trouver via get_nb_line et memset_range_line dans mes variables lines et map. 
    Elle stock egalement le nom du fichier dans map_fd. 
    Elle va allouer la memoire pour un tableau de chaine de caractere avec ft_calloc et le stocker dans map.map. 
    Elle permet de gerer l'erreur si le fd n'est pas compatible. 
    Elle ferme ensuite le fd avec la fonction close. 
*/
void    stock_map(char *map_fd, t_game_params *game)
{
    size_t  col;
    int     range;
    int     i;

    col = 0;
    range = 0;
    i = 0;
    game->map.lignes = get_nbr_lines(map_fd);
    game->map.map_file = map_fd;
    game->map.map = ft_calloc(game->map.lignes + 1, sizeof(char *));
    if (!game->map.map)
        return;
    game->map.fd = open(map_fd, O_RDONLY);
    if (game->map.fd == -1)
    {
        perror("ERROR: Ouverture du fichier impossible\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        memset_range_line(range, col, i, game);
        close(game->map.fd);
    }
}

/*
    Fonction permettant d'initaliser les variables de ma structure "map_params" et "game_params"
*/
void    map_init(t_game_params *game)
{
    game->x = 0;
    game->y = 0;
    game->win_h = game->map.lignes * IMG_SIZE;
    game->win_l = (ft_strlen(game->map.map[0]) - 1) * IMG_SIZE;
    game->map.player = 0;
    game->map.items = 0;
    game->map.exit = 0;
    game->moves = 0;
    game->items = 0;
}