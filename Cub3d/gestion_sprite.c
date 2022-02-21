/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/13 18:17:55 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_dist_sprite(t_list **lst)
{
	t_list *temp2;
	t_list *temp3;

	temp2 = *lst;
	temp3 = *lst;
	calc_dist(lst);
	while (temp2)
	{
		while (temp3)
		{
			if (temp2->dist > temp3->dist)
			{
				temp2->x = echonge(&temp3->x, temp2->x);
				temp2->y = echonge(&temp3->y, temp2->y);
				temp2->dist = echonge(&temp3->dist, temp2->dist);
			}
			temp3 = temp3->next;
		}
		temp3 = *lst;
		temp2 = temp2->next;
	}
}
