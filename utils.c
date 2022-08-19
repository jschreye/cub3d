/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:29:51 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/19 14:02:41 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count - 1);
}

int	ft_map_char(char c)
{
	if (c == '1')
		return (0);
	return (1);
}
