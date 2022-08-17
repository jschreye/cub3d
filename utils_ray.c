/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:58:25 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/17 17:51:48 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_angle(float angle, int *deg)
{
	if (angle < 0)
		angle += 6.2831853071;
	if (angle > 6.2831853071)
		angle -= 6.2831853071;
	*deg = ft_rad_to_deg(angle);
}

void	check_char_map(t_data *data)
{
	if (data->ray.char_map != '1')
		data->ray.spe = data->ray.char_map;
}

float	ft_fix_fisheye(float angle)
{
	if (angle < 0)
		angle += 6.2831853071;
	if (angle > 6.2831853071)
		angle -= 6.2831853071;
	return (cos(angle));	
}

void	ft_draw_v_line(t_image *image, t_ray *ray, int color)
{
	float	d_x;
	float	d_y;
	int		pix;
	float	p_x;
	float	p_y;

	d_x = 0;
	d_y = ray->y2 - ray->y1;
	pix = sqrt((d_x * d_x) + (d_y * d_y));
	d_x /= pix;
	d_y /= pix;
	p_x = ray->ix;
	p_y = ray->y1;
	while (pix)
	{
		my_mlx_pixel_put(image, p_x, p_y, color);
		p_x += d_x;
		p_y += d_y;
		--pix;
	}
}

void	ft_wall_texture(t_data *data, t_ray *ray)
{
	ray->iy = -1;
	ray->ty = ray->to * ray->ty_step;
	while (++ray->iy < ray->w_bot)
	{
		ray->c = ft_get_tex_color(ray->tex, ray->tx, ray->ty, ray->shade);
		/*printf("c = %d\n", ray->c);
		//printf("tex = %d\n", ray->tex);
		printf("tx = %f\n", ray->tx);
		printf("ty = %f\n", ray->ty);
		printf("shade = %f\n", ray->shade);*/
		exit(0);
		my_mlx_pixel_put(&data->world, ray->ix, ray->iy + ray->w_top, ray->c);
		ray->ty += ray->ty_step;
	}
}