/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:26:37 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 16:29:14 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	to_hexadecimal2(int k)
{
	if (k == 10)
		return ('A');
	if (k == 11)
		return ('B');
	if (k == 12)
		return ('C');
	if (k == 13)
		return ('D');
	if (k == 14)
		return ('E');
	if (k == 15)
		return ('F');
	return (k + '0');
}

char	*filling_ptr_x2(char *p, int x, unsigned int n)
{
	int k;

	p[x] = '\0';
	x--;
	while (x > -1)
	{
		k = n % 16;
		p[x] = to_hexadecimal2(k);
		n = (n - (n % 16)) / 16;
		x--;
	}
	return (p);
}

int		len_nbr_x2(int unsigned n)
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

int		ft_itoa_x2(int unsigned n)
{
	int			x;
	int			y;
	char		*p;
	const char	*temp;

	x = 0;
	y = 1;
	x = x + len_nbr_x2(n);
	p = malloc((sizeof(char) * x) + 1);
	if (p == NULL)
		return (0);
	if (y == -1)
		p[0] = '-';
	temp = filling_ptr_x2(p, x, n);
	x = ft_putstr(temp);
	free(p);
	return (x);
}

/*
** print conversion 'p' with nbr after '%'
** ex : %-*p
*/

int		print_p_with_flag_minus_itwl(va_list va_lst, int i, const char *args)
{
	int nbr;
	int box;

	nbr = 0;
	box = va_arg(va_lst, int);
	if (args[i] == '.')
	{
		if (box > 0)
		{
			nbr = nbr + write_n_cs(' ', box - 2);
			nbr = nbr + write(1, "0x", 2);
		}
		else
		{
			nbr = nbr + write(1, "0x", 2);
			nbr = nbr + write_n_cs(' ', (box * -1) - 2);
		}
	}
	else
	{
		if (box > 0)
			box = box * -1;
		nbr = nbr + print_p_flg_nbr_not_psg(box, va_arg(va_lst, unsigned long));
	}
	return (nbr);
}
