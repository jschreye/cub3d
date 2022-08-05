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

int	ft_check_key(int keycode, void *img, void *ptr, int x, int y)
{
    
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126)
		mlx_pixel_put(img, ptr, x -= 5, y, 0xff00ff);
	if (keycode == 1 || keycode == 125)
		mlx_pixel_put(img, ptr, x += 5, y, 0xff00ff);
	if (keycode == 2 || keycode == 124)
		mlx_pixel_put(img, ptr, x, y -= 5, 0xff00ff);
	if (keycode == 0 || keycode == 123)
		mlx_pixel_put(img, ptr, x, y += 5, 0xff00ff);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;
    //int x = 500;
    //int y = 500;
    if (argc != 2)
		exit (0);
	ft_init_struct_data(&data);
	data.fd = open(argv[1], O_RDONLY);
	ft_check_cub(&data);
    /*data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "name_of_window");
    mlx_pixel_put(data.mlx, data.mlx_win, x, y, 0xff00ff);
    mlx_key_hook(data.mlx_win, ft_check_key, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, ft_close, &data);
    mlx_loop(data.mlx);*/
	while (1)
	{}
    return (0);
}
	//int i = 0;
	// ft_print_tab(data.tab_map);
	// printf("%s\n", data.no_texture);
	// printf("%s\n", data.so_texture);
	// printf("%s\n", data.we_texture);
	// printf("%s\n", data.ea_texture);
	// while (i < 3)
	// {
	// 	printf("%d\n", data.floor[i]);
	// 	printf("%d\n", data.roof[i]);
	// 	i++;
	// }