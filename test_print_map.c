#include "cub3d.h"

void ft_boucle(t_data *data)
{
    int i;
    int j;
    int h;
    int w;
    i = 0;
    data->img.coory = 0;
    while (data->tab_map[i])
    {
        j = 0;
        data->img.coorx = 0;
        while (data->tab_map[i][j])
        {
            if (data->tab_map[i][j] == 'N')
               break; 
            data->img.coorx += 30;
            j++;
        }
        if (data->tab_map[i][j] == 'N')
            break; 
        data->img.coory += 30;
        i++;
    }
     data->img.img  = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
}
void ft_move_up(t_data *data)
{
    int w;
    int h;

    if (data->c == 0)
    {
        ft_boucle(data);
        data->c++;
    }
    if (data->cy == 0)
        data->cy = data->img.coory;
    if (data->cy < data->img.coory)
    {
        data->cy += 30;
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->cy);
        data->cy -= 30;
    }
    else
    {
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->cy);
    }
    data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->cy);
    data->img.coory -= 5;
    if (data->img.coory == data->cy - 30)
        data->cy = data->img.coory;
    data->img.img  = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
}

void ft_move_down(t_data *data)
{
    int w;
    int h;

    if (data->c == 0)
    {
        ft_boucle(data);
        data->c++;
    }
    if (data->cy == 0)
        data->cy = data->img.coory;
    if (data->cy > data->img.coory)
    {
        data->cy -= 30;
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->cy);
        data->cy += 30;
    }
    else
    {
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->cy);
    }
    data->img.coory += 5;
    if (data->img.coory == data->cy + 30)
        data->cy = data->img.coory;
    data->img.img  = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
}

void ft_move_left(t_data *data)
{
    int w;
    int h;

    if (data->c == 0)
    {
        ft_boucle(data);
        data->c++;
    }
    if (data->cx == 0)
        data->cx = data->img.coorx;
    if (data->cx < data->img.coorx)
    {
        data->cx += 30;
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->cx, data->img.coory);
        data->cx -= 30;
    }
    else
    {
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->cx, data->img.coory);
    }
    data->img.coorx -= 5;
    if (data->img.coorx == data->cx - 30)
        data->cx = data->img.coorx;
    data->img.img  = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
}

void ft_move_right(t_data *data)
{
    int w;
    int h;

    if (data->c == 0)
    {
        ft_boucle(data);
        data->c++;
    }
    if (data->cx == 0)
        data->cx = data->img.coorx;
    if (data->cx > data->img.coorx)
    {
        data->cx -= 30;
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->cx, data->img.coory);
        data->cx += 30;
    }
    else
    {
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->cx, data->img.coory);
    }
    data->img.coorx += 5;
    if (data->img.coorx == data->cx + 30)
        data->cx = data->img.coorx;
    data->img.img  = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
}

int    ft_check_key(int keycode, t_data *data)
{
    data->keycode_value = keycode;
    if (keycode == 53)
        exit(0);
    if (keycode == 13 || keycode == 126)
        ft_move_up(data);
    if (keycode == 0 || keycode == 123)
        ft_move_left(data);
    if (keycode == 1 || keycode == 125)
        ft_move_down(data);
    if (keycode == 2 || keycode == 124)
        ft_move_right(data);
    return (0);
}

void ft_attribute_img(t_data *data, char c)
{
    int w;
    int h;

    if (c == 48)
    {
        data->img.img = mlx_xpm_file_to_image(data->mlx, data->no_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
    }
    if (c == 49)
    {
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->so_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
    }
    if (c == 78 || c == 83 || c == 69 || c == 87)
    {
        data->img.img  = mlx_xpm_file_to_image(data->mlx, data->we_texture, &w, &h);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img , data->img.coorx, data->img.coory);
    }
}

void ft_print_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->tab_map[i])
    {
        j = 0;
        data->img.coorx = 0;
        while (data->tab_map[i][j])
        {
            ft_attribute_img(data, data->tab_map[i][j]);
            data->img.coorx += 30;
            j++;
        }
        data->img.coory += 30;
        i++;
    }
    data->img.img = NULL;
}