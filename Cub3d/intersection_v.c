/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_v.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/13 18:19:12 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_intersection_v(float toor, int *helper, float *i, float *j)
{
	*helper = 0;
	if ((toor >= 0 && toor <= 90) || (toor >= 270 && toor <= 360))
		t_win.intersection_vx = floor(t_win.x_player / 64) * 64 + 64;
	else
	{
		t_win.intersection_vx = floor(t_win.x_player / 64) * 64;
		*helper += 1;
	}
	t_win.intersection_vy = t_win.y_player + (t_win.x_player
	- t_win.intersection_vx) * -tan(toor * M_PI / 180);
	*i = floor((t_win.intersection_vx - *helper) / 64);
	*j = floor(t_win.intersection_vy / 64);
}

void	last_intersection_v(float toor, int helper, float *i, float *j)
{
	if ((toor >= 0 && toor <= 90) || (toor >= 270 && toor <= 360))
	{
		t_win.intersection_vx = t_win.intersection_vx + 64;
		t_win.intersection_vy = t_win.intersection_vy
		- (64 * -tan(toor * M_PI / 180));
	}
	else
	{
		t_win.intersection_vx = t_win.intersection_vx - 64;
		t_win.intersection_vy = t_win.intersection_vy
		- (64 * tan(toor * M_PI / 180));
	}
	*i = floor((t_win.intersection_vx - helper) / 64);
	*j = floor(t_win.intersection_vy / 64);
}

float	intersection_v(float toor, char c)
{
	float	i;
	float	j;
	int		helper;

	normalise(&toor);
	first_intersection_v(toor, &helper, &i, &j);
	while (1)
		if (t_win.str_map.y_map > (int)j
		&& t_win.str_map.x_map > (int)i && (int)i >= 0 && (int)j >= 0)
			if (t_win.str_map.disp[(int)j][(int)i] != c)
				last_intersection_v(toor, helper, &i, &j);
			else
				break ;
		else
			break ;
	return (sqrt(pow((t_win.x_player - t_win.intersection_vx), 2)
	+ pow((t_win.y_player - t_win.intersection_vy), 2)));
}
