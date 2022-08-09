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
	//int w = -1;
	//int x = 0;
    //int x = 500;
    //int y = 500;
    if (argc != 2)
		exit (0);
	ft_check_map_cub(argv[1]);
	ft_init_struct_data(&data);
	ft_init_struct_img(&data);
	data.fd = open(argv[1], O_RDONLY);
	ft_check_cub(&data);
	close(data.fd);
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, data.img.screenw, data.img.screenh, "name_of_window");
	ft_print_map(&data);
	
    mlx_key_hook(data.mlx_win, ft_check_key, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, ft_close, &data);
    mlx_loop(data.mlx);
	//while (1)
	//{}
    return (0);
}