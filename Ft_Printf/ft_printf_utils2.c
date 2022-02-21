/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:19:13 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 15:14:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*filling_ptr(char *p, int x, int n)
{
	int k;

	p[x] = '\0';
	x--;
	if (n >= 0)
	{
		while (x > -1)
		{
			k = n % 10;
			p[x] = k + '0';
			n = (n - (n % 10)) / 10;
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			k = (n % 10) * -1;
			p[x] = k + '0';
			n = (n - (n % 10)) / 10;
			x--;
		}
	}
	return (p);
}

int		len_nbr(int n)
{
	int x;

	x = 0;
	while (n != 0)
	{
		if ((n / 10) != 0)
			x++;
		n = n / 10;
	}
	return (x + 1);
}

int		ft_itoa(int n)
{
	int			x;
	int			y;
	char		*p;
	const char	*temp;

	x = 0;
	y = 1;
	if (n < 0)
	{
		y = -1;
		x++;
	}
	x = x + len_nbr(n);
	p = malloc((sizeof(char) * x) + 1);
	if (p == NULL)
		return (0);
	if (y == -1)
		p[0] = '-';
	temp = filling_ptr(p, x, n);
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

int		x2_with_flag_zero_itwl(const char *args, va_list va_lst, int i)
{
	int bx;
	int nbr;
	int box;

	nbr = 0;
	bx = va_arg(va_lst, int);
	if (args[i + 2] != '.')
		nbr += x2_with_flag_zero_and_nbr(bx, va_arg(va_lst, unsigned int));
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
