/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:41:39 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/09 12:31:17 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_wall(int x, int y, float b, float ang)
{
	float tall;
	float stah;
	float yy;

	yy = 0;
	param_directione(&ang, &b);
	tall = (64 / b) * (t_win.width / 2) * tan(30 * (M_PI / 180)) * 1.5;
	t_win.res = y - tall;
	t_win.end = y + tall;
	stah = (t_win.height - tall) / 2;
	if (t_win.directione != 's')
		sutface(stah, x);
	t_win.y_step = t_win.y_xpm / (float)(t_win.end - t_win.res);
	while (t_win.res < t_win.end)
	{
		param_color_wall_bo(x, yy, t_win.res, b);
		t_win.res++;
		yy += t_win.y_step;
	}
}

int		shadow(int color, float dest)
{
	int r;
	int g;
	int b;

	if ((dest / 64) > 1.7)
	{
		b = fmod(color, 256) / (dest / (64 * 1.7));
		g = fmod(color / 256, 256) / (dest / (64 * 1.7));
		r = fmod(color / pow(256, 2), 256) / (dest / (64 * 1.7));
		return (rgbtoint(r, g, b));
	}
	return (color);
}

void	param_color_wall_bo(int x, float yy, float res, float dist)
{
	if (t_win.directione == 'N')
		t_win.color = t_win.dataimgno[(int)(t_win.offset
		+ ((int)(yy) * t_win.x_xpm))];
	else if (t_win.directione == 'W')
		t_win.color = t_win.dataimgwe[(int)(t_win.offset
		+ ((int)(yy) * t_win.x_xpm))];
	else if (t_win.directione == 'S')
		t_win.color = t_win.dataimgso[(int)(t_win.offset
		+ ((int)(yy) * t_win.x_xpm))];
	else if (t_win.directione == 'E')
		t_win.color = t_win.dataimgea[(int)(t_win.offset
		+ ((int)(yy) * t_win.x_xpm))];
	else if (t_win.directione == 's')
		t_win.color = t_win.dataimgsp[(int)(t_win.offsetsprite
		+ ((int)(yy) * t_win.x_xpm))];
	if (t_win.directione != 's')
		my_mlx_pixel_put(x, res, shadow(t_win.color, dist));
	else
	{
		if (t_win.color > 0 && t_win.offsetsprite >= 0)
			my_mlx_pixel_put(x, res, shadow(t_win.color, dist));
	}
}
