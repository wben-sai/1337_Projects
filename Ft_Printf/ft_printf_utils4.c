/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:26:37 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 14:47:00 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	to_hexadecimal(int k)
{
	if (k == 10)
		return ('a');
	if (k == 11)
		return ('b');
	if (k == 12)
		return ('c');
	if (k == 13)
		return ('d');
	if (k == 14)
		return ('e');
	if (k == 15)
		return ('f');
	return (k + '0');
}

char	*filling_ptr_x(char *p, int x, unsigned int n)
{
	int k;

	p[x] = '\0';
	x--;
	while (x > -1)
	{
		k = n % 16;
		p[x] = to_hexadecimal(k);
		n = (n - (n % 16)) / 16;
		x--;
	}
	return (p);
}

int		len_nbr_x(int unsigned n)
{
	int x;

	x = 0;
	while (n != 0)
	{
		if ((n / 16) != 0)
			x++;
		n = n / 16;
	}
	return (x + 1);
}

int		ft_itoa_x(int unsigned n)
{
	int			x;
	int			y;
	char		*p;
	const char	*temp;

	x = 0;
	y = 1;
	x = x + len_nbr_x(n);
	p = malloc((sizeof(char) * x) + 1);
	if (p == NULL)
		return (0);
	if (y == -1)
		p[0] = '-';
	temp = filling_ptr_x(p, x, n);
	x = ft_putstr(temp);
	free(p);
	return (x);
}

/*
** print conversion 'x' with flag 0 after '%'
** ex : %0*x
** ex : %0*.*x
** ex : %0*.73x
** ex : %0.*x
*/

int		x_with_flag_zero_itwl(const char *args, va_list va_lst, int i)
{
	int bx;
	int nbr;
	int box;

	nbr = 0;
	bx = va_arg(va_lst, int);
	if (args[i + 2] != '.')
		nbr += x_with_flag_zero_and_nbr(bx, va_arg(va_lst, unsigned int));
	else
	{
		if (args[i + 3] == '*')
		{
			box = va_arg(va_lst, int);
			nbr += f0_itl_x(bx, box, va_arg(va_lst, unsigned int));
		}
		else
		{
			box = ft_atoi(args + i + 3);
			nbr += f0_itl_x(bx, box, va_arg(va_lst, unsigned int));
		}
	}
	return (nbr);
}
