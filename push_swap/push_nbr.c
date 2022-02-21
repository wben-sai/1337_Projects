/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:16:33 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 19:55:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_close_nbr(int n, t_stacks **lst)
{
	int	nbr;

	t_param.i = 0;
	nbr = pos_nbr_in_lst(*lst, val_pos(*lst, t_param.i++));
	if (nbr == 0)
		return (nbr);
	if (nbr < (len_stack(*lst) / 2))
		nbr *= -1;
	else
		nbr = len_stack(*lst) - nbr;
	t_param.res = nbr;
	while (--n > 0)
		get_close_nbr(nbr, lst);
	return (t_param.res);
}

void	push_close_n_nbr(int n)
{
	t_param.middle = val_pos(t_param.stacka, n / 2);
	while (n > 0)
	{
		t_param.res = push_close_nbr(n--, &t_param.stacka);
		if (t_param.res < 0)
		{
			while (t_param.res++ < 0)
				ra(&t_param.stacka, 1);
		}
		else if (t_param.res > 0)
		{
			while (t_param.res-- > 0)
				rra(&t_param.stacka, 1);
			t_param.res--;
		}
		if (len_stack(t_param.stackb) == 0)
			pb(&t_param.stacka, &t_param.stackb);
		else
		{
			pb(&t_param.stacka, &t_param.stackb);
			if (t_param.stackb->stack < t_param.middle)
				rb(&t_param.stackb, 1);
		}
		sort_stack(&t_param.stacka);
	}
}

int	getsign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
