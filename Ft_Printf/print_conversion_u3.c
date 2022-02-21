/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_u3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:20:56 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 14:35:56 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'u' with prs after '%'
** ex : %.96u
*/

int		write_psg_u(int itwl, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if ((len_nbr_u(d) >= itwl && itwl != 0) || (len_nbr_u(d) > itwl && d != 0))
		nbr = nbr + ft_itoa_u(d);
	else if ((len_nbr_u(d) < itwl && itwl != 0))
	{
		i = itwl - len_nbr_u(d);
		while (i > 0)
		{
			nbr = nbr + write(1, "0", 1);
			i--;
		}
		nbr = nbr + ft_itoa_u(d);
	}
	return (nbr);
}

/*
** print conversion 'u' with flag 0 and nbr after '%'
** ex : %023u
** ex : %023u
*/

int		u_with_flag_zero_and_nbr(int x, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
		nbr += print_u_with_flag_zero_and_neg_nbr(x, d);
	else
	{
		i = x - len_nbr_u(d);
		while (i-- > 0)
			nbr = nbr + write(1, "0", 1);
		nbr = nbr + ft_itoa_u(d);
	}
	return (nbr);
}

/*
** print conversion 'u' with flag 0 and nbr after '%'
** ex : %0*u && * < 0
*/

int		print_u_with_flag_zero_and_neg_nbr(int x, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	nbr = nbr + ft_itoa_u(d);
	i = (x * -1) - len_nbr_u(d);
	while (i-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'u' with flag 0 after '%'
** ex : %0*.73u && * < 0
** ex : %0*.*u && *2 < 0
*/

void	u_flag_0_and_negnbr_and_psg(int x, int itwl, unsigned int d, int *nbr)
{
	int i;

	x = x * -1;
	if (itwl < 0)
	{
		*nbr = *nbr + ft_itoa_u(d);
		i = x - len_nbr_u(d);
		*nbr = *nbr + write_n_cs(' ', i);
	}
	else
	{
		i = itwl - len_nbr_u(d);
		*nbr = *nbr + write_n_cs('0', i);
		*nbr = (d != 0) ? *nbr + ft_itoa_u(d) : *nbr + write(1, " ", 1);
		i = (itwl > len_nbr_u(d)) ? x - itwl : x - len_nbr_u(d);
		*nbr = *nbr + write_n_cs(' ', i);
	}
}

/*
** print conversion 'u' with flag 0 after '%'
** ex : %0*.73u && * > 0
** ex : %0*.*u && *2 > 0 && * > 0
*/

void	u_flag_0_and_posnbr_and_psg(int x, int itwl, unsigned int d, int *nbr)
{
	int i;

	if (d == 0 && itwl == 0 && x == 0)
		*nbr = *nbr;
	else
	{
		if (x < 0)
			x = x * -1;
		i = (itwl > len_nbr_u(d)) ? x - itwl : x - len_nbr_u(d);
		*nbr = *nbr + write_n_cs(' ', i);
		i = itwl - len_nbr_u(d);
		*nbr = *nbr + write_n_cs('0', i);
		if (d == 0 && itwl == 0)
			*nbr = *nbr + write(1, " ", 1);
		else
			*nbr = *nbr + ft_itoa_u(d);
	}
}
