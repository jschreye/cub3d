#include "cub3d.h"

void ft_init_struct_pars(t_data *data)
{
    data->pars.floor = NULL;
    data->pars.roof = NULL;
    data->pars.pl_x = 0;
    data->pars.pl_y = 0;
    data->pars.map_h = 0;
    data->pars.map_w = 0;   
    data->pars.no_texture = NULL;
    data->pars.so_texture = NULL;
    data->pars.we_texture = NULL;
    data->pars.ea_texture = NULL;
    data->pars.map = NULL;
}

void ft_init_struct_truc(t_truc *t)
{
    t->i = 0;
    t->j = 0;
    t->k = 0;
    t->tmp = NULL;
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