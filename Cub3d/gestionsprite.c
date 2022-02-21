/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:54:30 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/13 18:15:49 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_render(int x, int y, int sp_size, t_list *lst)
{
	int color_sp;
	int i;
	int j;

	i = -1;
	while (++i < sp_size)
	{
		if ((x + i) < 0 || (x + i) > t_win.width)
			continue;
		if (lst->dist > t_win.walls_dist[x + i])
			continue;
		j = -1;
		while (++j < sp_size)
		{
			if ((y + j) < 0 || (y + j) >= t_win.height)
				continue;
			color_sp = t_win.dataimgsp[(int)((64
					* (j * 64 / sp_size))
					+ (i * 64 / sp_size))];
			if (color_sp != t_win.dataimgsp[0])
				my_mlx_pixel_put((x + i), (y + j)
				, shadow(color_sp, lst->dist));
		}
	}
}

void	ft_sprite(t_list *lst)
{
	float sp_size;
	float x_inter;
	float y_inter;
	float sp_ang;

	sp_ang = atan2(lst->y - t_win.y_player, lst->x - t_win.x_player);
	while ((sp_ang - (t_win.toor * M_PI / 180)) > M_PI)
		sp_ang -= 2 * M_PI;
	while ((sp_ang - (t_win.toor * M_PI / 180)) < -M_PI)
		sp_ang += 2 * M_PI;
	sp_size = (t_win.width / lst->dist) * 64;
	y_inter = (t_win.height / 2) - (sp_size / 2);
	x_inter = (sp_ang - t_win.toor * M_PI / 180) * t_win.width /
	(60.0 * M_PI / 180) + (t_win.width / 2 - sp_size / 2);
	sp_render(x_inter, y_inter, sp_size, lst);
}

void	print__sprite(t_list **lst)
{
	t_list	*temp;

	t_win.directione = 's';
	temp = *lst;
	while (temp)
	{
		ft_sprite(temp);
		temp = temp->next;
	}
}
