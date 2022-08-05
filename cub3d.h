/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:45:29 by jschreye          #+#    #+#             */
/*   Updated: 2022/07/11 13:34:44 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_truc
{
    int i;
    int j;
    int k;
    char *tmp;
}               t_truc;

typedef struct s_count
{
    int no;
    int so;
    int we;
    int ea;
    int f;
    int c;
} t_count;

typedef struct s_img
{
    int loc_p_i;
    int loc_p_y;
    int coor_x;
    int coor_y;
    void *img;
} t_img;

typedef struct s_data
{
    int     fd;
    int     *floor;
    int     *roof;
    int     keycode_value;
    void    *mlx;
    void    *mlx_win;
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    char    **tab_map;
}   t_data;

void    ft_check_cub(t_data *data);
void    ft_print_tab(char **tab);
void    ft_free_tab(char **tab);
void    ft_init_struct_data(t_data *data);
void ft_init_struct_count(t_count *count);
void ft_print_error_cub(char **tab);
void    ft_atoi_arg(int *tab_int, char **tab);
void ft_registre_path_bis(t_data *data, char *str_tab, char *str, t_count *count);
void ft_registre_path(t_data *data, char *str_tab, char *str, t_count *count);
void ft_check_error_count(t_count *count);
void    ft_check_tab_data(t_data *data, char **tab);
int ft_check_arg(char **tab);
int ft_check_space(char *str);
void    ft_delete_space(char **tab);
void ft_print_error_map(char **tab);
void ft_check_map(t_data *data);
void ft_check_p(t_data *data);
void    ft_check_char_map(t_data *data);
int ft_count_tab(char **tab);
void ft_check_border(t_data *data);
void ft_init_struct_img(t_img *img);
void ft_print_map(t_data *data, t_img *img);

#endif