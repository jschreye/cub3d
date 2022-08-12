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

#include "cub3d.h"

void ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int ft_close()
{
    exit(0);
}

int main(int argc, char **argv)
{
	t_data data;

    if (argc != 2)
		exit (0);
	ft_check_map_cub(argv[1]);
	ft_init_struct_pars(&data);
	ft_init_struct_key(&data);
	data.pars.fd = open(argv[1], O_RDONLY);	
	ft_check_cub(&data);
	close(data.pars.fd);
	ft_init_struct_win(&data);
	ft_init_world(&data);
	ft_init_texture(&data);
	ft_init_map(&data);
	ft_get_image(&data, '1');
	mlx_hook(data.win.mlx_win, 17, 1L<<0, ft_close, &data);
    mlx_loop(data.win.mlx);
	//while (1)
	//{}
    return (0);
}