#include "cub3d.h"

int ft_check_arg(char **tab)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
        i++;
    if (i != 3)
        return (1);
    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (ft_isalpha(tab[i][j]) == 1)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_check_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != 9)
            return (0);
        i++;
    }
    return (1);
}