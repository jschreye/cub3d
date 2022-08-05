#include "cub3d.h"

void    ft_check_last_line(char **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[i])
        i++;
    while (tab[i- 1][j])
    {
        if (tab[i- 1][j] != '1' && tab[i- 1][j] != ' ')
            ft_print_error_cub(tab);
        j++;
    }
}

void    ft_parsing_map(t_data *data, char **tab, int i)
{
    int j;
    int size;

    j = 0;
    size = 0;
    while (tab[size])
        size++;
    data->tab_map = ft_calloc(size, sizeof(char*));//PAS FREE
    while (tab[i])
    {
        data->tab_map[j] = ft_calloc(ft_strlen(tab[i]) + 1, sizeof(char));//PAS FREE
        ft_strcpy(data->tab_map[j], tab[i]);
        i++;
        j++;
    }
    data->tab_map[j] = NULL;
    ft_free_tab(tab);
}

void    ft_delete_space(char **tab)
{
    t_truc t;

    t.i = 0;
    while (tab[t.i])
    {
        t.tmp = ft_calloc(ft_strlen(tab[t.i]) + 1, sizeof(char));
        t.j = 0;
        t.k = 0;
        while (tab[t.i][t.j])
        {
            if (tab[t.i][t.j] == ' ')
                t.j++;
            else
            {
                t.tmp[t.k] = tab[t.i][t.j];
                t.j++;
                t.k++;
            }
        }
        ft_bzero(tab[t.i], ft_strlen(tab[t.i]));
        ft_strcpy(tab[t.i], t.tmp);
        free(t.tmp);
        t.i++;
    }
}

void    ft_parsing_cub(t_data *data, char **tab)
{
    int i;
    int j;
    char **tab_data;

    i = 0;
    j = 0;
    tab_data = ft_calloc(7, sizeof(char*));//PAS FREE
    while (tab[i] && j != 6)
    {
        if (ft_check_space(tab[i]) == 1)
            i++;
        tab_data[j] = ft_calloc(ft_strlen(tab[i]) + 1, sizeof(char));//PAS FREE
        ft_strcpy(tab_data[j], tab[i]);
        i++;
        j++;
    }
    tab_data[j] = NULL;
    if (j != 6)
        ft_print_error_cub(tab_data);
    ft_parsing_map(data, tab, i);
    ft_check_tab_data(data, tab_data);
}

void    ft_check_cub(t_data *data)
{
    char    *str;
    char    *str_full_cub;
    char    *tmp;
    char    **tab;

    str_full_cub = ft_strdup("");//free
    while (1)
    {
        tmp = str_full_cub;
        str = get_next_line(data->fd);
        if (str != NULL)
            str_full_cub = ft_join(str_full_cub, str);
        if (str == NULL)
            break;
        free (tmp);
        free (str);
    }
    tab = ft_split(str_full_cub, '\n');//free
    free (str_full_cub);
    ft_check_last_line(tab);
    ft_parsing_cub(data, tab);
    ft_check_map(data);
}
