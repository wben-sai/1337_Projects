/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:20:56 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 16:58:39 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 'p' with nbr after '%'
** ex : %*p
*/

int	print_p_flg_nbr_not_psg(int x, unsigned long d)
{
	int nbr;

	nbr = 0;
	if (x < 0)
	{
		x = (x * -1) - len_nbr_p(d);
		nbr = nbr + ft_itoa_p(d);
		while (x > 2)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
	}
	else if (x >= 0)
	{
		x = x - len_nbr_p(d);
		while (x > 2)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
		nbr = nbr + ft_itoa_p(d);
	}
	return (nbr);
}

/*
** print conversion 'p' with nbr after '%'
** ex : %96p
*/

int	print_p_with_flag_nbr(const char *args, va_list va_lst, int x, int i)
{
	int				nbr;
	unsigned long	box;

	nbr = 0;
	if (args[i] == '-')
		i++;
	while (args[i] <= '9' && args[i] >= '0')
		i++;
	box = va_arg(va_lst, unsigned long);
	if (args[i] == '.' && args[i + 1] == 'p' && box == 0)
	{
		if (x > 0)
		{
			nbr = nbr + write_n_cs(' ', x - 2);
			nbr = nbr + write(1, "0x", 2);
		}
		else
		{
			nbr = nbr + write(1, "0x", 2);
			nbr = nbr + write_n_cs(' ', (x * -1) - 2);
		}
	}
	else
		nbr = nbr + print_p_flg_nbr_not_psg(x, box);
	return (nbr);
}

/*
** print conversion 'p' with nbr after '%'
** ex : %*p
*/

int	print_conversion_p_with_flag_itwl(va_list va_lst, int i, const char *args)
{
	int nbr;
	int bx;
	int box;

	nbr = 0;
	bx = va_arg(va_lst, int);
	box = va_arg(va_lst, unsigned long);
	if (args[i + 1] != '.')
		nbr = nbr + print_p_flg_nbr_not_psg(bx, box);
	else if (args[i + 2] == 'p')
	{
		nbr = nbr + print_conversion_p_with_flag_pp(bx, box);
	}
	return (nbr);
}

/*
** print conversion 'p' with . after '%'
** ex : %.p
*/

int	print_conversion_p_with_flag_pp(int bx, int box)
{
	int nbr;

	nbr = 0;
	if (bx == 0 && box == 0)
		nbr = nbr + write(1, "0x", 2);
	else if (box == 0)
	{
		if (bx < 0)
		{
			nbr = nbr + write(1, "0x", 2);
			bx = bx * -1;
			while ((bx-- - 2) > 0)
				nbr = nbr + write(1, " ", 1);
		}
		else
		{
			while ((bx-- - 2) > 0)
				nbr = nbr + write(1, " ", 1);
			nbr = nbr + write(1, "0x", 2);
		}
	}
	else
		nbr = nbr + print_p_flg_nbr_not_psg(bx, box);
	return (nbr);
}

int	print_conversion_p(va_list va_lst, int i, const char *args)
{
	int nbr;
	int x;
	int box;

	nbr = 0;
	x = ft_atoi(args + i);
	if (x != 0 && args[i] != '0')
		nbr = nbr + print_p_with_flag_nbr(args, va_lst, x, i);
	else if (args[i] == '*')
		nbr = nbr + print_conversion_p_with_flag_itwl(va_lst, i, args);
	else if (args[i] == '-' && args[i + 1] == '*')
		nbr = nbr + print_p_with_flag_minus_itwl(va_lst, i + 2, args);
	else if (args[i] == 'p')
		nbr = nbr + ft_itoa_p(va_arg(va_lst, unsigned long));
	else if (args[i] == '.')
	{
		box = va_arg(va_lst, unsigned long);
		if (args[i + 1] == 'p' && box == 0)
			nbr = nbr + write(1, "0x", 2);
		else
			nbr = nbr + ft_itoa_p(box);
	}
	else
		nbr = nbr + ft_itoa_p(va_arg(va_lst, unsigned long));
	return (nbr);
}
