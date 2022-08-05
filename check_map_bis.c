#include "cub3d.h"

void ft_check_p(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->tab_map[i])
    {
        j = 0;
        while (data->tab_map[i][j])
        {
            if (data->tab_map[i][j] == 'N' || data->tab_map[i][j] == 'S'
                || data->tab_map[i][j] == 'W' || data->tab_map[i][j] == 'E')
            {
                if ((data->tab_map[i - 1][j] == ' ' && data->tab_map[i - 1][j])
                    || (data->tab_map[i + 1][j] == ' ' && data->tab_map[i + 1][j])
                    || (data->tab_map[i][j - 1] == ' ' && data->tab_map[i][j - 1]) 
                    || (data->tab_map[i][j + 1] == ' ' && data->tab_map[i][j + 1]))
                    ft_print_error_map(data->tab_map);
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
    while (data->tab_map[i])
    {
        j = 0;
        while (data->tab_map[i][j])
        {
            if (data->tab_map[i][j] != '1' && data->tab_map[i][j] != '0'
                && data->tab_map[i][j] != ' ' && data->tab_map[i][j] != 'N'
                && data->tab_map[i][j] != 'S' && data->tab_map[i][j] != 'E'
                && data->tab_map[i][j] != 'W')
                ft_print_error_map(data->tab_map);
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
    while (data->tab_map[0][i])
    {
        if (data->tab_map[0][i] != ' ' && data->tab_map[0][i] != '1')
            ft_print_error_map(data->tab_map);
        i++;
    }
    i = 0;
    while (data->tab_map[ft_count_tab(data->tab_map)][i])
    {
        if (data->tab_map[ft_count_tab(data->tab_map)][i] != ' ' 
            && data->tab_map[ft_count_tab(data->tab_map)][i] != '1')
            ft_print_error_map(data->tab_map);
        i++;
    }
}