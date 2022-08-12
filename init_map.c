#include "cub3d.h"

float ft_deg_to_rad(int angle)
{
    return (angle * 3.1415926535 / 180);
}

float ft_rad_to_deg(int angle)
{
    return (angle / 3.1415926535 * 180);
}

static int ft_get_map_size(int width, int height)
{
    int max_w;
    int max_h;
    int size1;
    int size2;

    max_w = (960 / 2) - (2 * 5);
    max_h = 120 - (2 * 5);
    size1 = max_w / width;
    size2 = max_h / height;
    if (size1 > size2)
        return (size2);
    return (size1);
}

void ft_init_map(t_data *data)
{
    data->map.map_size = ft_get_map_size(data->pars.map_w,
        data->pars.map_h);
    data->map.w = data->pars.map_w * data->map.map_size;
    data->map.h = data->pars.map_h * data->map.map_size;
    data->map.h_offset = data->win.world_h + 5 + ((120 - (2 * 5))
        - data->map.h) / 2;
    data->map.w_offset = (data->win.width - (2 * 5) - data->map.w) / 2;
    data->map.pos_x = (data->pars.pl_x * data->map.map_size)
        + (0.5 * data->map.map_size) - (0.5 * 3);
    data->map.pos_y = (data->pars.pl_y * data->map.map_size)
        + (0.5 * data->map.map_size) - (0.5 * 3);
    data->map.prev_x = data->map.pos_x;
    data->map.prev_y = data->map.pos_y;
    if (data->pars.player == 'N')
        data->map.a_rad = ft_deg_to_rad(90);
    else if (data->pars.player == 'S')
        data->map.a_rad = ft_deg_to_rad(270);
    else if (data->pars.player == 'E')
        data->map.a_rad = ft_deg_to_rad(0);
    else if (data->pars.player == 'W')
        data->map.a_rad = ft_deg_to_rad(180);
    data->map.a_deg = ft_rad_to_deg(data->map.a_rad);
    data->map.delta_x = cos(-data->map.a_rad);
    data->map.delta_y = sin(-data->map.a_rad);
}