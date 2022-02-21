/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:50:51 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 21:29:49 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_car_in_lif(const char *x, const char *y, int len_set)
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

static int		nb_c_rig(const char *x, const char *y, int len_set, int len_s1)
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

static char		*filling_ptr(char *ptr, const char *s1, size_t i, int r)
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

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
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
