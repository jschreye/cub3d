#include "cub3d.h"

void ft_check_angle(float angle, int *deg)
{
    if (angle < 0)
        angle += 6.2831853071;
    if (angle > 6.2831853071)
        angle -= 6.2831853071;
    *deg = ft_rad_to_deg(angle);
}

void	check_char_map(t_data *data)
{
	if (data->ray.char_map != '1')
		data->ray.spe = data->ray.char_map;
}