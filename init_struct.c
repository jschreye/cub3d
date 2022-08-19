/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:29:40 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/19 15:05:04 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct_pars(t_data *data)
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

void	ft_init_struct_key(t_data *data)
{
	data->key.a = 0;
	data->key.d = 0;
	data->key.left = 0;
	data->key.right = 0;
	data->key.s = 0;
	data->key.w = 0;
}

void	ft_init_struct_truc(t_truc *t)
{
	t->i = 0;
	t->j = 0;
	t->k = 0;
	t->tmp = NULL;
}

void	ft_init_struct_count(t_count *count)
{
	count->no = 0;
	count->so = 0;
	count->we = 0;
	count->ea = 0;
	count->f = 0;
	count->c = 0;
}

void	ft_init_struct_win(t_data *data)
{
	data->win.mlx = mlx_init();
	data->win.win_h = 0;
	data->win.win_w = 0;
	data->win.win_h = 1080;
	data->win.win_w = 1920;
	if (data->win.win_w > 0 && data->win.win_h > 0)
	{
		data->win.margin_w = (data->win.win_w - 960) / 2;
		data->win.margin_h = (data->win.win_h - 800) / 2;
	}
	else
	{
		data->win.win_w = 960;
		data->win.win_h = 800;
		data->win.margin_h = 0;
		data->win.margin_w = 0;
	}
	data->win.mlx_win = mlx_new_window(data->win.mlx,
			data->win.win_w, data->win.win_h, "cub3d");
	data->win.width = 960;
	data->win.heigth = 800;
	data->win.world_h = 680;
}
