/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_u4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:21:32 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 14:23:34 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'u' with flag 0 after '%'
** ex : %042.73u
** ex : %056.*u
*/

int		f0_itl_u(int x, int itwl, unsigned int d)
{
	int nbr;
	int i;

	nbr = 0;
	if (x < 0)
		u_flag_0_and_negnbr_and_psg(x, itwl, d, &nbr);
	else
	{
		if (itwl < 0)
		{
			i = x - len_nbr_u(d);
			nbr = nbr + write_n_cs('0', i);
			nbr = nbr + ft_itoa_u(d);
		}
		else
			u_flag_0_and_posnbr_and_psg(x, itwl, d, &nbr);
	}
	return (nbr);
}

/*
** print conversion 'u' with flag 0 after '%'
** ex : %023u
** ex : %0*u
** ex : %042.73u
** ex : %0*.*u
*/

int		print_u_with_flag_zero(const char *args, va_list va_lst, int x, int i)
{
	int nbr;
	int box;

	nbr = 0;
	if (ft_atoi(args + i + 1) != 0)
	{
		while (args[i] <= '9' && args[i] >= '0')
			i++;
		if (args[i] != '.')
			nbr += u_with_flag_zero_and_nbr(x, va_arg(va_lst, unsigned int));
		else
		{
			if (args[i + 1] == '*')
				box = va_arg(va_lst, int);
			else
				box = ft_atoi(args + i + 1);
			if (args[++i] == '*')
				nbr += f0_itl_u(x, box, va_arg(va_lst, unsigned int));
			else
				nbr += f0_itl_u(x, box, va_arg(va_lst, unsigned int));
		}
	}
	else
		nbr = nbr + u_with_flag_zero_outnbr(args, va_lst, i);
	return (nbr);
}

/*
** print conversion 'u' with flag 0 after '%'
** ex : %0*u
** ex : %0*.*u
** ex : %0*.73u
** ex : %0.*u
*/

int		u_with_flag_zero_outnbr(const char *args, va_list va_lst, int i)
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
			nbr += f0_itl_u(0, bx, va_arg(va_lst, unsigned int));
		}
		else
		{
			bx = ft_atoi(args + i + 2);
			nbr += f0_itl_u(0, bx, va_arg(va_lst, unsigned int));
		}
		return (nbr);
	}
	else if (args[i + 1] == '*')
		return (nbr + u_with_flag_zero_itwl(args, va_lst, i));
	box = va_arg(va_lst, unsigned int);
	if (box != 0)
		nbr = nbr + ft_itoa_u(box);
	return (nbr);
}

/*
** print conversion 'u' with flag 0 after '%'
** ex : %0*u
** ex : %0*.*u
** ex : %0*.73u
** ex : %0.*u
*/

int		u_with_flag_zero_itwl(const char *args, va_list va_lst, int i)
{
	int bx;
	int nbr;
	int box;

	nbr = 0;
	bx = va_arg(va_lst, int);
	if (args[i + 2] != '.')
		nbr += u_with_flag_zero_and_nbr(bx, va_arg(va_lst, unsigned int));
	else
	{
		if (args[i + 3] == '*')
		{
			box = va_arg(va_lst, int);
			nbr += f0_itl_u(bx, box, va_arg(va_lst, unsigned int));
		}
		else
		{
			box = ft_atoi(args + i + 3);
			nbr += f0_itl_u(bx, box, va_arg(va_lst, unsigned int));
		}
	}
	return (nbr);
}

/*
** print conversion 'u' with prs after '%'
** ex : %.96u
** ex : %.*u
*/

int		conversion_u_psg(va_list va_lst, int i, const char *args)
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
		nbr += write_psg_u(bx, x);
	}
	else if (args[i + 1] != 'u')
		nbr += write_psg_u(ft_atoi(args + i + 1), va_arg(va_lst, unsigned int));
	else if (args[i + 1] == 'u')
	{
		bx = va_arg(va_lst, unsigned int);
		if (bx != 0)
			nbr = nbr + ft_itoa_u(bx);
	}
	return (nbr);
}
