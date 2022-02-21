/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_s2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:59:16 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/13 20:13:00 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 's' with flag '*' after '%'
** ex : %*.s
*/

int	s_f_ps(int x)
{
	int nbr;

	nbr = 0;
	if (x < 0)
		x = x * -1;
	while (x-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

int	print_conversion_s(va_list va_lst, int i, const char *args)
{
	int x;
	int nbr;

	nbr = 0;
	x = ft_atoi(args + i);
	if (x != 0)
		nbr = nbr + print_s_with_flag_nbr(args, va_lst, x, i);
	else if (args[i] == '*')
		nbr = nbr + print_conversion_s_with_flag_itwl(args, va_lst, i);
	else if (args[i] == '-')
		nbr += print_conversion_s_with_flag_minus(args, va_lst, i);
	else if (args[i] == '.')
		if (args[i + 1] == '*')
			nbr += write_nbr_cs(va_arg(va_lst, int), va_arg(va_lst, char*));
		else
			nbr += write_nbr_cs(ft_atoi(args + i + 1), va_arg(va_lst, char*));
	else
		nbr = nbr + ft_putstr(va_arg(va_lst, char*));
	return (nbr);
}

/*
** print conversion 's' with flag '-' after '%'
** ex : %-*s
** ex : %-*.12s
** ex : %-*.s
*/

int	print_conversion_s_with_flag_minus(const char *args, va_list va_lst, int i)
{
	int nbr;
	int bx;

	nbr = 0;
	if (args[i + 1] == '*')
	{
		bx = va_arg(va_lst, int);
		if (bx > 0)
			bx = bx * -1;
		if (args[i + 2] != '.')
			nbr = nbr + print_s_flg_nbr_not_psg(bx, va_arg(va_lst, char*));
		else
		{
			nbr += print_s_flag_minus_psg(args, va_lst, i, bx);
		}
	}
	else if (args[i + 1] == 's')
		nbr = nbr + ft_putstr(va_arg(va_lst, char*));
	return (nbr);
}

/*
** print conversion 's' with flag '-' after '%'
** ex : %-*.12s
** ex : %-*.*s
*/

int	print_s_flag_minus_psg(const char *args, va_list va_lst, int i, int bx)
{
	int nbr;
	int box;

	nbr = 0;
	if (args[i + 3] == '*')
	{
		box = va_arg(va_lst, int);
		nbr += s_f_nb_psg(bx, box, va_arg(va_lst, char*));
	}
	else if (args[i + 3] == 's')
		nbr += s_f_ps(bx);
	else
	{
		box = ft_atoi(args + i + 3);
		nbr += s_f_nb_psg(bx, box, va_arg(va_lst, char*));
	}
	return (nbr);
}
