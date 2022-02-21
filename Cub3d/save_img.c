/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:09:22 by wben-sai          #+#    #+#             */
/*   Updated: 2020/11/26 09:41:18 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_img_pix(int col, int row)
{
	int	param1;
	int	param2;
	int	param3;
	int	*get_pix;
	int clr;

	get_pix = (int *)mlx_get_data_addr(t_win.img, &param1, &param2, &param3);
	clr = get_pix[(t_win.img_height - row - 1) * t_win.img_width + col];
	t_win.buf[row * t_win.width_pt + col * 3 + 0] = fmod(clr, 256);
	t_win.buf[row * t_win.width_pt + col * 3 + 1] = fmod((clr / 256), 256);
	t_win.buf[row * t_win.width_pt + col * 3 + 2] = fmod(clr / 256 / 256, 256);
}

void	initialis_param_img(void)
{
	t_win.img_width = (int32_t)t_win.width;
	t_win.img_height = (int32_t)t_win.height;
	t_win.img_bitcount = 24;
	t_win.width_pt = ((t_win.img_width * t_win.img_bitcount + 31) / 32) * 4;
	t_win.imagesize = t_win.width_pt * t_win.img_height;
	t_win.bisize = 40;
	t_win.bfoffbits = 54;
	t_win.filesize = 54 + t_win.imagesize;
	t_win.biplanes = 1;
	t_win.header[54] = '\0';
	ft_memcpy(t_win.header, "BM", 2);
	ft_memcpy(t_win.header + 2, &t_win.filesize, 4);
	ft_memcpy(t_win.header + 10, &t_win.bfoffbits, 4);
	ft_memcpy(t_win.header + 14, &t_win.bisize, 4);
	ft_memcpy(t_win.header + 18, &t_win.img_width, 4);
	ft_memcpy(t_win.header + 22, &t_win.img_height, 4);
	ft_memcpy(t_win.header + 26, &t_win.biplanes, 2);
	ft_memcpy(t_win.header + 28, &t_win.img_bitcount, 2);
	ft_memcpy(t_win.header + 34, &t_win.imagesize, 4);
	t_win.buf = malloc(t_win.imagesize + 1);
	t_win.buf[t_win.imagesize] = '\0';
}

void	save_img(void)
{
	int		row;
	int		col;
	int		fout;

	mlx_put_image_to_window(t_win.mlx_ptr, t_win.win_ptr, t_win.img, 0, 0);
	initialis_param_img();
	row = 0;
	while (row < t_win.img_height)
	{
		col = 0;
		while (col < t_win.img_width)
			get_img_pix(col++, row);
		row++;
	}
	fout = open("Image.bmp", O_CREAT | O_RDWR, 0777);
	write(fout, t_win.header, 54);
	write(fout, (char*)t_win.buf, t_win.imagesize);
	close(fout);
	free(t_win.buf);
	exit(0);
}
