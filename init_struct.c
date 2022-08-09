#include "cub3d.h"

void ft_init_struct_data(t_data *data)
{
    data->floor = NULL;
    data->roof = NULL;
    data->no_texture = NULL;
    data->so_texture = NULL;
    data->we_texture = NULL;
    data->ea_texture = NULL;
    data->tab_map = NULL;
    data->keycode_value = 0;
    data->cy = 0;
    data->cx = 0;
    data->c = 0;
}

void ft_init_struct_count(t_count *count)
{
    count->no = 0;
    count->so = 0;
    count->we = 0;
    count->ea = 0;
    count->f = 0;
    count->c = 0;
}

void ft_init_struct_img(t_data *data)
{
    data->img.screenw = 640;//largeur ecran en px
    data->img.screenh = 480;//hauteur ecran en px
    data->img.mapw = 0;//nombre de colonne de la map
    data->img.maph = 0;//nombre de ligne de la map
    data->img.posx = 0;//position joueur
    data->img.posy = 0;//position joueur
    data->img.dirx = 0;//direction du joueur
    data->img.diry = 0;//direction du joueur
    data->img.planex = 0;//le plan camera du joueur (doit être perpendiculaire à la direction)
    data->img.planey = 0.66;//le plan camera du joueur (doit être perpendiculaire à la direction)
    data->img.camerax = 0;
    data->img.raydirx = 0;
    data->img.raydiry = 0;
    data->img.img = NULL;
    data->img.coorx = 0;//pour test (a effacer)
    data->img.coory = 0;//pour test (a effacer)
}