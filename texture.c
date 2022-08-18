#include "cub3d.h"

t_img *ft_ray_texture(float ray_a, t_ray *ray)
{
    if (ray->cross == 'v')
    {
        if (ray_a > 90 && ray_a < 270 && ray->tx_w.img)
            return (&ray->tx_w);
        else if ((ray_a < 90 || ray_a > 270) && ray->tx_e.img)
            return (&ray->tx_e);
    }
    else if (ray->cross == 'h')
    {
		if (ray_a > 0 && ray_a < 180 && ray->tx_n.img)
			return (&ray->tx_n);
		else if (ray_a > 180 && ray->tx_s.img)
			return (&ray->tx_s);   
    }
    return (NULL);
}

int ft_ray_color(float ray_a, t_ray *ray)
{
	if (ray->cross == 'v')
	{
		if (ray_a > 90 && ray_a < 270)
			return (0x00101010);
		else
			return (0x00202020);
	}
	else if (ray->cross == 'h')
	{
		if (ray_a > 0 && ray_a < 180)
			return (0x00303030);
		else
			return (0x00000000);
	}
	return (0x00ffffff);
}

void    ft_use_texture(t_data *data, t_ray *ray)
{
    if (ray->cross == 'h')
    {
        ray->tx = (int)((ray->wx - (int)ray->wx) * ray->tex->width);
        if (data->map.a_deg > 180)
            ray->tx = ray->tex->width - ray->tx -1;
    }
    else
    {
		ray->tx = (int)((ray->wy - (int)ray->wy) * ray->tex->width);
		if (data->map.a_deg > 90 && data->map.a_deg < 270)
			ray->tx = ray->tex->width - ray->tx - 1;
    }
    ray->shade = ft_color_shade(data->map.a_deg, ray);
    while(--ray->lpr)
    {
        ray->y1 = 0;
        ray->y2 = ray->w_top;
        ft_draw_v_line(&data->world, ray, data->map.c_ceil);
        ft_wall_texture(data, ray);
		ray->y1 = ray->w_bot + ray->w_top;
		ray->y2 = data->win.world_h;
        ft_draw_v_line(&data->world, ray, data->map.c_floor);
        ray->ix++;
    }
}

void    ft_use_color(t_data *data, t_ray *ray)
{
	while (--ray->lpr)
	{
		ray->y1 = 0;
		ray->y2 = ray->w_top;
		ft_draw_v_line(&data->world, ray, data->map.c_ceil);
		ray->iy = -1;
		while (++ray->iy < ray->w_bot)
			my_mlx_pixel_put(&data->world, ray->ix, ray->iy + ray->w_top, ray->c);
		ray->y1 = ray->w_bot + ray->w_top;
		ray->y2 = data->win.world_h;
		ft_draw_v_line(&data->world, ray, data->map.c_floor);
		ray->ix++;
	}      
}