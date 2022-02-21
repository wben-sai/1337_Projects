/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:19:13 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 12:07:32 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*filling_ptr(char *p, int x, int n)
{
	int k;

	p[x] = '\0';
	x--;
	if (n >= 0)
	{
		while (x > -1)
		{
			k = n % 10;
			p[x] = k + '0';
			n = (n - (n % 10)) / 10;
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			k = (n % 10) * -1;
			p[x] = k + '0';
			n = (n - (n % 10)) / 10;
			x--;
		}
	}
	return (p);
}

static int		len_nbr(int n)
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

char			*ft_itoa(int n)
{
	int		x;
	int		y;
	char	*p;

	x = 0;
	y = 1;
	if (n < 0)
	{
		y = -1;
		x++;
	}
	x = x + len_nbr(n);
	p = malloc((sizeof(char) * x) + 1);
	if (p == NULL)
		return (NULL);
	if (y == -1)
		p[0] = '-';
	return (filling_ptr(p, x, n));
}
