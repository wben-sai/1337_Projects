/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:22 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 19:54:57 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_right_nbr_in_a(int nbr)
{
	int	pos;

	pos = get_position_nbr(t_param.stacka, nbr);
	if (pos == 0)
		pos = 0;
	else if (pos > (len_stack(t_param.stacka) / 2))
		pos = len_stack(t_param.stacka) - pos;
	else
		pos *= -1;
	if (pos < 0)
	{
		while (pos++ < 0)
			ra(&t_param.stacka, 1);
	}
	else if (pos > 0)
	{
		while (pos-- > 0)
			rra(&t_param.stacka, 1);
	}
	pb(&t_param.stacka, &t_param.stackb);
}

void	get_right_nbr(int nbr)
{
	int	pos;

	pos = get_position_nbr(t_param.stackb, nbr);
	if (pos == 0)
		pos = 0;
	else if (pos > (len_stack(t_param.stackb) / 2))
		pos = len_stack(t_param.stackb) - pos;
	else
		pos *= -1;
	if (pos < 0)
	{
		while (pos++ < 0)
			rb(&t_param.stackb, 1);
	}
	else if (pos > 0)
	{
		while (pos-- > 0)
			rrb(&t_param.stackb, 1);
	}
	pa(&t_param.stacka, &t_param.stackb);
}

void	get_close_nbr(int nbr, t_stacks **lst)
{
	nbr = pos_nbr_in_lst(*lst, val_pos(*lst, t_param.i));
	if (nbr < (len_stack(*lst) / 2))
		nbr *= -1;
	else
		nbr = len_stack(*lst) - nbr;
	if ((nbr <= 0 && t_param.res >= 0 && t_param.res > (nbr * -1))
		|| (nbr <= 0 && t_param.res < 0 && (t_param.res * (-1)) > (nbr * -1)))
		t_param.res = nbr;
	else if ((nbr >= 0 && t_param.res >= 0 && t_param.res > nbr)
		|| (nbr >= 0 && t_param.res < 0 && (t_param.res * -1) > nbr))
		t_param.res = nbr;
	t_param.i++;
}

int	get_position_nbr(t_stacks *lst, int nbr)
{
	t_stacks	*temp1;
	int			i;

	temp1 = lst;
	i = 0;
	while (temp1 != NULL)
	{
		if (temp1->stack == nbr)
			return (i);
		temp1 = temp1->next;
		i++;
	}
	return (-1);
}

void	freestack(void)
{
	t_stacks	*lst;

	lst = t_param.stacka;
	while (lst)
	{
		free (lst);
		lst = lst->next;
	}
}
