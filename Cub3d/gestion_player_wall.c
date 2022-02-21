/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_player_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/13 18:19:57 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player(t_list **lst)
{
	float	ang;
	float	dist;
	int		i;

	i = 0;
	ang = t_win.toor - 30;
	t_win.x_print = 0;
	t_win.y_print = t_win.height / 2;
	while (ang <= t_win.toor + 30)
	{
		dist = intersection_pss(ang);
		t_win.walls_dist[i++] = dist;
		ang += 60.0 / t_win.width;
		t_win.x_print++;
	}
	t_win.walls_dist[i] = '\0';
	print__sprite(lst);
}

float	intersection_pss(float ang)
{
	float a;
	float b;

	a = intersection_h(ang, '1');
	b = intersection_v(ang, '1');
	t_win.directione = (a > b) ? 'v' : 'h';
	if (a > b)
	{
		t_win.offset = fmod(t_win.intersection_vy, 64);
		print_wall(t_win.x_print, t_win.y_print, b, ang);
		return (b);
	}
	else
	{
		t_win.offset = fmod(t_win.intersection_hx, 64);
		print_wall(t_win.x_print, t_win.y_print, a, ang);
		return (a);
	}
}
