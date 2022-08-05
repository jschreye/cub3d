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

int    ft_check_key(int keycode, t_img *img, t_data *data)
{
    data->keycode_value = keycode;
    if (keycode == 53)
        exit(0);
    if (keycode == 13 || keycode == 126)
        ft_move_up(img);
    if (keycode == 0 || keycode == 123)
        ft_move_left(img);
    if (keycode == 1 || keycode == 125)
        ft_move_down(img);
    if (keycode == 2 || keycode == 124)
        ft_move_right(img);
    return (0);
}

int main(int argc, char **argv)
{
	t_data data;
	t_img img;
    //int x = 500;
    //int y = 500;
    if (argc != 2)
		exit (0);
	ft_init_struct_data(&data);
	ft_init_struct_img(&img);
	data.fd = open(argv[1], O_RDONLY);
	ft_check_cub(&data);
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "name_of_window");
	ft_print_map(&data, &img);

    
    mlx_key_hook(data.mlx_win, ft_check_key, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, ft_close, &data);
    mlx_loop(data.mlx);
	while (1)
	{}
    return (0);
}