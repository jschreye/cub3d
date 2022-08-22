/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:54:25 by jschreye          #+#    #+#             */
/*   Updated: 2022/08/22 11:35:59 by jschreye         ###   ########.fr       */
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
//# include <CoreGraphics/CGDisplayConfiguration.h>

typedef struct s_map
{
	int		map_size;
	int		w;
	int		h;
	int		h_offset;
	int		w_offset;
	int		a_deg;
	int		c_floor;
	int		c_ceil;
	float	ws_fps;
	float	ad_fps;
	float	rot_fps;
	float	pos_y;
	float	pos_x;
	float	prev_x;
	float	prev_y;
	float	a_rad;
	float	pl_angle;
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
	int				hmx;
	int				hmy;
	int				vmx;
	int				vmy;
	int				i;
	int				h_shift;
	int				v_shift;
	int				ix;
	int				rays;
	int				r_1;
	int				r_05;
	int				lpr_cpy;
	int				lpr;
	int				y1;
	int				y2;
	int				iy;
	char			spe;
	char			cross;
	char			char_map;
	float			ty;
	float			shade;
	float			tx;
	float			w_top;
	float			to;
	float			ty_step;
	float			wx;
	float			w_bot;
	float			wy;
	float			dist;
	float			hx;
	float			hy;
	float			vx;
	float			vy;
	float			y;
	float			x;
	float			yo;
	float			xo;
	float			dist_v;
	float			dist_h;
	float			atan;
	float			ntan;
	double			r_ra;
	double			fov_05;
	unsigned int	c;
	t_img			tx_n;
	t_img			tx_w;
	t_img			tx_e;
	t_img			tx_s;
	t_img			*tex;
}					t_ray;

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
	int				fd;
	int				*floor;
	int				*roof;
	int				pl_x;
	int				pl_y;
	int				map_h;
	int				map_w;
	unsigned long	hex_f;
	unsigned long	hex_s;
	char			player;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			**map;
}					t_parsing;

typedef struct s_window
{
	void				*mlx;
	void				*mlx_win;
	int					win_w;
	int					win_h;
	int					margin_w;
	int					margin_h;
	int					width;
	int					heigth;
	int					world_h;
}						t_window;

typedef struct s_grid
{
	int		of;
	int		xo;
	int		yo;
	int		vo;
	int		ho;
	int		mx;
	int		mx_add_xo;
	int		mx_sub_xo;
	int		my;
	int		my_add_yo;
	int		my_sub_yo;
}	t_grid;

typedef struct s_data
{
	t_window	win;
	t_parsing	pars;
	t_key		key;
	t_image		world;
	t_image		maping;
	t_ray		ray;
	t_map		map;
	t_grid		grid;
}				t_data;

// initialisation
void			ft_init_struct_pars(t_data *data);
void			ft_init_struct_truc(t_truc *t);
void			ft_init_struct_count(t_count *count);
void			ft_init_struct_win(t_data *data);
void			ft_init_struct_key(t_data *data);
void			ft_init_world(t_data *data);
void			ft_init_texture(t_data *data);
void			ft_init_map(t_data *data);

// print error
void			ft_print_error_cub(char **tab);
void			ft_print_error_map(char **tab);
void			ft_check_map_cub(char *argv);
void			ft_print_error_texture(char **tab);

// parsing_cub
void			ft_check_cub(t_data *data);
int				ft_check_space(char *str);
void			ft_check_tab_data(t_data *data, char **tab);
void			ft_delete_space(char **tab);
int				ft_check_arg(char **tab);
unsigned long	ft_create_rgb(int t, int r, int g, int b);
void			ft_get_color(t_data *data);

//parsing_map
void			ft_check_map(t_data *data);
void			ft_check_char_map(t_data *data);
void			ft_check_border(t_data *data);
void			ft_check_p(t_data *data);
void			ft_check_size_map(t_data *data);
void			ft_new_map(t_data *data);

//utils
void			ft_free_tab(char **tab);
void			ft_print_tab(char **tab);
int				ft_close(t_data *data);
int				ft_count_tab(char **tab);
float			ft_deg_to_rad(int angle);
int				ft_rad_to_deg(float angle);
float			ft_fix_fisheye(float angle);

//raycasting
void			ft_get_image(t_data *data);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
void			ft_raycasting(t_data *data);
void			ft_check_angle(float angle, int *deg);
void			ft_check_hori_ray(t_parsing *pars, t_map *map, t_ray *ray);
void			ft_check_verti_ray(t_parsing *pars, t_map *map, t_ray *ray);
void			ft_compare_rays(t_data *data);
void			ft_get_3d(t_data *data, t_ray *ray);

//texture
t_img			*ft_ray_texture(float ray_a, t_ray *ray);
int				ft_ray_color(float ray_a, t_ray *ray);
void			ft_use_color(t_data *data, t_ray *ray);
void			ft_use_texture(t_data *data, t_ray *ray);
float			ft_color_shade(float ray_a, t_ray *ray);
void			ft_draw_v_line(t_image *image, t_ray *ray, int color);
void			ft_wall_texture(t_data *data, t_ray *ray);
unsigned int	ft_get_tex_color(t_img *tex, int x, int y, float shade);

//move
int				ft_map_char(char c);
void			check_char_map(t_data *data);
int				ft_events_loop(t_data *data);
void			ft_move(t_data *data, char dir);
void			ft_rotation(t_data *data, char dir);

//key
int				ft_key_press(int k, t_data *data);
int				ft_key_release(int k, t_data *data);

#endif
