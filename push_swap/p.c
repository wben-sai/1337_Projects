/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:36:56 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/22 16:33:51 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stacks **lsta, t_stacks **lstb)
{
	t_stacks	*ptr_lst;
	t_stacks	*first;

	first = *lsta;
	ptr_lst = *lsta;
	*lsta = ptr_lst->next;
	if (*lstb != NULL)
	{
		first->next = *lstb;
		*lstb = first;
	}
	else
	{
		first->next = NULL;
		*lstb = first;
	}
	write(1, "pb\n", 3);
}

void	pa(t_stacks **lsta, t_stacks **lstb)
{
	t_stacks	*ptr_lst;
	t_stacks	*first;

	first = *lstb;
	ptr_lst = *lstb;
	*lstb = ptr_lst->next;
	if (*lsta != NULL)
	{
		first->next = *lsta;
		*lsta = first;
	}
	else
	{
		first->next = NULL;
		*lsta = first;
	}
	write(1, "pa\n", 3);
}
