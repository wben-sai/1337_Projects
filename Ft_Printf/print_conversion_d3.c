/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_d3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:20:56 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 14:36:44 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'd' with prs after '%'
** ex : %.96d
*/

int		write_psg(int itwl, int d)
{
	int nbr;
	int i;

	nbr = 0;
	if ((len_nbr(d) >= itwl && itwl != 0) || (len_nbr(d) > itwl && d != 0))
		nbr = nbr + ft_itoa(d);
	else if ((len_nbr(d) < itwl && itwl != 0) || (len_nbr(d) > itwl && d != 0))
	{
		i = itwl - len_nbr(d);
		if (d < 0)
		{
			nbr = nbr + write(1, "-", 1);
			d = d * -1;
		}
		while (i > 0)
		{
			nbr = nbr + write(1, "0", 1);
			i--;
		}
		nbr = nbr + ft_itoa(d);
	}
	return (nbr);
}

/*
** print conversion 'd' with flag 0 and nbr after '%'
** ex : %023d
** ex : %023d
*/

int		print_d_with_flag_zero_and_nbr(int x, int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
		nbr += print_d_with_flag_zero_and_neg_nbr(x, d);
	else
	{
		if (d < 0)
		{
			nbr = nbr + write(1, "-", 1);
			d = d * -1;
			x--;
		}
		i = x - len_nbr(d);
		while (i-- > 0)
			nbr = nbr + write(1, "0", 1);
		nbr = nbr + ft_itoa(d);
	}
	return (nbr);
}

/*
** print conversion 'd' with flag 0 and nbr after '%'
** ex : %0*d && * < 0
*/

int		print_d_with_flag_zero_and_neg_nbr(int x, int d)
{
	int nbr;
	int i;

	nbr = 0;
	nbr = nbr + ft_itoa(d);
	i = (x * -1) - len_nbr(d);
	if (d < 0)
		i--;
	while (i-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'd' with flag 0 after '%'
** ex : %0*.73d && * < 0
** ex : %0*.*d && *2 < 0
*/

void	print_d_flag_0_and_negnbr_and_psg(int x, int itwl, int d, int *nbr)
{
	int i;

	x = x * -1;
	if (itwl < 0)
	{
		*nbr = *nbr + ft_itoa(d);
		i = x - len_nbr(d);
		if (d < 0)
			i--;
		*nbr = *nbr + write_n_cs(' ', i);
	}
	else
	{
		i = itwl - len_nbr(d);
		if (d < 0)
		{
			*nbr = *nbr + write(1, "-", 1);
			d = d * -1;
			x--;
		}
		*nbr = *nbr + write_n_cs('0', i);
		*nbr = (d != 0) ? *nbr + ft_itoa(d) : *nbr + write(1, " ", 1);
		i = (itwl > len_nbr(d)) ? x - itwl : x - len_nbr(d);
		*nbr = *nbr + write_n_cs(' ', i);
	}
}

/*
** print conversion 'd' with flag 0 after '%'
** ex : %0*.73d && * > 0
** ex : %0*.*d && *2 > 0 && * > 0
*/

void	print_d_flag_0_and_posnbr_and_psg(int x, int itwl, int d, int *nbr)
{
	int i;

	if (d == 0 && itwl == 0 && x == 0)
		*nbr = *nbr;
	else
	{
		if (x < 0)
			x = x * -1;
		if (d < 0)
			x--;
		i = (itwl > len_nbr(d)) ? x - itwl : x - len_nbr(d);
		*nbr = *nbr + write_n_cs(' ', i);
		i = itwl - len_nbr(d);
		if (d < 0)
		{
			*nbr = *nbr + write(1, "-", 1);
			d = d * -1;
		}
		*nbr = *nbr + write_n_cs('0', i);
		if (d == 0 && itwl == 0)
			*nbr = *nbr + write(1, " ", 1);
		else
			*nbr = *nbr + ft_itoa(d);
	}
}
