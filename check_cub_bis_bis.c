/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_bis_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:11:45 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/17 10:47:16 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_arg(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (1);
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isalpha(tab[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 9)
			return (0);
		i++;
	}
	return (1);
}

unsigned long	ft_create_rgb(int t, int r, int g, int b)
{
	return (((t & 0xFF) << 24) + ((r & 0xFF) << 16) + \
			((g & 0xFF) << 8) + (b & 0xFF));
}

void	ft_get_color(t_data *data)
{
	data->pars.hex_f = ft_create_rgb(0, data->pars.floor[0],
		data->pars.floor[1], data->pars.floor[2]);
	data->pars.hex_s = ft_create_rgb(0, data->pars.roof[0],
		data->pars.roof[1], data->pars.roof[2]);
}