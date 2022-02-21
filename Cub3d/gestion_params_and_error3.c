/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_params_and_error3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/01 12:03:32 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	gestion_param(char **line)
{
	char	*temp;
	char	**param;
	int		x;

	x = ft_strlen(*line);
	temp = *line;
	*line = ft_strtrim(*line, " ");
	free(temp);
	if (x > 0 && *line[0] == '\0')
		ft_error("elements must be separed by empty line");
	param = ft_split(*line, ' ');
	if (param[0] != NULL)
	{
		set_param(param, *line);
	}
	freeparam(param);
}

int		ckeck_map(t_list **lst)
{
	int i;
	int y_map;

	i = 0;
	y_map = t_win.str_map.y_map - 2;
	while (t_win.str_map.disp[0][i] != '\0')
	{
		if ((t_win.str_map.disp[0][i] != '1'
		&& t_win.str_map.disp[0][i] != ' ')
		|| (t_win.str_map.disp[y_map + 1][i] != ' '
		&& t_win.str_map.disp[y_map + 1][i] != '1'))
		{
			ft_error("Map Inco\n");
		}
		i++;
	}
	i = 0;
	check_error_map(y_map, i, lst);
	if (t_win.y_player == 0 && t_win.x_player == 0)
		ft_error("the player does not exist\n");
	calc_dist_sprite(lst);
	sheck_resul();
	return (1);
}

void	ckeck_player(int y, char *s, t_list **lst)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == 'N')
			t_win.toor = 270;
		else if (s[i] == 'S')
			t_win.toor = 90;
		else if (s[i] == 'W')
			t_win.toor = 180;
		else if (s[i] == 'E')
			t_win.toor = 0;
		if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
		{
			if (t_win.y_player != 0 && t_win.x_player != 0)
				ft_error("Player error\n");
			t_win.y_player = y * 64 + 32;
			t_win.x_player = i * 64 + 32;
		}
		if (s[i] == '2')
			ft_lstadd_back(lst, ft_lstnew(i * 64 + 32, y * 64 + 32, 0, 'n'));
		if (check_c(s[i]) == 0)
			ft_error("Caracter Inco\n");
	}
}

int		check_c(char c)
{
	if (c != 'N' && c != 'S' && c != ' ' && c != '1' && c != '0'
	&& c != '2' && c != 'W' && c != 'E')
	{
		return (0);
	}
	return (1);
}
