/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_mx4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:21:32 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 15:26:32 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'X' with flag 0 after '%'
** ex : %042.73x
** ex : %056.*x
*/

int		f0_itl_x2(int x, int itwl, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
		x2_flag_0_and_negnbr_and_psg(x, itwl, d, &nbr);
	else
	{
		if (itwl < 0)
		{
			i = x - len_nbr_x2(d);
			nbr = nbr + write_n_cs('0', i);
			nbr = nbr + ft_itoa_x2(d);
		}
		else
			x2_flag_0_and_posnbr_and_psg(x, itwl, d, &nbr);
	}
	return (nbr);
}

/*
** print conversion 'X' with flag 0 after '%'
** ex : %023x
** ex : %0*x
** ex : %042.73x
** ex : %0*.*x
*/

int		print_x2_with_flag_zero(const char *args, va_list va_lst, int x, int i)
{
	int nbr;
	int box;

	nbr = 0;
	if (ft_atoi(args + i + 1) != 0)
	{
		while (args[i] <= '9' && args[i] >= '0')
			i++;
		if (args[i] != '.')
			nbr += x2_with_flag_zero_and_nbr(x, va_arg(va_lst, unsigned int));
		else
		{
			if (args[i + 1] == '*')
				box = va_arg(va_lst, int);
			else
				box = ft_atoi(args + i + 1);
			if (args[++i] == '*')
				nbr += f0_itl_x2(x, box, va_arg(va_lst, unsigned int));
			else
				nbr += f0_itl_x2(x, box, va_arg(va_lst, unsigned int));
		}
	}
	else
		nbr = nbr + x2_with_flag_zero_outnbr(args, va_lst, i);
	return (nbr);
}

/*
** print conversion 'X' with flag 0 after '%'
** ex : %0*x
** ex : %0*.*x
** ex : %0*.73x
** ex : %0.*x
*/

int		x2_with_flag_zero_outnbr(const char *args, va_list va_lst, int i)
{
	int				nbr;
	unsigned int	box;
	int				bx;

	nbr = 0;
	if (args[i + 1] == '.' && args[i + 2] != 'd')
	{
		if (args[i + 2] == '*')
		{
			bx = va_arg(va_lst, int);
			nbr += f0_itl_x2(0, bx, va_arg(va_lst, unsigned int));
		}
		else
		{
			bx = ft_atoi(args + i + 2);
			nbr += f0_itl_x2(0, bx, va_arg(va_lst, unsigned int));
		}
		return (nbr);
	}
	else if (args[i + 1] == '*')
		return (nbr + x2_with_flag_zero_itwl(args, va_lst, i));
	box = va_arg(va_lst, unsigned int);
	if (box != 0)
		nbr = nbr + ft_itoa_x2(box);
	return (nbr);
}

/*
** print conversion 'X' with flag 0 and '*' after '%'
** ex : %0*x
** ex : %0*.*x
** ex : %0*.73x
*/

int		x2_with_flag_zero_anditwl(const char *args, va_list va_lst, int i)
{
	int nbr;
	int box;
	int bx;

	nbr = 0;
	bx = va_arg(va_lst, int);
	if (args[i + 2] != '.')
		nbr += print_d_with_flag_zero_and_nbr(bx, va_arg(va_lst, unsigned int));
	else
	{
		if (args[i + 3] == '*')
		{
			box = va_arg(va_lst, int);
			nbr += f0_itl_x2(bx, box, va_arg(va_lst, unsigned int));
		}
		else
		{
			box = ft_atoi(args + i + 3);
			nbr += f0_itl_x2(bx, box, va_arg(va_lst, unsigned int));
		}
	}
	return (nbr);
}

/*
** print conversion 'X' with prs after '%'
** ex : %.96x
** ex : %.*x
*/

int		conversion_x2_psg(va_list va_lst, int i, const char *args)
{
	int				bx;
	unsigned int	x;
	int				nbr;

	nbr = 0;
	if (args[i + 1] == '*')
	{
		bx = va_arg(va_lst, int);
		x = va_arg(va_lst, unsigned int);
		if (bx == 0 && x == 0)
			return (nbr);
		nbr += write_psg_x2(bx, x);
	}
	else if (args[i + 1] != 'X')
	{
		bx = ft_atoi(args + i + 1);
		nbr += write_psg_x2(bx, va_arg(va_lst, unsigned int));
	}
	else if (args[i + 1] == 'X')
	{
		bx = va_arg(va_lst, unsigned int);
		if (bx != 0)
			nbr = nbr + ft_itoa_x2(bx);
	}
	return (nbr);
}
