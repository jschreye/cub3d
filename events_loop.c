/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:45:45 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/19 13:48:31 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_events_loop(t_data *data)
{
	if (data->key.w == 1)
		ft_move(data, 'w');
	if (data->key.s == 1)
		ft_move(data, 's');
	if (data->key.a == 1)
		ft_move(data, 'a');
	if (data->key.d == 1)
		ft_move(data, 'd');
	if (data->key.left == 1)
		ft_rotation(data, 'l');
	if (data->key.right == 1)
		ft_rotation(data, 'r');
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->world.image,
		data->win.margin_w, data->win.margin_h);
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,
		data->maping.image, data->win.margin_w + data->map.w_offset,
		data->win.margin_h + data->map.h_offset);
	return (0);
}
