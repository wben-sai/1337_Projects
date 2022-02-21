/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:45:58 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/06 17:22:26 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversions(const char *args, int i)
{
	while ((args[i] == '-' || (args[i] >= '0' && args[i] <= '9')
		|| args[i] == '.' || args[i] == '*') && args[i] != '\0')
		i++;
	if (args[i] == 'c')
		return (1);
	if (args[i] == 's')
		return (2);
	if (args[i] == 'p')
		return (3);
	if (args[i] == 'd')
		return (4);
	if (args[i] == 'i')
		return (5);
	if (args[i] == 'u')
		return (6);
	if (args[i] == 'x')
		return (7);
	if (args[i] == 'X')
		return (8);
	if (args[i] == '%')
		return (9);
	if (args[i] == 'n')
		return (10);
	return (-1);
}

int	switch_conversion(int conve, va_list va_lst, int i, const char *args)
{
	int nbr;

	nbr = 0;
	if (conve == 1)
		nbr = nbr + print_conversion_c(va_lst, i, args);
	if (conve == 2)
		nbr = nbr + print_conversion_s(va_lst, i, args);
	if (conve == 3)
		nbr = nbr + print_conversion_p(va_lst, i, args);
	if (conve == 4)
		nbr = nbr + print_conversion_d(va_lst, i, args);
	if (conve == 5)
		nbr = nbr + print_conversion_d(va_lst, i, args);
	if (conve == 6)
		nbr = nbr + print_conversion_u(va_lst, i, args);
	if (conve == 7)
		nbr = nbr + print_conversion_x(va_lst, i, args);
	if (conve == 8)
		nbr = nbr + print_conversion_x2(va_lst, i, args);
	if (conve == 9)
		nbr = nbr + print_conversion_por(va_lst, i, args);
	return (nbr);
}

int	action_conversions(va_list va_lst, int *i, const char *args)
{
	int nbr;
	int	*ptr_box;
	int conve;

	nbr = 0;
	conve = 0;
	conve = check_conversions(args, *i + 1);
	if (conve != -1 && conve != 10)
	{
		nbr = nbr + switch_conversion(conve, va_lst, ++*i, args);
		while (args[*i] == '-' || (args[*i] >= '0' && args[*i] <= '9')
			|| args[*i] == '.' || args[*i] == '*')
			*i = *i + 1;
	}
	if (conve == 10)
	{
		ptr_box = va_arg(va_lst, int*);
		*ptr_box = nbr;
		*i = *i + 1;
	}
	return (nbr);
}

int	ft_printf(const char *args, ...)
{
	int		i;
	int		nbr;
	va_list va_lst;

	i = 0;
	nbr = 0;
	va_start(va_lst, args);
	while (args[i] != '\0')
	{
		if (args[i] == '%')
		{
			nbr = nbr + action_conversions(va_lst, &i, args);
		}
		else
			nbr = nbr + write(1, &args[i], 1);
		i++;
	}
	va_end(va_lst);
	return (nbr);
}
