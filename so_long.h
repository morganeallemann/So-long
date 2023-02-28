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
# define GAMEOVER "images/game_over.xpm"
# define WINNER "images/winner.xpm"

/* Definition des touches de mouvement */
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

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
    int     ennemies;
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
    void    *game_over;
    void    *winner;
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
    int     items;

}               t_game_params;

/*  Fonctions qui gerent les parametres de la map. */
int     get_nbr_lines(char *map_fd);
void    memset_range_line(int range, int col, int i, t_game_params *game);
void    stock_map(char *map_fd, t_game_params *game);
void    map_init(t_game_params *game);
int    close_game(void *game);

/* Fonctions qui gerent les parametres de la fenetre. */
int     window_init(t_game_params *game);
int     put_map_on_windows(t_game_params *game);

/* Fonctions qui gerent les parametre des images. */
void    images_init(t_game_params *game);
void    define_sprite(t_game_params *game, int width, int y, int x);

/* Fonction qui gerent les paramètres du joueur. */
void    player_init(t_game_params *game);
void    player_move(int keycode, t_game_params *game);
void    player_move_down(t_game_params *game);
void    player_move_left(t_game_params *game);
void    player_move_right(t_game_params *game);
void    game_over(t_game_params *game);
void    winner(t_game_params *game);
void    ennemies_animations(t_game_params *game, int width, int y);

/* Fonctions qui gèrent les paramètres des événements clavier. */
int     event_key(int keycode, t_game_params *game);

/* Autres fonctions utiles. */
void    ft_free(char **tab);

#endif
