/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_params_and_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/09 11:39:40 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_error_map(int y_map, int i, t_list **lst)
{
	while (y_map > 0)
	{
		while (t_win.str_map.disp[y_map][i] != '\0')
		{
			if (t_win.str_map.disp[y_map][i] != '1'
			&& t_win.str_map.disp[y_map][i] != ' ')
			{
				if (t_win.str_map.disp[y_map][i + 1] == ' '
				|| t_win.str_map.disp[y_map][i + 1] == '\0'
				|| t_win.str_map.disp[y_map][i - 1] == ' '
				|| t_win.str_map.disp[y_map - 1][i] == ' '
				|| t_win.str_map.disp[y_map + 1][i] == ' ')
				{
					ft_error("Map Inco\n");
				}
			}
			i++;
		}
		ckeck_player(y_map, t_win.str_map.disp[y_map], lst);
		y_map--;
		i = 0;
	}
}

void	param_s(char **param, char *line)
{
	if (t_win.sprite != NULL)
		ft_error("The item \"S\" already exists\n");
	if (len_split(param) > 2)
	{
		t_win.sprite = sheck_namexpm2(line);
		if (sheck_namexpm(t_win.sprite) != 1)
			ft_error("The Path OF \"S\" Inco\n");
	}
	else if (param[1] == NULL)
		ft_error("The Name OF \"S\" Inco\n");
	else if (sheck_namexpm(param[1]) == 1)
		t_win.sprite = ft_strdup(param[1]);
	else
		ft_error("The Name OF \"S\" Inco\n");
}

void	param_f(char **param)
{
	char	**tmp;
	int		r;
	int		g;
	int		b;

	if (len_split(param) != 2)
		ft_error("The number of items is more than 2 in F\n");
	if (t_win.f != -1)
		ft_error("The item \"F\" already exists\n");
	if (len_c(param[1], ',') != 2)
		ft_error("The number of \",\" is more than 2 in F\n");
	tmp = ft_split(param[1], ',');
	if (len_split(tmp) != 3)
		ft_error("The number of items is more than 3 in param F\n");
	if (is_number(tmp[0]) != 1 || is_number(tmp[1]) != 1
	|| is_number(tmp[2]) != 1)
		ft_error("color Inco in \"F\" \n");
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("color Inco in \"F\" \n");
	t_win.f = rgbtoint(r, g, b);
	freeparam(tmp);
}

void	param_c(char **param)
{
	char	**tmp;
	int		r;
	int		g;
	int		b;

	if (len_split(param) != 2)
		ft_error("The number of items is more than 2 in C\n");
	if (t_win.c != -1)
		ft_error("The item \"C\" already exists\n");
	if (len_c(param[1], ',') != 2)
		ft_error("The number of \",\" is more than 2 in C\n");
	tmp = ft_split(param[1], ',');
	if (len_split(tmp) != 3)
		ft_error("The number of items is more than 3 in param C\n");
	if (is_number(tmp[0]) != 1 || is_number(tmp[1]) != 1
	|| is_number(tmp[2]) != 1)
		ft_error("color Inco in \"C\" \n");
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("color Inco in \"C\" \n");
	t_win.c = rgbtoint(r, g, b);
	freeparam(tmp);
}

void	set_param(char **param, char *line)
{
	if (ft_strncmp(param[0], "R", 2) == 0)
		param_r(param);
	else if (ft_strncmp(param[0], "NO", 3) == 0)
		param_no(param, line);
	else if (ft_strncmp(param[0], "SO", 3) == 0)
		param_so(param, line);
	else if (ft_strncmp(param[0], "WE", 3) == 0)
		param_we(param, line);
	else if (ft_strncmp(param[0], "EA", 3) == 0)
		param_ea(param, line);
	else if (ft_strncmp(param[0], "S\0", 3) == 0)
		param_s(param, line);
	else if (ft_strncmp(param[0], "F", 2) == 0)
		param_f(param);
	else if (ft_strncmp(param[0], "C", 2) == 0)
		param_c(param);
	else if (param[0])
		ft_error("Line Inco \n");
}
