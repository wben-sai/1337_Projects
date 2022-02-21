/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/04 17:00:09 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clac_x_y_map(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
	{
		t_win.str_map.y_map = t_win.str_map.y_map + 1;
		if (ft_strlen(line) > t_win.str_map.x_map)
			t_win.str_map.x_map = ft_strlen(line);
	}
	t_win.len_file = t_win.len_file + 1;
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	int	*dst;
	int	d;
	int	d1;
	int	d3;

	dst = (int *)mlx_get_data_addr(t_win.img, &d1, &d3, &d);
	if (x < t_win.width && y < t_win.height && x >= 0 && y >= 0)
		dst[y * (int)t_win.width + x] = color;
}

void	param_directione(float *ang, float *b)
{
	float direc;

	direc = *ang - t_win.toor;
	direc += t_win.toor;
	while (direc >= 360)
		direc = direc - 360;
	while (direc < 0)
		direc = direc + 360;
	if (((direc >= 0 && direc <= 90) || (direc >= 270 && direc <= 360))
	&& t_win.directione == 'v')
		t_win.directione = 'E';
	else if ((direc > 90 && direc < 270) && t_win.directione == 'v')
		t_win.directione = 'W';
	else if ((direc >= 0 && direc <= 180) && t_win.directione == 'h')
		t_win.directione = 'S';
	else if ((direc > 180 && direc < 360) && t_win.directione == 'h')
		t_win.directione = 'N';
	*ang = t_win.toor - *ang;
	if (*b == 0)
		*b = 1;
	if (t_win.directione != 's')
		*b *= cos(*ang * M_PI / 180);
}

void	sutface(float stah, int x)
{
	int i;

	i = 0;
	while (stah > 0)
	{
		my_mlx_pixel_put(x, i, t_win.c);
		my_mlx_pixel_put(x, t_win.height - i, t_win.f);
		i++;
		stah--;
	}
}
