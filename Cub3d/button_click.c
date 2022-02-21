/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_click.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:55:13 by wben-sai          #+#    #+#             */
/*   Updated: 2020/11/23 17:36:21 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_list **lst)
{
	mlx_clear_window(t_win.mlx_ptr, t_win.win_ptr);
	if (key == 13)
		key_click_up(lst);
	if (key == 1)
		key_click_down(lst);
	if (key == 124)
		t_win.toor = t_win.toor + 10;
	if (key == 123)
		t_win.toor = t_win.toor - 10;
	if (key == 53)
		freepath(lst);
	if (key == 0)
		key_click_left(lst);
	if (key == 2)
		key_click_right(lst);
	if (key == 126)
		t_win.up_down += 10;
	if (key == 125)
		t_win.up_down -= 10;
	normalise(&t_win.toor);
	print_player(lst);
	mlx_put_image_to_window(t_win.mlx_ptr, t_win.win_ptr, t_win.img, 0, 0);
	return (0);
}
