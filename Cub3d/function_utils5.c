/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/03/12 20:56:50 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalise(float *toor)
{
	while (*toor >= 360)
		*toor = *toor - 360;
	while (*toor < 0)
		*toor = *toor + 360;
}

void	freeparam(char **param)
{
	int i;

	i = -1;
	if (param)
	{
		while (param[++i] != 0 && param[i] != '\0')
		{
			free(param[i]);
			param[i] = NULL;
		}
		free(param);
	}
}

void	sheck_resul(void)
{
	if (t_win.width == 0 || t_win.height == 0)
		ft_error("the resolution does not exist\n");
	if (t_win.f == -1)
		ft_error("the F does not exist\n");
	if (t_win.c == -1)
		ft_error("the C does not exist\n");
}

void	deletelist(t_list **head_ref)
{
	t_list *current;
	t_list *next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

void	freepath(t_list **lst)
{
	deletelist(lst);
	freeparam(t_win.str_map.disp);
	if (t_win.wall_no != NULL)
		free(t_win.wall_no);
	if (t_win.wall_so != NULL)
		free(t_win.wall_so);
	if (t_win.wall_we != NULL)
		free(t_win.wall_we);
	if (t_win.wall_ea != NULL)
		free(t_win.wall_ea);
	if (t_win.sprite != NULL)
		free(t_win.sprite);
	exit(0);
}
