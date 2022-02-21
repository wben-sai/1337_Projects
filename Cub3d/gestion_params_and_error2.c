/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_params_and_error2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/09 12:24:30 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	param_r(char **param)
{
	if (len_split(param) != 3)
		ft_error("The number of items is more than 3 in R\n");
	if (t_win.width != 0 && t_win.width != 0)
		ft_error("The item \"R\" already exists\n");
	if (is_number(param[1]) == 0 || is_number(param[2]) == 0)
		ft_error("the params is not a number\n");
	t_win.width = ft_atoi(param[1]);
	t_win.height = ft_atoi(param[2]);
	if (t_win.width == 0 || t_win.height == 0)
		ft_error("The height and width should be more than 0\n");
	if (t_win.width > 2560 || t_win.width == -1)
		t_win.width = 2560;
	if (t_win.height > 1440 || t_win.height == -1)
		t_win.height = 1440;
}

void	param_no(char **param, char *line)
{
	if (t_win.wall_no != NULL)
		ft_error("The item \"NO\" already exists\n");
	if (len_split(param) > 2)
	{
		t_win.wall_no = sheck_namexpm2(line);
		if (sheck_namexpm(t_win.wall_no) != 1)
			ft_error("The Path OF \"NO\" Inco\n");
	}
	else if (param[1] == NULL)
		ft_error("The Name OF \"NO\" Inco\n");
	else if (sheck_namexpm(param[1]) == 1)
		t_win.wall_no = ft_strdup(param[1]);
	else
		ft_error("The Name OF \"NO\" Inco\n");
}

void	param_so(char **param, char *line)
{
	if (t_win.wall_so != NULL)
		ft_error("The item \"SO\" already exists\n");
	if (len_split(param) > 2)
	{
		t_win.wall_so = sheck_namexpm2(line);
		if (sheck_namexpm(t_win.wall_so) != 1)
			ft_error("The Path OF \"SO\" Inco\n");
	}
	else if (param[1] == NULL)
		ft_error("The Name OF \"SO\" Inco\n");
	else if (sheck_namexpm(param[1]) == 1)
		t_win.wall_so = ft_strdup(param[1]);
	else
		ft_error("The Name OF \"SO\" Inco\n");
}

void	param_we(char **param, char *line)
{
	if (t_win.wall_we != NULL)
		ft_error("The item \"WE\" already exists\n");
	if (len_split(param) > 2)
	{
		t_win.wall_we = sheck_namexpm2(line);
		if (sheck_namexpm(t_win.wall_we) != 1)
			ft_error("The Path OF \"WE\" Inco\n");
	}
	else if (param[1] == NULL)
		ft_error("The Name OF \"WE\" Inco\n");
	else if (sheck_namexpm(param[1]) == 1)
		t_win.wall_we = ft_strdup(param[1]);
	else
		ft_error("The Name OF \"WE\" Inco\n");
}

void	param_ea(char **param, char *line)
{
	if (t_win.wall_ea != NULL)
		ft_error("The item \"EA\" already exists\n");
	if (len_split(param) > 2)
	{
		t_win.wall_ea = sheck_namexpm2(line);
		if (sheck_namexpm(t_win.wall_ea) != 1)
			ft_error("The Path OF \"EA\" Inco\n");
	}
	else if (param[1] == NULL)
		ft_error("The Name OF \"EA\" Inco\n");
	else if (sheck_namexpm(param[1]) == 1)
		t_win.wall_ea = ft_strdup(param[1]);
	else
		ft_error("The Name OF \"EA\" Inco\n");
}
