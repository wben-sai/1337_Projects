/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:35:07 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 16:35:07 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			res++;
		i++;
	}
	if (res > 1 || ft_strlen(s) > 12)
		return (-1);
	else if (res == 1 && s[0] != '-' && s[0] != '+')
		return (-1);
	i = 0;
	if (res == 1)
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	nbr_pos(t_stacks *lst, int pos)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (i == pos)
			break ;
		i++;
		lst = lst->next;
	}
	return (lst->stack);
}

int	pos_nbr_in_lst(t_stacks *lst, int nbr)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (nbr == lst->stack)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}

int	check_argv(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (av[i])
	{
		if (is_number(av[i]) != 1)
			return (-1);
		while (av[j])
		{
			if (j != i && strcmp(av[j], av[i]) == 0)
				return (-1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = getsign(str, &i);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		exit(write(1, "Error\n", 6));
	return (result * sign);
}
