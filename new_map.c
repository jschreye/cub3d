#include "cub3d.h"

void ft_copy_map(char **new_map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->pars.map[i])
    {
        j = 0;
        while (data->pars.map[i][j])
        {
            if (data->pars.map[i][j] == '0'
            || data->pars.map[i][j] == 'N'
            || data->pars.map[i][j] == 'S'
            || data->pars.map[i][j] == 'E'
            || data->pars.map[i][j] == 'W')
                new_map[i][j] = data->pars.map[i][j];
            j++;
        }
        i++;
    }
    ft_free_tab(data->pars.map);
    data->pars.map = new_map;
}

char **ft_fill_one(char **new_map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (new_map[i])
    {
        j = 0;
        while (j < data->pars.map_w)
        {
            new_map[i][j] = '1';
            j++;
        }
        i++;
    }
    return (new_map);
}

void ft_malloc_map(t_data *data)
{
    int i;
    char **new_map;

    i = 0;
    new_map = ft_calloc(data->pars.map_h + 1, sizeof(char *));
    while (i < data->pars.map_h)
    {
        new_map[i] = ft_calloc(data->pars.map_w + 1, sizeof(char));
        i++;
    }
    new_map[i] = NULL;
    new_map = ft_fill_one(new_map, data);
    ft_copy_map(new_map, data);
}

void ft_new_map(t_data *data)
{
    ft_malloc_map(data);
}