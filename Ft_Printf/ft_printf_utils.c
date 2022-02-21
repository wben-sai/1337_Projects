/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:52:34 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/12 19:07:39 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
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
		while (str[x++] == '-')
			z = -1;
		x--;
	}
	while (str[x] != '\0')
	{
		if (str[x] >= '0' && str[x] <= '9' && y < 2147483647)
			y = (y * 10) + (str[x] - 48);
		else
			return (y * z);
		x++;
	}
	return (y * z);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(const char *s)
{
	int i;
	int nbr;

	nbr = 0;
	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		nbr = nbr + write(1, &s[i], 1);
		i++;
	}
	return (nbr);
}

int	write_nbr_cs(int nbr, char *s)
{
	int i;
	int x;

	x = 0;
	i = 0;
	if (s == NULL)
		s = "(null)";
	if (nbr < 0)
		nbr = ft_strlen(s);
	while (nbr > i && s[i] != '\0')
	{
		x = x + write(1, &s[i], 1);
		i++;
	}
	return (x);
}

int	write_n_cs(char c, int n)
{
	int nbr;

	nbr = 0;
	while (n-- > 0)
		nbr = nbr + write(1, &c, 1);
	return (nbr);
}
