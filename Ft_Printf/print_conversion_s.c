/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:51:31 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/09 16:09:20 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print conversion 's' with flag nbr after '%'
** ex : %23s
** ex : %-83s
*/

int	print_s_flg_nbr_not_psg(int x, char *s)
{
	int nbr;

	nbr = 0;
	if (s == NULL)
		s = "(null)";
	if (x < 0)
	{
		x = (x * -1) - ft_strlen(s);
		nbr = nbr + ft_putstr(s);
		while (x-- > 0)
			nbr = nbr + write(1, " ", 1);
		return (nbr);
	}
	else if (x >= 0)
	{
		x = x - ft_strlen(s);
		while (x > 0)
		{
			nbr = nbr + write(1, " ", 1);
			x--;
		}
		nbr = nbr + ft_putstr(s);
		return (nbr);
	}
	return (nbr);
}

/*
** print conversion 's' with flag nbr after '%'
** ex : %23.32s
** ex : %-83.*s
*/

int	s_f_nb_psg(int x, int itwl, char *s)
{
	int i;
	int nbr;

	nbr = 0;
	i = 0;
	if (s == NULL)
		s = "(null)";
	if (x < 0)
		nbr = nbr + s_f_nb_psg_neg(x, itwl, s);
	else if (x >= 0)
	{
		x = (ft_strlen(s) > itwl && itwl >= 0) ? x - itwl : x - ft_strlen(s);
		while (x-- > 0)
			nbr = nbr + write(1, " ", 1);
		while ((itwl > i && s[i] != '\0') || (itwl < 0 && s[i] != '\0'))
			nbr = nbr + write(1, &s[i++], 1);
		return (nbr);
	}
	return (nbr);
}

/*
** print conversion 's' with flag nbr neg after '%'
** ex : %-83.*s
*/

int	s_f_nb_psg_neg(int x, int itwl, char *s)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	if (itwl < 0)
		x = (x * -1) - ft_strlen(s);
	else
	{
		if (ft_strlen(s) > itwl)
			x = (x * -1) - itwl;
		else
			x = (x * -1) - ft_strlen(s);
	}
	while ((itwl > i && s[i] != '\0') || (itwl < 0 && s[i] != '\0'))
		nbr = nbr + write(1, &s[i++], 1);
	while (x-- > 0)
		nbr = nbr + write(1, " ", 1);
	return (nbr);
}

/*
** print conversion 's' with flag nbr after '%'
** ex : %23s
** ex : %32.23s
** ex : %23.*s
*/

int	print_s_with_flag_nbr(const char *args, va_list va_lst, int x, int i)
{
	int nbr;

	nbr = 0;
	if (args[i] == '-')
		i++;
	while (args[i] <= '9' && args[i] >= '0')
		i++;
	if (args[i] != '.')
		nbr = nbr + print_s_flg_nbr_not_psg(x, va_arg(va_lst, char*));
	else
	{
		if (args[i + 1] == '*')
			nbr += s_f_nb_psg(x, va_arg(va_lst, int), va_arg(va_lst, char*));
		else
			nbr += s_f_nb_psg(x, ft_atoi(args + i + 1), va_arg(va_lst, char*));
	}
	return (nbr);
}

/*
** print conversion 's' with flag nbr after '%'
** ex : %*s
** ex : %*.23s
** ex : %*.*s
*/

int	print_conversion_s_with_flag_itwl(const char *args, va_list va_lst, int i)
{
	int nbr;
	int bx;

	nbr = 0;
	if (args[i + 1] != '.')
	{
		bx = va_arg(va_lst, int);
		nbr = nbr + print_s_flg_nbr_not_psg(bx, va_arg(va_lst, char*));
	}
	else
	{
		bx = va_arg(va_lst, int);
		if (args[i + 2] == '*')
			nbr += s_f_nb_psg(bx, va_arg(va_lst, int), va_arg(va_lst, char*));
		else if (args[i + 2] == 's')
			nbr += s_f_ps(bx);
		else
			nbr += s_f_nb_psg(bx, ft_atoi(args + i + 2), va_arg(va_lst, char*));
	}
	return (nbr);
}
