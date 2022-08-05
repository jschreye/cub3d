#include "cub3d.h"

void ft_attribute_img(t_data *data, t_img *img, char c)
{
    int w;
    int h;

    if (c == 48)
    {
        img->img = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
         mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, img->coor_x, img->coor_y);
    }
    if (c == 49)
    {
        img->img = mlx_xpm_file_to_image(data->mlx, data->so_texture, &w, &h);
         mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, img->coor_x, img->coor_y);
    }
    if (c == 78 || c == 83 || c == 69 || c == 87)
    {
        img->img = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
         mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, img->coor_x, img->coor_y);
    }
}

void ft_print_map(t_data *data, t_img *img)
{
    int i;
    int j;

    i = 0;
    while (data->tab_map[i])
    {
        j = 0;
        img->coor_x = 0;
        while (data->tab_map[i][j])
        {
            ft_attribute_img(data, img, data->tab_map[i][j]);
            img->coor_x += 30;
            j++;
        }
        img->coor_y += 30;
        i++;
    }
}