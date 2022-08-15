
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <CoreGraphics/CGDisplayConfiguration.h>

typedef struct s_map
{
	int		map_size;
	int		w;
	int		h;
	int		h_offset;
	int		w_offset;
	float	pos_x;
	float	pos_y;
	float	prev_x;
	float	prev_y;
	float	a_rad;
	int		a_deg;
	float	delta_x;
	float	delta_y;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;
	int		width;
	int		heigth;
	int		bpp;
	int		ll;
	int		e;
}			t_img;

typedef struct s_ray
{
	t_img	tx_n;
	t_img	tx_w;
	t_img	tx_e;
	t_img	tx_s;
}			t_ray;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}		t_key;

typedef struct s_truc
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
}			t_truc;

typedef struct s_count
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}		t_count;

typedef struct s_parsing
{
	int		fd;
	int		*floor;
	int		*roof;
	int		pl_x;
	int		pl_y;
	int		map_h;
	int		map_w;
	char	player;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	**map;
}			t_parsing;

typedef struct s_window
{
	void				*mlx;
	void				*mlx_win;
	CGDirectDisplayID	display;
	int					win_w;
	int					win_h;
	int					margin_w;
	int					margin_h;
	int					width;
	int					heigth;
	int					world_h;
}						t_window;

typedef struct s_data
{
	t_window	win;
	t_parsing	pars;
	t_key		key;
	t_image		world;
	t_ray		ray;
	t_map		map;
}				t_data;

// initialisation
void	ft_init_struct_pars(t_data *data);
void	ft_init_struct_truc(t_truc *t);
void	ft_init_struct_count(t_count *count);
void	ft_init_struct_win(t_data *data);
void	ft_init_struct_key(t_data *data);
void	ft_init_world(t_data *data);
void	ft_init_texture(t_data *data);
void	ft_init_map(t_data *data);

// print error
void	ft_print_error_cub(char **tab);
void	ft_print_error_map(char **tab);
void	ft_check_map_cub(char *argv);
void	ft_print_error_texture(char **tab);

// parsing_cub
void	ft_check_cub(t_data *data);
int		ft_check_space(char *str);
void	ft_check_tab_data(t_data *data, char **tab);
void	ft_delete_space(char **tab);
int		ft_check_arg(char **tab);

//parsing_map
void	ft_check_map(t_data *data);
void	ft_check_char_map(t_data *data);
void	ft_check_border(t_data *data);
void	ft_check_p(t_data *data);
void	ft_check_size_map(t_data *data);

//utils
void	ft_free_tab(char **tab);
void	ft_print_tab(char **tab);
int		ft_close(void);
int		ft_count_tab(char **tab);

//raycasting
void	ft_get_image(t_data *data, char c);

#endif
