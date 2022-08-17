/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:56:51 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/17 18:21:25 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting(t_data *data)
{
	data->map.pos_x += 1.5;
	data->map.pos_y += 1.5;
	data->map.pl_angle = data->map.a_rad;
	data->map.a_rad += data->ray.fov_05;
	ft_check_angle(data->map.a_rad, &data->map.a_deg);
	data->ray.rays = -1;
	data->ray.ix = 0;
	printf("ray.y1 = %f\n ray.x2 = %f\n", data->ray.y, data->ray.x);
	while (++data->ray.rays < data->ray.r_1)
	{
		data->ray.dist_v = 0;
		data->ray.dist_h = 0;
		data->ray.atan = -1 / tan(-data->map.a_rad);
		data->ray.ntan = -tan(-data->map.a_rad);
		data->ray.spe = '0';
		ft_check_hori_ray(&data->pars, &data->map, &data->ray);
		ft_check_verti_ray(&data->pars, &data->map, &data->ray);
		ft_compare_rays(data);
		ft_get_3d(data, &data->ray);
		data->map.a_rad -= data->ray.r_ra;
		ft_check_angle(data->map.a_rad, &data->map.a_deg);
	}
	data->map.pos_x -= 1.5;
	data->map.pos_y -= 1.5;
	data->map.a_rad += data->ray.fov_05;
	data->map.a_deg = ft_rad_to_deg(data->map.a_rad);
}
