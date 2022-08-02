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

/*int	ft_check_key(int keycode, void *img, void *ptr, int x, int y)
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
}*/

int	ft_close(void)
{
	exit(0);
}


int main(int argc, char **argv)
{
    void *img;
    void *ptr;
	int fd;
    int x = 500;
    int y = 500;
	if (argc <= 1)
		exit(0);
	fd = open(argv[1], O_RDONLY);
    img = mlx_init();
    ptr = mlx_new_window(img, 1000, 1000, "super super");
	while (x > 1 && y < 1000)
	{
    	mlx_pixel_put(img, ptr, x, y, 0xff00ff);
		x--;
		y++;
	}
    mlx_key_hook(ptr, ptr, ptr);
    mlx_loop(img);
    return (0);
}