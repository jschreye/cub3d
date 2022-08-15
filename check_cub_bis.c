#include "cub3d.h"

void	ft_atoi_arg(int *tab_int, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab_int[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (tab_int[i] < 0 || tab_int[i] > 255)
			ft_print_error_cub(tab);
		i++;
	}
}

void	ft_registre_path_bis(t_data *data, char *str_tab, char *str, t_count *count)
{
	char	**tmp_tab;

	if (ft_strncmp(str, "F", 1) == 0)
	{
		ft_memmove(&str_tab[0], &str_tab[1], ft_strlen(str_tab));
		tmp_tab = ft_split(str_tab, ',');
		if (ft_check_arg(tmp_tab) == 1)
			ft_print_error_cub(tmp_tab);
		data->pars.floor = ft_calloc(3, sizeof(int));
		ft_atoi_arg(data->pars.floor, tmp_tab);
		ft_free_tab(tmp_tab);
		count->f++;
	}
	if (ft_strncmp(str, "C", 1) == 0)
	{
		ft_memmove(&str_tab[0], &str_tab[1], ft_strlen(str_tab));
		tmp_tab = ft_split(str_tab, ',');
		if (ft_check_arg(tmp_tab) == 1)
			ft_print_error_cub(tmp_tab);
		data->pars.roof = ft_calloc(3, sizeof(int));
		ft_atoi_arg(data->pars.roof, tmp_tab);
		ft_free_tab(tmp_tab);
		count->c++;
	}
}

void	ft_registre_path(t_data *data, char *str_tab, char *str, t_count *count)
{
	if (ft_strncmp(str, "NO", 2) == 0)
	{
		data->pars.no_texture = ft_calloc(ft_strlen(str_tab), sizeof(char));
		ft_strcpy(data->pars.no_texture, ft_strchr(str_tab, '.'));
		count->no++;
	}
	if (ft_strncmp(str, "SO", 2) == 0)
	{
		data->pars.so_texture = ft_calloc(ft_strlen(str_tab), sizeof(char));
		ft_strcpy(data->pars.so_texture, ft_strchr(str_tab, '.'));
		count->so++;
	}
	if (ft_strncmp(str, "WE", 2) == 0)
	{
		data->pars.we_texture = ft_calloc(ft_strlen(str_tab), sizeof(char));
		ft_strcpy(data->pars.we_texture, ft_strchr(str_tab, '.'));
		count->we++;
	}
	if (ft_strncmp(str, "EA", 2) == 0)
	{
		data->pars.ea_texture = ft_calloc(ft_strlen(str_tab), sizeof(char));
		ft_strcpy(data->pars.ea_texture, ft_strchr(str_tab, '.'));
		count->ea++;
	}
	ft_registre_path_bis(data, str_tab, str, count);
}

void	ft_check_error_count(t_count *count)
{
	if (count->c != 1)
		ft_print_error_cub(NULL);
	else if (count->ea != 1)
		ft_print_error_cub(NULL);
	else if (count->f != 1)
		ft_print_error_cub(NULL);
	else if (count->no != 1)
		ft_print_error_cub(NULL);
	else if (count->so != 1)
		ft_print_error_cub(NULL);
	else if (count->we != 1)
		ft_print_error_cub(NULL);
}

void	ft_check_tab_data(t_data *data, char **tab)
{
	t_count	count;
	int		i;

	i = 0;
	ft_init_struct_count(&count);
	ft_delete_space(tab);
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "NO./", 4) == 0)
			ft_registre_path(data, tab[i], "NO", &count);
		if (ft_strncmp(tab[i], "SO./", 4) == 0)
			ft_registre_path(data, tab[i], "SO", &count);
		if (ft_strncmp(tab[i], "WE./", 4) == 0)
			ft_registre_path(data, tab[i], "WE", &count);
		if (ft_strncmp(tab[i], "EA./", 4) == 0)
			ft_registre_path(data, tab[i], "EA", &count);
		if (ft_strncmp(tab[i], "F", 1) == 0)
			ft_registre_path(data, tab[i], "F", &count);
		if (ft_strncmp(tab[i], "C", 1) == 0)
			ft_registre_path(data, tab[i], "C", &count);
		i++;
	}
	ft_check_error_count(&count);
	ft_free_tab(tab);
}
