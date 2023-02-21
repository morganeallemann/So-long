#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

/* Définition de la résolution de mes images */
# define IMG_SIZE 32

/* Définition des paths de mes sprites */
# define FLOOR "images/Floor.xpm"
# define WALL "images/wall.xpm"
# define ITEMS "images/item.xpm"
# define PLAYER "images/Player.xpm"
# define PLAYER_DOWN "images/Player_down.xpm"
# define CAT_FRONT "images/Cat_front.xpm"
# define CAT_RIGHT "images/Cat_right.xpm"
# define EXIT "images/exit.xpm"

/* Struct qui défini les valeurs relative a la map
    - La hauteur et la largeur de ma map
    - L'axe y est l'index des colonnes
    - L'axe x est l'index des lignes
    - Définir un emplacement pour le player
    - Définir un emplacement pour les items
    - Définir un emplacement pour la sortie
*/
typedef struct  s_map_params
{
    char    **map;
    char    *map_file;
    int     fd;
    int     columns;
    int     lignes;
    int     player;
    int     items;
    int     exit;
    int     axe_y;
    int     axe_x;

}               t_map_params;

/* Struct qui pointe sur chacun des sprites qui remplaceront les valeurs de ma map.ber */
typedef struct  s_img_params
{
    int     img_l;
    int     img_h;
    void    *img;
    void    *floor;
    void    *wall;
    void    *items;
    void    *player;
    void    *player_down;
    void    *cat_front;
    void    *cat_right;
    void    *exit;

}               t_img_params;

/*  La struct game_params sera la struct principale. 
    - Il sera ensuite possible d'appeler mes autres struct via celle-ci en utilisant les variables créée à cet effet. 
    - La variable img permettra d'atteindre la struct qui gère les paramètres de mes sprites. Pareil pour la variable img_params qui sera un tableau
    - La variable map permettra d'atteindre la struct qui gère les paramètre de la map.
*/
typedef struct s_game_params
{
    t_img_params    img;
    t_img_params    **img_params;
    t_map_params    map;
    void    *mlx_ptr;
    void    *win_ptr;
    int     win_h;
    int     win_l;
    int     y;
    int     x;
    int     pos_y;
    int     pos_x;
    int     moves;

}               t_game_params;

#endif