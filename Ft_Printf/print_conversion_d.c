/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:33:46 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/13 20:36:20 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conversion_d(va_list va_lst, int i, const char *args)
{
	int nbr;
	int x;
	int bx;

	nbr = 0;
	x = ft_atoi(args + i);
	if (x != 0 && args[i] != '0')
		nbr = nbr + print_d_with_flag_nbr(args, va_lst, x, i);
	else if (args[i] == '*')
		nbr = nbr + print_conversion_d_with_flag_itwl(args, va_lst, i);
	else if (args[i] == '0')
		nbr = nbr + print_d_with_flag_zero(args, va_lst, x, i);
	else if (args[i] == '.')
		nbr = nbr + conversion_d_psg(va_lst, i, args);
	else if (args[i] == 'd' || args[i] == 'i')
		nbr = nbr + ft_itoa(va_arg(va_lst, int));
	else if (args[i] == '-' && args[i + 1] != 'd' && args[i + 1] != 'i')
		nbr = nbr + print_d_with_flag_minus(args, va_lst, i);
	else
	{
		bx = va_arg(va_lst, int);
		nbr = nbr + ft_itoa(bx);
	}
	return (nbr);
}

/*
** print conversion 'd' with flag * after '%'
** ex : %-*d
** ex : %-*.56d
** ex : %-.*d
*/

int	print_d_with_flag_minus(const char *args, va_list va_lst, int i)
{
	int nbr;
	int box;
	int bx;

	nbr = 0;
	if (args[i + 1] == '*')
	{
		box = va_arg(va_lst, int);
		if (args[i + 2] != '.')
			nbr += print_d_flag_minus_outpsg(box, va_arg(va_lst, int));
		else
		{
			if (args[i + 3] == '*')
			{
				bx = va_arg(va_lst, int);
				nbr += print_d_flag_minus_psg(box, bx, va_arg(va_lst, int));
			}
			else
			{
				bx = ft_atoi(args + i + 3);
				nbr += print_d_flag_minus_psg(box, bx, va_arg(va_lst, int));
			}
		}
	}
	return (nbr);
}

/*
** print conversion 'd' with flag * after '%'
** ex : %-*.*d
** ex : %-*.56d
*/

int	print_d_flag_minus_psg(int x, int itwl, int d)
{
	int nbr;
	int i;
	int i2;

	nbr = 0;
	if (x < 0)
		x = x * -1;
	i = itwl - len_nbr(d);
	i2 = (itwl > len_nbr(d)) ? x - itwl : x - len_nbr(d);
	if (d < 0)
	{
		nbr = nbr + write(1, "-", 1);
		d = d * -1;
		i2--;
	}
	while (i-- > 0)
		nbr = nbr + write(1, "0", 1);
	nbr = nbr + ft_itoa(d);
	while (i2-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'd' with flag * after '%'
** ex : %-*d
** ex : %-*.56d
** ex : %-.*d
*/

int	print_d_flag_minus_outpsg(int itwl, int d)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	if (d < 0)
		i--;
	nbr = nbr + ft_itoa(d);
	if (d < 0)
		d = d * -1;
	if (itwl < 0)
		itwl = itwl * -1;
	i = i + itwl - len_nbr(d);
	while (i-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'd' with flag * after '%'
** ex : %*d
** ex : %*.56d
** ex : %98.*d
*/

int	print_conversion_d_with_flag_itwl(const char *args, va_list va_lst, int i)
{
	int nbr;
	int bx;

	nbr = 0;
	if (args[i + 1] != '.')
	{
		bx = va_arg(va_lst, int);
		nbr = nbr + d_f_nbr(bx, va_arg(va_lst, int));
	}
	else
	{
		if (args[i + 2] == '*')
		{
			bx = va_arg(va_lst, int);
			nbr += d_f_nb_psg(bx, va_arg(va_lst, int), va_arg(va_lst, int));
		}
		else
		{
			bx = va_arg(va_lst, int);
			nbr += d_f_nb_psg(bx, ft_atoi(args + i + 2), va_arg(va_lst, int));
		}
	}
	return (nbr);
}
