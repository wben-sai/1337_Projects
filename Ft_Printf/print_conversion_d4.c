/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_d4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:21:32 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/14 16:34:44 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'd' with flag 0 after '%'
** ex : %042.73d
** ex : %056.*d
*/

int		f0_itl(int x, int itwl, int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
		print_d_flag_0_and_negnbr_and_psg(x, itwl, d, &nbr);
	else
	{
		if (itwl < 0)
		{
			i = x - len_nbr(d);
			if (d < 0)
			{
				nbr = nbr + write(1, "-", 1);
				d = d * -1;
				i--;
			}
			nbr = nbr + write_n_cs('0', i);
			nbr = nbr + ft_itoa(d);
		}
		else
			print_d_flag_0_and_posnbr_and_psg(x, itwl, d, &nbr);
	}
	return (nbr);
}

/*
** print conversion 'd' with flag 0 after '%'
** ex : %023d
** ex : %0*d
** ex : %042.73d
** ex : %0*.*d
*/

int		print_d_with_flag_zero(const char *args, va_list va_lst, int x, int i)
{
	int nbr;

	nbr = 0;
	if (ft_atoi(args + i + 1) != 0)
	{
		while (args[i] <= '9' && args[i] >= '0')
			i++;
		if (args[i] != '.')
			nbr = nbr + print_d_with_flag_zero_and_nbr(x, va_arg(va_lst, int));
		else
		{
			if (args[++i] == '*')
				nbr = nbr + f0_itl(x, va_arg(va_lst, int), va_arg(va_lst, int));
			else
				nbr = nbr + f0_itl(x, ft_atoi(args + i), va_arg(va_lst, int));
		}
	}
	else
		nbr = nbr + d_with_flag_zero_outnbr(args, va_lst, i);
	return (nbr);
}

/*
** print conversion 'd' with flag 0 after '%'
** ex : %0*d
** ex : %0*.*d
** ex : %0*.73d
** ex : %0.*d
*/

int		d_with_flag_zero_outnbr(const char *args, va_list va_lst, int i)
{
	int nbr;
	int box;

	nbr = 0;
	box = va_arg(va_lst, int);
	if (args[i + 1] == '.' && args[i + 2] != 'd')
		if (args[i + 2] == '*')
			nbr += f0_itl(0, box, va_arg(va_lst, int));
		else
			nbr += f0_itl(0, ft_atoi(args + i + 2), box);
	else if (args[i + 1] == '*')
	{
		if (args[i + 2] != '.')
			nbr += print_d_with_flag_zero_and_nbr(box, va_arg(va_lst, int));
		else
		{
			if (args[i + 3] == '*')
				nbr += f0_itl(box, va_arg(va_lst, int), va_arg(va_lst, int));
			else
				nbr += f0_itl(box, ft_atoi(args + i + 3), va_arg(va_lst, int));
		}
	}
	else if (box != 0)
		nbr = nbr + ft_itoa(box);
	return (nbr);
}

/*
** print conversion 'd' with prs after '%'
** ex : %.96d
** ex : %.*d
*/

int		conversion_d_psg(va_list va_lst, int i, const char *args)
{
	int bx;
	int x;
	int nbr;

	nbr = 0;
	if (args[i + 1] == '*')
	{
		bx = va_arg(va_lst, int);
		x = va_arg(va_lst, int);
		if (bx == 0 && x == 0)
			return (nbr);
		nbr += write_psg(bx, x);
	}
	else if (args[i + 1] != 'd' || args[i + 1] != 'i')
		nbr += write_psg(ft_atoi(args + i + 1), va_arg(va_lst, int));
	else if (args[i + 1] == 'd' || args[i + 1] != 'i')
	{
		bx = va_arg(va_lst, int);
		if (bx != 0)
			nbr = nbr + ft_itoa(bx);
	}
	return (nbr);
}
