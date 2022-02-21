/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:36:00 by wben-sai          #+#    #+#             */
/*   Updated: 2020/11/23 17:40:27 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_click_left(t_list **lst)
{
	float x;
	float y;

	y = (t_win.y_player + sin((t_win.toor - 90) * (M_PI / 180)) * 40) / 64;
	x = (t_win.x_player + cos((t_win.toor - 90) * (M_PI / 180)) * 40) / 64;
	if (t_win.str_map.disp[(int)y][(int)x] != '1'
	&& t_win.str_map.disp[(int)y][(int)x] != '2'
	&& t_win.str_map.disp[(int)y][(int)x] != ' ')
	{
		t_win.y_player += sin((t_win.toor - 90) * (M_PI / 180)) * 10;
		t_win.x_player += cos((t_win.toor - 90) * (M_PI / 180)) * 10;
		calc_dist_sprite(lst);
	}
}

void	key_click_right(t_list **lst)
{
	float x;
	float y;

	y = (t_win.y_player + sin((t_win.toor + 90) * (M_PI / 180)) * 40) / 64;
	x = (t_win.x_player + cos((t_win.toor + 90) * (M_PI / 180)) * 40) / 64;
	if (t_win.str_map.disp[(int)y][(int)x] != '1'
	&& t_win.str_map.disp[(int)y][(int)x] != '2'
	&& t_win.str_map.disp[(int)y][(int)x] != ' ')
	{
		t_win.y_player += sin((t_win.toor + 90) * (M_PI / 180)) * 10;
		t_win.x_player += cos((t_win.toor + 90) * (M_PI / 180)) * 10;
		calc_dist_sprite(lst);
	}
}

void	key_click_up(t_list **lst)
{
	float x;
	float y;

	y = (t_win.y_player + sin(t_win.toor * (M_PI / 180)) * 40) / 64;
	x = (t_win.x_player + cos(t_win.toor * (M_PI / 180)) * 40) / 64;
	if (t_win.str_map.disp[(int)y][(int)x] != '1'
	&& t_win.str_map.disp[(int)y][(int)x] != '2'
	&& t_win.str_map.disp[(int)y][(int)x] != ' ')
	{
		t_win.y_player = t_win.y_player + sin(t_win.toor * (M_PI / 180)) * 10;
		t_win.x_player = t_win.x_player + cos(t_win.toor * (M_PI / 180)) * 10;
		calc_dist_sprite(lst);
	}
}

void	key_click_down(t_list **lst)
{
	float x;
	float y;

	y = (t_win.y_player - sin(t_win.toor * (M_PI / 180)) * 40) / 64;
	x = (t_win.x_player - cos(t_win.toor * (M_PI / 180)) * 40) / 64;
	if (t_win.str_map.disp[(int)y][(int)x] != '1'
	&& t_win.str_map.disp[(int)y][(int)x] != '2'
	&& t_win.str_map.disp[(int)y][(int)x] != ' ')
	{
		t_win.y_player = t_win.y_player - sin(t_win.toor * (M_PI / 180)) * 10;
		t_win.x_player = t_win.x_player - cos(t_win.toor * (M_PI / 180)) * 10;
		calc_dist_sprite(lst);
	}
}
