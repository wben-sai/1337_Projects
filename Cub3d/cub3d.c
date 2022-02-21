/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:55:13 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/19 12:55:53 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_map(t_list **lst)
{
	char	*line;
	int		i;
	int		fd;

	t_win.str_map.disp = malloc((t_win.str_map.y_map + 1) * sizeof(char*));
	t_win.str_map.disp[t_win.str_map.y_map] = 0;
	i = t_win.len_file - t_win.str_map.y_map;
	fd = open(t_win.namefile, O_RDONLY);
	while (i-- > 0)
	{
		get_next_line(fd, &line);
		gestion_param(&line);
		free(line);
	}
	i = 0;
	while (i < t_win.str_map.y_map && get_next_line(fd, &line) >= 0)
	{
		t_win.str_map.disp[i] = ft_strdup_bylen(line, t_win.str_map.x_map);
		i++;
		free(line);
	}
	if (ckeck_map(lst) == 0)
		exit(0);
}

void	setdata(int a)
{
	t_win.win_ptr = mlx_new_window(t_win.mlx_ptr, t_win.width,
	t_win.height, "cub3d");
	t_win.img = mlx_new_image(t_win.mlx_ptr, t_win.width, t_win.height);
	t_win.addr = (int*)mlx_get_data_addr(t_win.img, &t_win.bits_per_pixel,
	&t_win.line_length, &t_win.endian);
	if (!(t_win.dataxmpno = mlx_xpm_file_to_image(t_win.mlx_ptr,
		t_win.wall_no, &t_win.x_xpm, &t_win.y_xpm)))
		ft_error("the image does not exist in \"NO\" \n");
	t_win.dataimgno = (int*)mlx_get_data_addr(t_win.dataxmpno, &a, &a, &a);
	if (!(t_win.dataxmpso = mlx_xpm_file_to_image(t_win.mlx_ptr,
	t_win.wall_so, &t_win.x_xpm, &t_win.y_xpm)))
		ft_error("the image does not exist in \"SO\" \n");
	t_win.dataimgso = (int*)mlx_get_data_addr(t_win.dataxmpso, &a, &a, &a);
	if (!(t_win.dataxmpwe = mlx_xpm_file_to_image(t_win.mlx_ptr,
	t_win.wall_we, &t_win.x_xpm, &t_win.y_xpm)))
		ft_error("the image does not exist in \"WE\" \n");
	t_win.dataimgwe = (int*)mlx_get_data_addr(t_win.dataxmpwe, &a, &a, &a);
	if (!(t_win.dataxmpea = mlx_xpm_file_to_image(t_win.mlx_ptr,
	t_win.wall_ea, &t_win.x_xpm, &t_win.y_xpm)))
		ft_error("the image does not exist in \"EA\" \n");
	t_win.dataimgea = (int*)mlx_get_data_addr(t_win.dataxmpea, &a, &a, &a);
	if (!(t_win.dataxmpsp = mlx_xpm_file_to_image(t_win.mlx_ptr,
	t_win.sprite, &t_win.x_xpm, &t_win.y_xpm)))
		ft_error("the image does not exist in \"S\" \n");
	t_win.dataimgsp = (int*)mlx_get_data_addr(t_win.dataxmpsp, &a, &a, &a);
}

void	ckeck_arg(int ac, char **av, t_list **lst)
{
	int x;

	if (ac != 3 && ac != 2)
		ft_error("Argement Error\n");
	x = ft_strlen(av[1]) - 1;
	if (av[1][x] != 'b' && av[1][x - 1] != 'u'
	&& av[1][x - 2] != 'c' && av[1][x - 3] != '.')
		ft_error("name file Inco \n");
	t_win.namefile = av[1];
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
		{
			read_file();
			my_map(lst);
			t_win.mlx_ptr = mlx_init();
			setdata(x);
			t_win.walls_dist = malloc(sizeof(float ) * t_win.width + 1);
			print_player(lst);
			save_img();
		}
		else
			ft_error("Name of last Argement Inco \n");
	}
}

void	read_file(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(t_win.namefile, O_RDONLY);
	if (fd == -1)
		ft_error("the file does not exist\n");
	while (get_next_line(fd, &line) == 1)
	{
		clac_x_y_map(line);
		free(line);
	}
	i = 0;
	if (ft_strlen(line) > t_win.str_map.x_map)
		t_win.str_map.x_map = ft_strlen(line);
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		t_win.str_map.y_map = t_win.str_map.y_map + 1;
	else
		ft_error("Inco last element in file\n");
	free(line);
	t_win.len_file = t_win.len_file + 1;
}

int		main(int ac, char **av)
{
	t_list	*lst;
	int		x;

	x = 0;
	lst = NULL;
	t_win.y_player = 0;
	t_win.x_player = 0;
	t_win.i = 0;
	t_win.str_map.y_map = 0;
	t_win.str_map.x_map = 0;
	t_win.len_file = 0;
	t_win.f = -1;
	t_win.c = -1;
	ckeck_arg(ac, av, &lst);
	read_file();
	my_map(&lst);
	t_win.mlx_ptr = mlx_init();
	setdata(x);
	t_win.walls_dist = malloc(sizeof(float ) * t_win.width + 1);
	print_player(&lst);
	mlx_put_image_to_window(t_win.mlx_ptr, t_win.win_ptr, t_win.img, 0, 0);
	mlx_hook(t_win.win_ptr, 2, 0, deal_key, &lst);
	mlx_hook(t_win.win_ptr, 17, 0, quit, &lst);
	mlx_loop(t_win.mlx_ptr);
	return (0);
}
