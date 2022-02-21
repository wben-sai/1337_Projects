/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_x2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:34:09 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 14:52:56 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'x' with flag nbr without psg
** ex : %24x
** ex : %-85x
*/

int	x_f_nbr(int x, unsigned int d)
{
	int nbr;

	nbr = 0;
	if (x < 0)
	{
		x = (x * -1) - len_nbr_x(d);
		nbr = nbr + ft_itoa_x(d);
		while (x-- > 0)
			nbr = nbr + write(1, " ", 1);
	}
	else if (x >= 0)
	{
		x = x - len_nbr_x(d);
		while (x-- > 0)
			nbr = nbr + write(1, " ", 1);
		nbr = nbr + ft_itoa_x(d);
	}
	return (nbr);
}

/*
** print conversion 'x' with flag negative nbr and prs
** ex : %-24.23x
** ex : %-85.*x
*/

int	x_f_nb_psg_neg(int x, int itwl, unsigned int d, int xx)
{
	int nbr;
	int i;

	nbr = 0;
	x = (len_nbr_x(d) > itwl) ? x - len_nbr_x(d) : x - itwl;
	while (x-- > 0)
		nbr = nbr + write(1, " ", 1);
	if (itwl > len_nbr_x(d))
	{
		i = itwl - len_nbr_x(d);
		while (i-- > 0)
			nbr = nbr + write(1, "0", 1);
	}
	if (itwl == 0 && d == 0 && xx != 0)
		nbr = nbr + write(1, " ", 1);
	else if (itwl != 0 || d != 0)
		nbr = nbr + ft_itoa_x(d);
	return (nbr);
}

/*
** print conversion 'x' with flag nbr and prs
** ex : %57.96x
** ex : %-24.23x
** ex : %36.*x
** ex : %-85.*x
*/

int	x_f_nb_psg(int x, int itwl, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
	{
		i = (len_nbr_x(d) >= itwl) ? (x * -1) - len_nbr_x(d) : (x * -1) - itwl;
		if (itwl > len_nbr_x(d))
			nbr = nbr + normini_x(itwl, &d);
		if ((x != 0 && d != 0) || (x != 0 && itwl != 0))
			nbr = nbr + ft_itoa_x(d);
		else
			i++;
		while (i-- > 0)
			nbr = nbr + write(1, " ", 1);
	}
	else if (x >= 0)
		nbr = nbr + x_f_nb_psg_neg(x, itwl, d, x);
	return (nbr);
}

int	normini_x(int itwl, unsigned int *d)
{
	int nbr;
	int i;

	nbr = 0;
	i = itwl - len_nbr_x(*d);
	while (i-- > 0)
		nbr = nbr + write(1, "0", 1);
	return (nbr);
}

/*
** print conversion 'x' with flag nbr after '%'
** ex : %12x
** ex : %-10x
** ex : %57.96x
** ex : %-24.23x
** ex : %36.*x
** ex : %-85.*x
*/

int	print_x_with_flag_nbr(const char *args, va_list va_lst, int x, int i)
{
	int nbr;
	int box;

	nbr = 0;
	if (args[i] == '-')
		i++;
	while (args[i] <= '9' && args[i] >= '0')
		i++;
	if (args[i] != '.')
		nbr = nbr + x_f_nbr(x, va_arg(va_lst, unsigned int));
	else
	{
		if (args[i + 1] == '*')
		{
			box = va_arg(va_lst, int);
			nbr += x_f_nb_psg(x, box, va_arg(va_lst, unsigned int));
		}
		else
		{
			box = ft_atoi(args + i + 1);
			nbr += x_f_nb_psg(x, box, va_arg(va_lst, unsigned int));
		}
	}
	return (nbr);
}
