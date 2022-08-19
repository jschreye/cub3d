/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:45:55 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/19 13:52:12 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_new_pos(t_image *maping, t_map *map, int color)
{
	int	w;
	int	h;

	h = 0;
	while (++h < 3)
	{
		w = 0;
		while (++w < 3)
			my_mlx_pixel_put(maping, (int)map->pos_x + w,
				(int)map->pos_y + h, color);
	}
}

void	ft_new_fov(t_image *maping, t_map *map)
{
	float	px_x;
	float	px_y;
	int		px;

	px_x = map->pos_x;
	px_y = map->prev_y;
	px = map->map_size;
	while (px)
	{
		my_mlx_pixel_put(maping, px_x + 1.5, px_y + 1.5, 0x0000FF00);
		px_x += map->delta_x;
		px_y += map->delta_y;
		px--;
	}
}

void	ft_get_image(t_data *data)
{
	ft_raycasting(data);
}
