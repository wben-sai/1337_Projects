/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:12:32 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/22 16:32:37 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks **lst, int x)
{
	t_stacks	*ptr_lst;
	t_stacks	*first;

	ptr_lst = *lst;
	while (ptr_lst->next->next != NULL)
		ptr_lst = ptr_lst->next;
	first = ptr_lst->next;
	first->next = *lst;
	ptr_lst->next = NULL;
	*lst = first;
	if (x == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks **lst, int x)
{
	t_stacks	*ptr_lst;
	t_stacks	*first;

	ptr_lst = *lst;
	while (ptr_lst->next->next != NULL)
		ptr_lst = ptr_lst->next;
	first = ptr_lst->next;
	first->next = *lst;
	ptr_lst->next = NULL;
	*lst = first;
	if (x == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks **lsta, t_stacks **lstb)
{
	rra(lsta, -1);
	rrb(lstb, -1);
	write(1, "rrr\n", 4);
}
