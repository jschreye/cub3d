/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:45:29 by jschreye          #+#    #+#             */
/*   Updated: 2022/07/11 13:34:44 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_print_error_cub(char **tab)
{
    if (tab)
        ft_free_tab(tab);
    printf("error: file .cub is not correct\n");
    exit (0);
}

void ft_print_error_map(char **tab)
{
    if (tab)
        ft_free_tab(tab);
    printf("error: map is not correct\n");
    exit (0);
}

void    ft_check_map_cub(char *argv)
{
    int    size;

    size = ft_strlen(argv);
    if (argv[size - 1] != 'b' || argv[size - 2] != 'u' || argv[size - 3] != 'c'
        || argv[size - 4] != '.')
    {
        write (1, "Error\n IS NOT A .CUB", 20);
        exit(0);
    }
}

void ft_print_error_texture(char **tab)
{
    if (tab)
        ft_free_tab(tab);
    printf("error: texture is not correct\n");
    exit (0);   
}