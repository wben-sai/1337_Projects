/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:26:37 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 14:23:40 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*filling_ptr_u(char *p, int x, unsigned int n)
{
	int k;

	p[x] = '\0';
	x--;
	while (x > -1)
	{
		k = n % 10;
		p[x] = k + '0';
		n = (n - (n % 10)) / 10;
		x--;
	}
	return (p);
}

int		len_nbr_u(unsigned int n)
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

int		ft_itoa_u(int unsigned n)
{
	int			x;
	char		*p;
	const char	*temp;

	x = 0;
	x = x + len_nbr_u(n);
	p = malloc((sizeof(char) * x) + 1);
	if (p == NULL)
		return (0);
	temp = filling_ptr_u(p, x, n);
	x = ft_putstr(temp);
	free(p);
	return (x);
}

/*
** print conversion 'u' with flag 0 and '*' after '%'
** ex : %0*u
** ex : %0*.*u
** ex : %0*.73u
*/

int		u_with_flag_zero_anditwl(const char *args, va_list va_lst, int i)
{
	int nbr;
	int box;
	int bx;

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
