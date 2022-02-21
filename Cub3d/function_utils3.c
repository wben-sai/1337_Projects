/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/03/12 20:56:50 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_atoi(char *str)
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

static int	nbr_car_in_lif(char *x, char *y, int len_set)
{
	int i;
	int r;
	int a;

	i = 0;
	a = 0;
	r = 0;
	while (x[i] != '\0')
	{
		while (r < len_set)
		{
			if (x[i] == y[r])
			{
				a++;
				break ;
			}
			r++;
		}
		if (r == len_set)
			return (a);
		r = 0;
		i++;
	}
	return (a);
}

static int	nb_c_rig(char *x, char *y, int len_set, int len_s1)
{
	int i;
	int r;
	int a;

	i = 0;
	a = 0;
	r = 0;
	while (len_s1 > 0)
	{
		while (r < len_set)
		{
			if (x[len_s1] == y[r])
			{
				a++;
				break ;
			}
			r++;
		}
		if (r == len_set)
			return (a);
		r = 0;
		len_s1--;
	}
	return (a);
}

static char	*filling_ptr(char *ptr, char *s1, size_t i, int r)
{
	int x;
	int y;

	x = 0;
	y = ft_strlen(s1) - (r + i);
	while (y > 0)
	{
		ptr[x] = s1[i + x];
		x++;
		y--;
	}
	ptr[x] = '\0';
	return (ptr);
}

char		*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		r;
	char	*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	r = 0;
	i = nbr_car_in_lif(s1, set, ft_strlen(set));
	if (ft_strlen(s1) != i)
		r = nb_c_rig(s1, set, ft_strlen(set), ft_strlen(s1) - 1);
	ptr = malloc((sizeof(char) * (ft_strlen(s1) - (r + i))) + 1);
	if (ptr == NULL)
		return (NULL);
	return (filling_ptr(ptr, s1, i, r));
}
