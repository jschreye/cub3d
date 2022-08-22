/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:00:08 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/22 11:56:20 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_color_shade(float ray_a, t_ray *ray)
{
	if (ray->cross == 'v')
	{
		if (ray_a > 90 && ray_a < 270)
			return (0.5);
		else
			return (1);
	}
	else if (ray->cross == 'h')
	{
		if (ray_a > 0 && ray_a < 180)
			return (0.8);
		else
			return (0.6);
	}
	return (1);
}

unsigned int	ft_get_tex_color(t_img *tex, int x, int y, float shade)
{
	unsigned int	clr;
	int				t;
	int				r;
	int				g;
	int				b;

	clr = *(unsigned int *)(tex->addr + (y * tex->ll + x * (tex->bpp / 8)));
	t = ((clr >> 24) & 0xFF);
	r = ((clr >> 16) & 0xFF) * shade;
	g = ((clr >> 8) & 0xFF) * shade;
	b = (clr & 0xFF) * shade;
	return (((t & 0xFF) << 24) + ((r & 0xFF) << 16)
		+ ((g & 0xFF) << 8) + (b & 0xFF));
}
