/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_por.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:20:56 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/06 20:18:39 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion '%' with nbr after '%'
** ex : %32%
** ex : %*%
*/

int	print_por_flg_nbr_not_psg(int x)
{
	int nbr;

	nbr = 0;
	if (x < 0)
	{
		x = (x * -1) - 1;
		nbr = nbr + write(1, "%", 1);
		while (x > 0)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
	}
	else if (x >= 0)
	{
		x = x - 1;
		while (x > 0)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
		nbr = nbr + write(1, "%", 1);
	}
	return (nbr);
}

/*
** print conversion '%' with * after '%'
** ex : %*%
*/

int	print_conversion_por_with_flag_itwl(va_list va_lst)
{
	int nbr;
	int bx;

	nbr = 0;
	bx = va_arg(va_lst, int);
	nbr = nbr + print_por_flg_nbr_not_psg(bx);
	return (nbr);
}

/*
** print conversion '%' with 0 after '%'
** ex : %032%
** ex : %0*%
*/

int	print_por_with_flag_zero_and_nbr(int x)
{
	int nbr;
	int i;

	nbr = 0;
	i = 1;
	if (i >= x)
		nbr = nbr + write(1, "%", 1);
	else
	{
		i = x - 1;
		while (i-- > 0)
			nbr = nbr + write(1, "0", 1);
		nbr = nbr + write(1, "%", 1);
	}
	return (nbr);
}

/*
** print conversion '%' with 0 after '%'
** ex : %032%
** ex : %0*%
*/

int	print_por_with_flag_zero(const char *args, int x, int i)
{
	int nbr;
	int bx;

	nbr = 0;
	bx = ft_atoi(args + i + 1);
	if (bx != 0)
	{
		while (args[i] <= '9' && args[i] >= '0')
			i++;
		nbr = nbr + print_por_with_flag_zero_and_nbr(x);
	}
	else
		nbr = nbr + write(1, "%", 1);
	return (nbr);
}

int	print_conversion_por(va_list va_lst, int i, const char *args)
{
	int nbr;
	int x;

	nbr = 0;
	x = ft_atoi(args + i);
	if (x != 0 && args[i] != '0')
		nbr = nbr + print_por_flg_nbr_not_psg(x);
	else if (args[i] == '*')
		nbr = nbr + print_conversion_por_with_flag_itwl(va_lst);
	else if (args[i] == '0')
		nbr = nbr + print_por_with_flag_zero(args, x, i);
	else if (args[i] == '%')
		nbr = nbr + write(1, "%", 1);
	else
	{
		nbr = nbr + write(1, "%", 1);
	}
	return (nbr);
}
