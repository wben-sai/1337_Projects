/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_sprite_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/03/13 16:37:07 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstnew(int x, int y, int dist, char c)
{
	t_list *nouveau;

	nouveau = malloc(sizeof(*nouveau));
	nouveau->x = x;
	nouveau->y = y;
	nouveau->dist = dist;
	nouveau->c = c;
	nouveau->next = NULL;
	return (nouveau);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *p;

	p = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->next = NULL;
	}
}

void	calc_dist(t_list **lst)
{
	t_list *temp;

	temp = *lst;
	while (temp)
	{
		temp->dist = sqrt(pow((t_win.x_player - temp->x), 2)
		+ pow((t_win.y_player - temp->y), 2));
		temp = temp->next;
	}
}

float	echonge(float *temp3, float temp2)
{
	float temp;

	temp = *temp3;
	*temp3 = temp2;
	return (temp);
}

int		rgbtoint(int r, int g, int b)
{
	return (65536 * r + 256 * g + b);
}
