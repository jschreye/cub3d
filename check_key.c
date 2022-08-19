/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:44:27 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/19 14:38:13 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int k, t_data *data)
{
	if (k == 13)
		data->key.w = 1;
	else if (k == 1)
		data->key.s = 1;
	else if (k == 0)
		data->key.a = 1;
	else if (k == 2)
		data->key.d = 1;
	else if (k == 124)
		data->key.left = 1;
	else if (k == 123)
		data->key.right = 1;
	return (0);
}

int	ft_key_release(int k, t_data *data)
{
	if (k == 13)
		data->key.w = 0;
	else if (k == 1)
		data->key.s = 0;
	else if (k == 0)
		data->key.a = 0;
	else if (k == 2)
		data->key.d = 0;
	else if (k == 124)
		data->key.left = 0;
	else if (k == 123)
		data->key.right = 0;
	else if (k == 53)
		ft_close(data);
	return (0);
}
