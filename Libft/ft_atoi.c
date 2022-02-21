/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:52:34 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 11:54:15 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	test_max_min(long y, int z)
{
	if (y > 2147483648 && z == -1)
		return (0);
	if (y > 2147483647 && z == 1)
		return (-1);
	return (y * z);
}

int			ft_atoi(const char *str)
{
	int		x;
	long	y;
	int		z;

	x = 0;
	y = 0;
	z = 1;
	while ((str[x] != '\0' && (str[x] >= 9 && str[x] <= 13)) || str[x] == 32)
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			z = -1;
		x++;
	}
	while (str[x] != '\0')
	{
		if (str[x] >= '0' && str[x] <= '9' && y < 2147483647)
			y = (y * 10) + (str[x] - 48);
		else
			return (test_max_min(y, z));
		x++;
	}
	return (test_max_min(y, z));
}
