/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:48:40 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/17 13:39:08 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_collision_check(t_map *map, t_grid *grid, char k)
{
	grid->of = 4;
	if (k == 'w')
		grid->of = 2;
	grid->xo = 0;
	if (map->delta_x < 0)
		grid->xo = -grid->of;
	else
		grid->xo = grid->of;
	grid->yo = 0;
	if (map->delta_y < 0)
		grid->yo = -grid->of;
	else
		grid->yo = grid->of;
	grid->vo = -1;
	grid->ho = -1;
	if (map->a_deg > 180)
		grid->vo += 3;
	if (map->a_deg < 90 || map->a_deg > 270)
		grid->ho += 3;
	grid->mx = (map->pos_x + grid->ho) / map->map_size;
	grid->mx_add_xo = (map->pos_x + grid->ho + grid->xo) / map->map_size;
	grid->mx_sub_xo = (map->pos_x + grid->ho - grid->xo) / map->map_size;
	grid->my = (map->pos_y + grid->vo) / map->map_size;
	grid->my_add_yo = (map->pos_y + grid->vo + grid->yo) / map->map_size;
	grid->my_sub_yo = (map->pos_y + grid->vo - grid->yo) / map->map_size;
}

void	ft_a_move(t_data *data, t_map *map)
{
	t_grid	g;
	
	map->a_rad += 1.57079632679;
	if (map->a_rad > 6.2831853071)
		map->a_rad -= 6.2831853071;
	map->delta_x = cos(-map->a_rad);
	map->delta_y = sin(-map->a_rad);
	ft_collision_check(map, &g, 'a');
	if (ft_map_char(data->pars.map[g.my][g.mx_add_xo]))
		map->pos_x += map->delta_x * map->ad_fps;
	if (ft_map_char(data->pars.map[g.my_add_yo][g.mx]))
		map->pos_y += map->delta_y * map->ad_fps;
	map->a_rad -= 1.57079632679;
	if (map->a_rad < 0)
		map->a_rad += 6.2831853071;
	map->delta_x = cos(-map->a_rad);
	map->delta_y = sin(-map->a_rad);
}

void	ft_d_move(t_data *data, t_map *map)
{
	t_grid	g;
	
	map->a_rad -= 1.57079632679;
	if (map->a_rad < 0)
		map->a_rad += 6.2831853071;
	map->delta_x = cos(-map->a_rad);
	map->delta_y = sin(-map->a_rad);
	ft_collision_check(map, &g, 'a');
	if (ft_map_char(data->pars.map[g.my][g.mx_add_xo]))
		map->pos_x += map->delta_x * map->ad_fps;
	if (ft_map_char(data->pars.map[g.my_add_yo][g.mx]))
		map->pos_y += map->delta_y * map->ad_fps;
	map->a_rad += 1.57079632679;
	if (map->a_rad > 6.2831853071)
		map->a_rad -= 6.2831853071;
	map->delta_x = cos(-map->a_rad);
	map->delta_y = sin(-map->a_rad);
}

void	ft_move(t_data *data, char dir)
{
	data->map.prev_x = data->map.pos_x;
	data->map.prev_y = data->map.pos_y;
	if (dir == 'w')
	{
		ft_collision_check(&data->map, &data->grid, 'w');
		if (ft_map_char(data->pars.map[data->grid.my][data->grid.mx_add_xo]))
			data->map.pos_x += data->map.delta_x * data->map.ws_fps;
		if (ft_map_char(data->pars.map[data->grid.my_add_yo][data->grid.mx]))
			data->map.pos_y += data->map.delta_y * data->map.ws_fps;
	}
	else if (dir == 's')
	{
		ft_collision_check(&data->map, &data->grid, 's');
		if (ft_map_char(data->pars.map[data->grid.my][data->grid.mx_sub_xo]))
			data->map.pos_x -= data->map.delta_x * data->map.ws_fps;
		if (ft_map_char(data->pars.map[data->grid.my_sub_yo][data->grid.mx]))
			data->map.pos_y -= data->map.delta_y * data->map.ws_fps;
	}
	else if (dir == 'a')
		ft_a_move(data, &data->map);
	else if (dir == 'd')
		ft_d_move(data, &data->map);
	ft_get_image(data);
}

void	ft_rotation(t_data *data, char dir)
{
	if (dir == 'l')
	{
		data->map.a_rad -= 0.0087266465 * data->map.rot_fps;
		if (data->map.a_rad < 0)
			data->map.a_rad += 6.2831853071;
	}
	else if (dir == 'r')
	{
		data->map.a_rad += 0.0087266465 * data->map.rot_fps;
		if (data->map.a_rad > 6.2831853071)
			data->map.a_rad -= 6.2831853071;
	}
	data->map.a_deg = ft_rad_to_deg(data->map.a_rad);
	data->map.delta_x = cos(-data->map.a_rad);
	data->map.delta_y = sin(-data->map.a_rad);
	ft_get_image(data);
}
