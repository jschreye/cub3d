
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

typedef struct s_parsing
{
    int     fd;
    int     *floor;
    int     *roof;
    int     pl_x;
    int     pl_y;
    int     map_h; //pas enregister
    int     map_w; //pas enregister  
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    char    **map;
}   t_parsing;

typedef struct s_window
{
    void    *mlx;
    void    *mlx_win;
}   t_window;

typedef struct s_data
{
    t_window win;
    t_parsing pars;
}   t_data;

 // initialisation
void    ft_init_struct_pars(t_data *data);
void    ft_init_struct_truc(t_truc *t);
void ft_init_struct_count(t_count *count);

// print error
void    ft_print_error_cub(char **tab);
void ft_print_error_map(char **tab);
void    ft_check_map_cub(char *argv);

// parsing_cub
void    ft_check_cub(t_data *data);
int ft_check_space(char *str);
void    ft_check_tab_data(t_data *data, char **tab);
void    ft_delete_space(char **tab);
int ft_check_arg(char **tab);

//parsing_map
void    ft_check_map(t_data *data);
void    ft_check_char_map(t_data *data);
void ft_check_border(t_data *data);
void ft_check_p(t_data *data);

//utils
void ft_free_tab(char **tab);
void ft_print_tab(char **tab);
int ft_close();

#endif