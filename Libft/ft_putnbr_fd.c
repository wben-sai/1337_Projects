/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:46:47 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 14:06:39 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_nig(int x, int n, int fd)
{
	char	k;
	int		i;
	int		r;
	int		j;

	i = 0;
	r = n;
	j = 0;
	while (x > 0)
	{
		while (x - 1 > i++)
			r = (r - (r % 10)) / 10;
		k = (r * -1) + '0';
		write(fd, &k, 1);
		x--;
		i = 1;
		while (x > j++)
			i = i * 10;
		n = n % i;
		i = 0;
		j = 0;
		r = n;
	}
}

static void	write_pos(int x, int n, int fd)
{
	char	k;
	int		i;
	int		r;
	int		j;

	i = 0;
	r = n;
	j = 0;
	while (x > 0)
	{
		while (x - 1 > i++)
			r = (r - (r % 10)) / 10;
		k = r + '0';
		write(fd, &k, 1);
		x--;
		i = 1;
		while (x > j++)
			i = i * 10;
		n = n % i;
		i = 0;
		j = 0;
		r = n;
	}
}

static void	test_pos_nig(int x, int n, int fd)
{
	if (n >= 0)
		write_pos(x, n, fd);
	else
		write_nig(x, n, fd);
}

static int	len_nbr_n(int n)
{
	int x;

	x = 0;
	while (n != 0)
	{
		if ((n / 10) != 0)
			x++;
		n = n / 10;
	}
	return (x + 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		x;
	int		y;
	char	m;

	x = 0;
	y = 1;
	m = '-';
	if (n < 0)
	{
		y = -1;
		write(fd, &m, 1);
	}
	x = x + len_nbr_n(n);
	test_pos_nig(x, n, fd);
}
