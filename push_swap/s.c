/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:19:08 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/22 12:44:56 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks **lst, int x)
{
	t_stacks	*ptr_lst;
	int			temp;

	ptr_lst = *lst;
	temp = ptr_lst->stack;
	ptr_lst->stack = ptr_lst->next->stack;
	ptr_lst->next->stack = temp;
	temp = ptr_lst->pos;
	ptr_lst->pos = ptr_lst->next->pos;
	ptr_lst->next->pos = temp;
	if (x == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stacks **lst, int x)
{
	t_stacks	*ptr_lst;
	int			temp;

	ptr_lst = *lst;
	temp = ptr_lst->stack;
	ptr_lst->stack = ptr_lst->next->stack;
	ptr_lst->next->stack = temp;
	temp = ptr_lst->pos;
	ptr_lst->pos = ptr_lst->next->pos;
	ptr_lst->next->pos = temp;
	if (x == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stacks **lsta, t_stacks **lstb)
{
	sa(lsta, -1);
	sb(lstb, -1);
	write(1, "ss\n", 3);
}
