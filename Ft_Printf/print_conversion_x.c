/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:33:46 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/13 18:28:19 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conversion_x(va_list va_lst, int i, const char *args)
{
	int				nbr;
	int				x;
	unsigned int	bx;

	nbr = 0;
	x = ft_atoi(args + i);
	if (x != 0 && args[i] != '0')
		nbr = nbr + print_x_with_flag_nbr(args, va_lst, x, i);
	else if (args[i] == '*')
		nbr = nbr + print_conversion_x_with_flag_itwl(args, va_lst, i);
	else if (args[i] == '0')
		nbr = nbr + print_x_with_flag_zero(args, va_lst, x, i);
	else if (args[i] == '.')
		nbr = nbr + conversion_x_psg(va_lst, i, args);
	else if (args[i] == 'x')
		nbr = nbr + ft_itoa_x(va_arg(va_lst, unsigned int));
	else if (args[i] == '-' && args[i + 1] != 'x')
		nbr = nbr + print_x_with_flag_minus(args, va_lst, i);
	else
	{
		bx = va_arg(va_lst, unsigned int);
		nbr = nbr + ft_itoa_x(bx);
	}
	return (nbr);
}

/*
** print conversion 'x' with flag * after '%'
** ex : %-*x
** ex : %-*.56x
** ex : %-.*x
*/

int	print_x_with_flag_minus(const char *args, va_list va_lst, int i)
{
	int nbr;
	int box;
	int bx;

	nbr = 0;
	if (args[i + 1] == '*')
	{
		box = va_arg(va_lst, int);
		if (args[i + 2] != '.')
			nbr += print_x_flag_minus_outpsg(box, va_arg(va_lst, unsigned int));
		else
		{
			if (args[i + 3] == '*')
			{
				bx = va_arg(va_lst, int);
				nbr += x_flag_minus_psg(box, bx, va_arg(va_lst, unsigned int));
			}
			else
			{
				bx = ft_atoi(args + i + 3);
				nbr += x_flag_minus_psg(box, bx, va_arg(va_lst, unsigned int));
			}
		}
	}
	return (nbr);
}

/*
** print conversion 'x' with flag * after '%'
** ex : %-*.*x
** ex : %-*.56x
*/

int	x_flag_minus_psg(int x, int itwl, unsigned int d)
{
	int nbr;
	int i;
	int i2;

	nbr = 0;
	if (x < 0)
		x = x * -1;
	i = itwl - len_nbr_x(d);
	i2 = (itwl > len_nbr_x(d)) ? x - itwl : x - len_nbr_x(d);
	while (i-- > 0)
		nbr = nbr + write(1, "0", 1);
	nbr = nbr + ft_itoa_x(d);
	while (i2-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'x' with flag * after '%'
** ex : %-*x
** ex : %-*.56x
** ex : %-.*x
*/

int	print_x_flag_minus_outpsg(int itwl, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	nbr = nbr + ft_itoa_x(d);
	if (itwl < 0)
		itwl = itwl * -1;
	i = i + itwl - len_nbr_x(d);
	while (i-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 'x' with flag * after '%'
** ex : %*x
** ex : %*.56x
** ex : %98.*x
*/

int	print_conversion_x_with_flag_itwl(const char *args, va_list va_lst, int i)
{
	int nbr;
	int bx;
	int box;

	nbr = 0;
	if (args[i + 1] != '.')
	{
		bx = va_arg(va_lst, int);
		nbr = nbr + x_f_nbr(bx, va_arg(va_lst, unsigned int));
	}
	else
	{
		bx = va_arg(va_lst, int);
		if (args[i + 2] == '*')
		{
			box = va_arg(va_lst, int);
			nbr += x_f_nb_psg(bx, box, va_arg(va_lst, unsigned int));
		}
		else
		{
			box = ft_atoi(args + i + 2);
			nbr += x_f_nb_psg(bx, box, va_arg(va_lst, unsigned int));
		}
	}
	return (nbr);
}
