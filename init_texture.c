#include "cub3d.h"

void ft_init_texture_bis(t_data *data)
{
    data->ray.tx_e.img = mlx_xpm_file_to_image(data->win.mlx,
        data->pars.ea_texture, &data->ray.tx_e.width, &data->ray.tx_e.heigth);
    if (!data->ray.tx_e.img)
        ft_print_error_texture(data->pars.map);
    else
        data->ray.tx_e.addr = mlx_get_data_addr(data->ray.tx_e.img,
            &data->ray.tx_e.bpp, &data->ray.tx_e.ll, &data->ray.tx_e.e);  
    data->ray.tx_w.img = mlx_xpm_file_to_image(data->win.mlx,
        data->pars.we_texture, &data->ray.tx_w.width, &data->ray.tx_w.heigth);
    if (!data->ray.tx_w.img)
        ft_print_error_texture(data->pars.map);
    else
        data->ray.tx_w.addr = mlx_get_data_addr(data->ray.tx_w.img,
            &data->ray.tx_w.bpp, &data->ray.tx_w.ll, &data->ray.tx_w.e);
}

void ft_init_texture(t_data *data)
{
    data->ray.tx_n.img = mlx_xpm_file_to_image(data->win.mlx,
        data->pars.no_texture, &data->ray.tx_n.width, &data->ray.tx_n.heigth);
    if (!data->ray.tx_n.img)
        ft_print_error_texture(data->pars.map);
    else
        data->ray.tx_n.addr = mlx_get_data_addr(data->ray.tx_n.img,
            &data->ray.tx_n.bpp, &data->ray.tx_n.ll, &data->ray.tx_n.e);
    data->ray.tx_s.img = mlx_xpm_file_to_image(data->win.mlx,
        data->pars.so_texture, &data->ray.tx_s.width, &data->ray.tx_s.heigth);
    if (!data->ray.tx_s.img)
        ft_print_error_texture(data->pars.map);
    else
        data->ray.tx_s.addr = mlx_get_data_addr(data->ray.tx_s.img,
            &data->ray.tx_s.bpp, &data->ray.tx_s.ll, &data->ray.tx_s.e);
    ft_init_texture_bis(data);
}