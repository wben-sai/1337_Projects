/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/13 18:19:04 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	intersection_h(float toor, char c)
{
	float	x;
	float	y;
	int		helper;

	normalise(&toor);
	first_intersection_h(toor, &helper, &x, &y);
	while (1)
	{
		if (t_win.str_map.y_map > (int)y
		&& t_win.str_map.x_map > (int)x && (int)x >= 0 && (int)y >= 0)
			if (t_win.str_map.disp[(int)y][(int)x] != c)
				last_intersection_h(toor, helper, &x, &y);
			else
				break ;
		else
			break ;
	}
	return (sqrt(pow((t_win.x_player - t_win.intersection_hx), 2)
	+ pow((t_win.y_player - t_win.intersection_hy), 2)));
}

void	first_intersection_h(float toor, int *helper, float *x, float *y)
{
	*helper = 0;
	if (toor >= 180 && toor <= 360)
	{
		t_win.intersection_hy = floor(t_win.y_player / 64) * 64;
		*helper += 1;
	}
	else
		t_win.intersection_hy = floor(t_win.y_player / 64) * 64 + 64;
	t_win.intersection_hx = t_win.x_player
	+ (t_win.y_player - t_win.intersection_hy) / -tan(toor * M_PI / 180);
	*x = t_win.intersection_hx / 64;
	*y = (t_win.intersection_hy - *helper) / 64;
}

void	last_intersection_h(float toor, int helper, float *x, float *y)
{
	if (toor >= 180 && toor <= 360)
	{
		t_win.intersection_hx = t_win.intersection_hx
		+ (64 / -tan(toor * M_PI / 180));
		t_win.intersection_hy = t_win.intersection_hy - 64;
	}
	else
	{
		t_win.intersection_hx = t_win.intersection_hx
		+ (64 / tan(toor * M_PI / 180));
		t_win.intersection_hy = t_win.intersection_hy + 64;
	}
	*x = t_win.intersection_hx / 64;
	*y = (t_win.intersection_hy - helper) / 64;
}
