/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_d2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:34:09 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/14 14:05:36 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'd' with flag nbr without psg
** ex : %24d
** ex : %-85d
*/

int	d_f_nbr(int x, int d)
{
	int nbr;

	nbr = 0;
	if (x < 0)
	{
		if (d < 0)
			x++;
		x = (x * -1) - len_nbr(d);
		nbr = nbr + ft_itoa(d);
		while (x-- > 0)
			nbr = nbr + write(1, " ", 1);
	}
	else if (x >= 0)
	{
		if (d < 0)
			x--;
		x = x - len_nbr(d);
		while (x-- > 0)
			nbr = nbr + write(1, " ", 1);
		nbr = nbr + ft_itoa(d);
	}
	return (nbr);
}

/*
** print conversion 'd' with flag negative nbr and prs
** ex : %-24.23d
** ex : %-85.*d
*/

int	d_f_nb_psg_neg(int x, int itwl, int d, int xx)
{
	int nbr;
	int i;

	nbr = 0;
	x = (len_nbr(d) > itwl) ? x - len_nbr(d) : x - itwl;
	if (d < 0)
		x--;
	while (x-- > 0)
		nbr = nbr + write(1, " ", 1);
	if (itwl > len_nbr(d))
	{
		i = itwl - len_nbr(d);
		if (d < 0)
		{
			nbr = nbr + write(1, "-", 1);
			d = d * -1;
		}
		while (i-- > 0)
			nbr = nbr + write(1, "0", 1);
	}
	if (itwl == 0 && d == 0 && xx != 0)
		nbr = nbr + write(1, " ", 1);
	else if (itwl != 0 || d != 0)
		nbr = nbr + ft_itoa(d);
	return (nbr);
}

/*
** print conversion 'd' with flag nbr and prs
** ex : %57.96d
** ex : %-24.23d
** ex : %36.*d
** ex : %-85.*d
*/

int	d_f_nb_psg(int x, int itwl, int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
	{
		i = (len_nbr(d) >= itwl) ? (x * -1) - len_nbr(d) : (x * -1) - itwl;
		if (d < 0)
			i--;
		if (itwl > len_nbr(d))
			nbr = nbr + normini(itwl, &d);
		if ((x != 0 && d != 0) || (x != 0 && itwl != 0))
			nbr = nbr + ft_itoa(d);
		else
			i++;
		while (i-- > 0)
			nbr = nbr + write(1, " ", 1);
	}
	else if (x >= 0)
		nbr = nbr + d_f_nb_psg_neg(x, itwl, d, x);
	return (nbr);
}

int	normini(int itwl, int *d)
{
	int nbr;
	int i;

	nbr = 0;
	i = itwl - len_nbr(*d);
	if (*d < 0)
	{
		*d = *d * -1;
		nbr = nbr + write(1, "-", 1);
	}
	while (i-- > 0)
		nbr = nbr + write(1, "0", 1);
	return (nbr);
}

/*
** print conversion 'd' with flag nbr after '%'
** ex : %12d
** ex : %-10d
** ex : %57.96d
** ex : %-24.23d
** ex : %36.*d
** ex : %-85.*d
*/

int	print_d_with_flag_nbr(const char *args, va_list va_lst, int x, int i)
{
	int nbr;

	nbr = 0;
	if (args[i] == '-')
		i++;
	while (args[i] <= '9' && args[i] >= '0')
		i++;
	if (args[i] != '.')
		nbr = nbr + d_f_nbr(x, va_arg(va_lst, int));
	else
	{
		if (args[i + 1] == '*')
			nbr += d_f_nb_psg(x, va_arg(va_lst, int), va_arg(va_lst, int));
		else
			nbr += d_f_nb_psg(x, ft_atoi(args + i + 1), va_arg(va_lst, int));
	}
	return (nbr);
}
