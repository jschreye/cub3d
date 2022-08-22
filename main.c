/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:45:29 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/22 10:00:29 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_close(t_data *data)
{
	mlx_clear_window(data->win.mlx, data->win.mlx_win);
	mlx_destroy_window(data->win.mlx, data->win.mlx_win);
	printf("Program left properly.\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit (0);
	ft_check_map_cub(argv[1]);
	ft_init_struct_pars(&data);
	ft_init_struct_key(&data);
	data.pars.fd = open(argv[1], O_RDONLY);
	ft_check_cub(&data);
	close(data.pars.fd);
	ft_new_map(&data);
	ft_init_struct_win(&data);
	ft_init_world(&data);
	ft_init_texture(&data);
	ft_init_map(&data);
	ft_get_image(&data);
	mlx_hook(data.win.mlx_win, 2, 0, ft_key_press, &data);
	mlx_hook(data.win.mlx_win, 3, 0, ft_key_release, &data);
	mlx_hook(data.win.mlx_win, 17, 1L << 0, ft_close, &data);
	mlx_loop_hook(data.win.mlx, ft_events_loop, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
