/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:50:25 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/19 09:33:48 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hori_loop(t_parsing *pars, t_map *map, t_ray *ray)
{
	while (++ray->i < pars->map_h - 2)
	{
		ray->hmx = ((int) ray->x) / map->map_size;
		ray->hmy = ((int) ray->y) / map->map_size;
		if (ray->x >= 0 && ray->x < map->w && ray->y >= 0 && ray->y < map->h
			&& !ft_map_char(pars->map[ray->hmy + ray->h_shift][ray->hmx]))
		{
			ray->hx = ray->x;
			ray->hy = ray->y;
			ray->dist_h = sqrt(powf((ray->x - map->pos_x), 2)
					+ powf((ray->y - map->pos_y), 2));
			ray->i = pars->map_h;
		}
		else
		{
			ray->x += ray->xo;
			ray->y += ray->yo;
		}
	}
}

void	ft_verti_loop(t_parsing *pars, t_map *map, t_ray *ray)
{
	while (++ray->i < pars->map_w - 2)
	{
		ray->vmx = ((int)ray->x) / map->map_size;
		ray->vmy = ((int)ray->y) / map->map_size;
		if (ray->x >= 0 && ray->x < map->w && ray->y >= 0 && ray->y < map->h
			&& !ft_map_char(pars->map[ray->vmy][ray->vmx + ray->v_shift]))
		{		
			ray->vx = ray->x;
			ray->vy = ray->y;
			ray->dist_v = sqrt(powf((ray->x - map->pos_x), 2)
					+ powf((ray->y - map->pos_y), 2));
			ray->i = pars->map_w;
		}
		else
		{
			ray->x += ray->xo;
			ray->y += ray->yo;
		}
	}
}

void	ft_check_hori_ray(t_parsing *pars, t_map *map, t_ray *ray)
{
	ray->i = -1;
	ray->h_shift = 0;
	if (map->a_deg > 0 && map->a_deg < 180)
	{
		ray->y = ((int)(map->pos_y / map->map_size)) * map->map_size;
		ray->x = (map->pos_y - ray->y) * ray->atan + map->pos_x;
		ray->yo = -map->map_size;
		ray->xo = -ray->yo * ray->atan;
		ray->h_shift = -1;
	}
	else if (map->a_deg > 180)
	{
		ray->y = ((int)(map->pos_y / map->map_size)) * map->map_size
			+ map->map_size;
		ray->x = (map->pos_y - ray->y) * ray->atan + map->pos_x;
		ray->yo = map->map_size;
		ray->xo = -ray->yo * ray->atan;
	}
	else
	{
		ray->y = map->pos_y;
		ray->x = map->pos_x;
		ray->i = pars->map_h;
	}
	ft_hori_loop(pars, map, ray);
}

void	ft_check_verti_ray(t_parsing *pars, t_map *map, t_ray *ray)
{
	ray->i = -1;
	ray->v_shift = 0;
	if (map->a_deg > 90 && map->a_deg < 270)
	{
		ray->x = ((int)(map->pos_x / map->map_size)) * map->map_size;
		ray->y = (map->pos_x - ray->x) * ray->ntan + map->pos_y;
		ray->xo = -map->map_size;
		ray->yo = -ray->xo * ray->ntan;
		ray->v_shift = -1;
	}
	else if (map->a_deg < 90 || map->a_deg > 270)
	{
		ray->x = ((int)(map->pos_x / map->map_size)) * map->map_size
			+ map->map_size;
		ray->y = (map->pos_x - ray->x) * ray->ntan + map->pos_y;
		ray->xo = map->map_size;
		ray->yo = -ray->xo * ray->ntan;
	}
	else
	{
		ray->y = map->pos_y;
		ray->x = map->pos_x;
		ray->i = pars->map_w;
	}
	ft_verti_loop(pars, map, ray);
}

void	ft_compare_rays(t_data *data)
{
	if (data->ray.dist_v != 0
		&& (data->ray.dist_h == 0 || data->ray.dist_v < data->ray.dist_h))
	{
		data->ray.x = data->ray.vx;
		data->ray.y = data->ray.vy;
		data->ray.wx = data->ray.x / data->map.map_size;
		data->ray.wy = data->ray.y / data->map.map_size;
		data->ray.dist = data->ray.dist_v;
		data->ray.cross = 'v';
		data->ray.char_map
			= data->pars.map[data->ray.vmy][data->ray.vmx + data->ray.v_shift];
		ft_check_char_map(data);
	}
	else
	{
		data->ray.x = data->ray.hx;
		data->ray.y = data->ray.hy;
		data->ray.wx = data->ray.x / data->map.map_size;
		data->ray.wy = data->ray.y / data->map.map_size;
		data->ray.dist = data->ray.dist_h;
		data->ray.cross = 'h';
		data->ray.char_map
			= data->pars.map[data->ray.hmy + data->ray.h_shift][data->ray.hmx];
		ft_check_char_map(data);
	}
}
