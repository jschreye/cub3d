#include "cub3d.h"

void ft_check_border_bis(t_data *data)
{
    int i;
    int size;

    i = 0;
    while (data->pars.map[i])
    {
        if (data->pars.map[i][0] != ' ' && data->pars.map[i][0] != '1')
           ft_print_error_map(data->pars.map);
        i++;
    }
    i = 0;
    while (data->pars.map[i])
    {
        size = ft_strlen(data->pars.map[i]);
        if (data->pars.map[i][size - 1] != ' ' 
            && data->pars.map[i][size - 1] != '1')
           ft_print_error_map(data->pars.map);
        i++;
    }
}

void ft_check_zero_bis(t_data *data, int i, int j)
{
    if ((data->pars.map[i - 1][j] && data->pars.map[i - 1][j] == ' ')
        || !data->pars.map[i - 1][j])
        ft_print_error_map(data->pars.map);
    if ((data->pars.map[i + 1][j] && data->pars.map[i + 1][j] == ' ')
        || !data->pars.map[i + 1][j])
        ft_print_error_map(data->pars.map);
    if ((data->pars.map[i][j - 1] && data->pars.map[i][j - 1] == ' ')
        || !data->pars.map[i ][j - 1])
        ft_print_error_map(data->pars.map);
    if ((data->pars.map[i][j + 1] && data->pars.map[i][j + 1] == ' ')
        || !data->pars.map[i][j + 1])
        ft_print_error_map(data->pars.map);
}

void ft_check_zero(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->pars.map[i])
    {
        j = 0;
        while (data->pars.map[i][j])
        {
            if (data->pars.map[i][j] == '0')
                ft_check_zero_bis(data, i, j);
            j++;
        }
        i++;
    } 
}

void ft_count_char_map(t_data *data)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (data->pars.map[i])
    {
        j = 0;
        while (data->pars.map[i][j])
        {
            if (data->pars.map[i][j] == 'N')
                count++;
            if (data->pars.map[i][j] == 'S')
                count++;
            if (data->pars.map[i][j] == 'W')
                count++;
            if (data->pars.map[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    } 
    if (count != 1)
        ft_print_error_map(data->pars.map);
}

void ft_check_map(t_data *data)
{
    ft_check_char_map(data);
    ft_count_char_map(data);
    ft_check_border(data);
    ft_check_border_bis(data);
    ft_check_zero(data);
    ft_check_p(data);
    ft_check_size_map(data);
}