#include "cub3d.h"

void ft_get_3d(t_data *data, t_ray *ray)
{
    ray->dist *=  ft_fix_fisheye(data->map.pl_angle - data->map.a_rad);
    ray->w_bot = data->win.world_h * data->map.map_size / ray->dist;
    ray->tex = ft_ray_texture(data->map.a_deg, ray);
    if (ray->tex)
    {
        ray->ty_step = ray->tex->heigth / ray->w_bot;
        ray->to = 0;
    }
    else
        ray->c = ft_ray_color(data->map.a_deg, ray);
    if (ray->w_bot > data->win.world_h)
    {
        if (ray->tex)
            ray->to = (ray->w_bot - data->win.world_h) / 2;
        ray->w_bot = data->win.world_h;
    }
    ray->w_top = (data->win.world_h / 2) - (ray->w_bot / 2);
    ray->lpr_cpy = (data->win.width / ray->r_1) + 1;
    ray->lpr = ray->lpr_cpy;
    if (ray->tex)
        ft_use_texture(data, ray);
    else
        ft_use_color(data, ray);
}