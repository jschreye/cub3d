/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:00:46 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/15 14:02:13 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
}

void	ft_init_world(t_data *data)
{
	int	x;
	int	y;

	data->world.image = mlx_new_image(data->win.mlx, data->win.width,
			data->win.world_h);
	data->world.addr = mlx_get_data_addr(data->world.image,
			&data->world.bits_per_pixel, &data->world.line_length,
			&data->world.endian);
	y = -1;
	while (++y < data->win.world_h)
	{
		x = -1;
		while (++x < data->win.width)
			my_mlx_pixel_put(&data->world, x, y, 0x00505050);
	}
}
