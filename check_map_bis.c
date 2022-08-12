#include "cub3d.h"

void ft_check_p(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->pars.map[i])
    {
        j = 0;
        while (data->pars.map[i][j])
        {
            if (data->pars.map[i][j] == 'N' || data->pars.map[i][j] == 'S'
                || data->pars.map[i][j] == 'W' || data->pars.map[i][j] == 'E')
            {
                data->pars.player = data->pars.map[i][j];
                data->pars.pl_x = i;
                data->pars.pl_y = j;
                if ((data->pars.map[i - 1][j] == ' ' && data->pars.map[i - 1][j])
                    || (data->pars.map[i + 1][j] == ' ' && data->pars.map[i + 1][j])
                    || (data->pars.map[i][j - 1] == ' ' && data->pars.map[i][j - 1]) 
                    || (data->pars.map[i][j + 1] == ' ' && data->pars.map[i][j + 1]))
                    ft_print_error_map(data->pars.map);
            }
            j++;
        }
        i++;
    }
}

void    ft_check_char_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->pars.map[i])
    {
        j = 0;
        while (data->pars.map[i][j])
        {
            if (data->pars.map[i][j] != '1' && data->pars.map[i][j] != '0'
                && data->pars.map[i][j] != ' ' && data->pars.map[i][j] != 'N'
                && data->pars.map[i][j] != 'S' && data->pars.map[i][j] != 'E'
                && data->pars.map[i][j] != 'W')
                ft_print_error_map(data->pars.map);
            j++;
        }
        i++;
    }    
}

int ft_count_tab(char **tab)
{
    int count;

    count = 0;
    while(tab[count])
        count++;
    return (count - 1);
}

void ft_check_border(t_data *data)
{
    int i;

    i = 0;
    while (data->pars.map[0][i])
    {
        if (data->pars.map[0][i] != ' ' && data->pars.map[0][i] != '1')
            ft_print_error_map(data->pars.map);
        i++;
    }
    i = 0;
    while (data->pars.map[ft_count_tab(data->pars.map)][i])
    {
        if (data->pars.map[ft_count_tab(data->pars.map)][i] != ' ' 
            && data->pars.map[ft_count_tab(data->pars.map)][i] != '1')
            ft_print_error_map(data->pars.map);
        i++;
    }
}

void ft_check_size_map(t_data *data)
{
    int i;
    int j;
    int tmp;

    i = 0;
    tmp = 0;
    while (data->pars.map[i])
    {
        j = 0;
        while (data->pars.map[i][j])
            j++;
        if (j > tmp)
            tmp = j;
        i++;
        data->pars.map_h++;
    }
    data->pars.map_w = tmp;
}