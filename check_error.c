/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:45:29 by jschreye          #+#    #+#             */
/*   Updated: 2022/07/11 13:34:44 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx/mlx.h"
#include <stdlib.h>

void	ft_check_map_cub(char *argv)
{
	int	size;

	size = ft_strlen(argv);
	if (argv[size - 1] != 'b' || argv[size - 2] != 'u' || argv[size - 3] != 'c'
		|| argv[size - 4] != '.')
	{
		write (1, "Error\n IS NOT A .BER", 20);
		exit(0);
	}
}

