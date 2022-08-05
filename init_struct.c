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