/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:31:02 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/13 11:37:37 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conversion_c(va_list va_lst, int i, const char *args)
{
	int		nbr;
	int		x;
	char	c;

	nbr = 0;
	x = ft_atoi(args + i);
	if (x != 0)
		nbr = nbr + print_c_with_flag_nbr(x, va_arg(va_lst, int));
	else if (args[i] == '*')
		nbr += print_c_with_flag_nbr(va_arg(va_lst, int), va_arg(va_lst, int));
	else if (args[i] == '-' && args[i + 1] == '*')
	{
		x = va_arg(va_lst, int);
		if (x > 0)
			x = x * -1;
		nbr = nbr + print_c_with_flag_nbr(x, va_arg(va_lst, int));
	}
	else
	{
		c = va_arg(va_lst, int);
		write(1, &c, 1);
		nbr++;
	}
	return (nbr);
}

/*
** print_c_with_flag_nbr(int x, char c);
** [x : nbr space][ex : %20c || %-25c]
*/

int	print_c_with_flag_nbr(int x, char c)
{
	int nbr;

	nbr = 0;
	if (x < 0)
	{
		x = x * -1;
		nbr = nbr + write(1, &c, 1);
		while (x > 1)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
	}
	else if (x >= 0)
	{
		while (x > 1)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
		nbr = nbr + write(1, &c, 1);
	}
	return (nbr);
}
