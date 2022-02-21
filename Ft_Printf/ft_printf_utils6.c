/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:26:37 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/13 12:08:02 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	to_hexadecimal_p(int k)
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

char	*filling_ptr_p(char *p, int x, unsigned long n)
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

int		len_nbr_p(unsigned long n)
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

int		ft_itoa_p(unsigned long n)
{
	int			x;
	char		*p;
	const char	*temp;

	x = 0;
	x = x + len_nbr_p(n);
	p = malloc((sizeof(char) * x) + 1);
	if (p == NULL)
		return (0);
	temp = filling_ptr_p(p, x, n);
	write(1, "0", 1);
	write(1, "x", 1);
	x = ft_putstr(temp);
	free(p);
	return (x + 2);
}

int		print_por_with_flag_nbr(const char *args, int x, int i)
{
	int nbr;

	nbr = 0;
	if (args[i] == '-')
		i++;
	while (args[i] <= '9' && args[i] >= '0')
		i++;
	nbr = nbr + print_por_flg_nbr_not_psg(x);
	return (nbr);
}
