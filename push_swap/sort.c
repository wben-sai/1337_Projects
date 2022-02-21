/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:08:52 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 18:38:10 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_n_nbr(int n, t_stacks **stack)
{
	t_stacks	*lst;

	lst = *stack;
	if (n == 2 && lst->stack > lst->next->stack)
		ra(stack, 1);
	else if (n == 3)
		sort_3_nbr(stack);
	else if (n == 4)
	{
		get_right_nbr_in_a(val_pos(lst, 0));
		sort_3_nbr(stack);
		pa(&t_param.stacka, &t_param.stackb);
	}
	else if (n == 5)
	{
		get_right_nbr_in_a(val_pos(lst, 0));
		lst = *stack;
		get_right_nbr_in_a(val_pos(lst, 1));
		sort_3_nbr(stack);
		pa(&t_param.stacka, &t_param.stackb);
		pa(&t_param.stacka, &t_param.stackb);
	}
}

int	check_sort(t_stacks *lst)
{
	t_stacks	*temp1;
	int			i;

	temp1 = lst;
	i = 0;
	while (temp1->next != NULL)
	{
		if (temp1->stack > temp1->next->stack)
			return (-1);
		i++;
		temp1 = temp1->next;
	}
	return (1);
}

void	sort_stack(t_stacks **stacka)
{
	t_stacks	*lst;
	t_stacks	*lst2;
	int			temp;

	lst = *stacka;
	while (lst)
	{
		lst2 = *stacka;
		temp = 0;
		while (lst2)
		{
			if (lst->stack > lst2->stack)
				temp++;
			lst2 = lst2->next;
		}
		lst->pos = temp;
		lst = lst->next;
	}
}

void	sort_3_nbr(t_stacks **stack)
{
	t_stacks	*lst;

	lst = *stack;
	if (check_sort(*stack) == 1)
		return ;
	if (nbr_pos(lst, 0) > nbr_pos(lst, 1)
		&& nbr_pos(lst, 1) < nbr_pos(lst, 2)
		&& nbr_pos(lst, 0) < nbr_pos(lst, 2))
		sa(stack, 1);
	else if (nbr_pos(lst, 0) > nbr_pos(lst, 1)
		&& nbr_pos(lst, 1) < nbr_pos(lst, 2)
		&& nbr_pos(lst, 0) > nbr_pos(lst, 2))
		ra(stack, 1);
	else if (nbr_pos(lst, 0) < nbr_pos(lst, 1)
		&& nbr_pos(lst, 1) > nbr_pos(lst, 2)
		&& nbr_pos(lst, 0) > nbr_pos(lst, 2))
		rra(stack, 1);
	else
	{
		sa(stack, 1);
		if (nbr_pos(lst, 0) < nbr_pos(lst, 1))
			rra(stack, 1);
		else
			ra(stack, 1);
	}
}
