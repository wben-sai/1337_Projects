/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_x3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:20:56 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 15:00:34 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'x' with prs after '%'
** ex : %.96x
*/

int		write_psg_x(int itwl, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if ((len_nbr_x(d) >= itwl && itwl != 0) || (len_nbr_x(d) > itwl && d != 0))
		nbr = nbr + ft_itoa_x(d);
	else if ((len_nbr_x(d) < itwl && itwl != 0))
	{
		i = itwl - len_nbr_x(d);
		while (i > 0)
		{
			nbr = nbr + write(1, "0", 1);
			i--;
		}
		nbr = nbr + ft_itoa_x(d);
	}
	return (nbr);
}

/*
** print conversion 'x' with flag 0 and nbr after '%'
** ex : %023x
** ex : %023x
*/

int		x_with_flag_zero_and_nbr(int x, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
		nbr += print_x_with_flag_zero_and_neg_nbr(x, d);
	else
	{
		i = x - len_nbr_x(d);
		while (i-- > 0)
			nbr = nbr + write(1, "0", 1);
		nbr = nbr + ft_itoa_x(d);
	}
	return (nbr);
}

/*
** print conversion 'x' with flag 0 and nbr after '%'
** ex : %0*x && * < 0
*/

int		print_x_with_flag_zero_and_neg_nbr(int x, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	nbr = nbr + ft_itoa_x(d);
	i = (x * -1) - len_nbr_x(d);
	while (i-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'x' with flag 0 after '%'
** ex : %0*.73u && * < 0
** ex : %0*.*u && *2 < 0
*/

void	x_flag_0_and_negnbr_and_psg(int x, int itwl, unsigned int d, int *nbr)
{
	int i;

	x = x * -1;
	if (itwl < 0)
	{
		*nbr = *nbr + ft_itoa_x(d);
		i = x - len_nbr_x(d);
		*nbr = *nbr + write_n_cs(' ', i);
	}
	else
	{
		i = itwl - len_nbr_x(d);
		*nbr = *nbr + write_n_cs('0', i);
		*nbr = (d != 0) ? *nbr + ft_itoa_x(d) : *nbr + write(1, " ", 1);
		i = (itwl > len_nbr_x(d)) ? x - itwl : x - len_nbr_x(d);
		*nbr = *nbr + write_n_cs(' ', i);
	}
}

/*
** print conversion 'x' with flag 0 after '%'
** ex : %0*.73x && * > 0
** ex : %0*.*x && *2 > 0 && * > 0
*/

void	x_flag_0_and_posnbr_and_psg(int x, int itwl, unsigned int d, int *nbr)
{
	int i;

	if (d == 0 && itwl == 0 && x == 0)
		*nbr = *nbr;
	else
	{
		if (x < 0)
			x = x * -1;
		i = (itwl > len_nbr_x(d)) ? x - itwl : x - len_nbr_x(d);
		*nbr = *nbr + write_n_cs(' ', i);
		i = itwl - len_nbr_x(d);
		*nbr = *nbr + write_n_cs('0', i);
		if (d == 0 && itwl == 0)
			*nbr = *nbr + write(1, " ", 1);
		else
			*nbr = *nbr + ft_itoa_x(d);
	}
}
