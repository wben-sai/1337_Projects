/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:49:55 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/22 15:04:40 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks **lst, int x)
{
	int			temp;
	int			temp2;
	t_stacks	*ptr_lst;

	ptr_lst = *lst;
	temp = ptr_lst->stack;
	temp2 = ptr_lst->pos;
	while (ptr_lst->next != NULL)
	{
		ptr_lst->stack = ptr_lst->next->stack;
		ptr_lst->pos = ptr_lst->next->pos;
		ptr_lst->c = ptr_lst->next->c;
		ptr_lst = ptr_lst->next;
	}
	ptr_lst->stack = temp;
	ptr_lst->pos = temp2;
	if (x == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stacks **lst, int x)
{
	int			temp;
	int			temp2;
	t_stacks	*ptr_lst;

	ptr_lst = *lst;
	temp = ptr_lst->stack;
	temp2 = ptr_lst->pos;
	while (ptr_lst->next != NULL)
	{
		ptr_lst->stack = ptr_lst->next->stack;
		ptr_lst->pos = ptr_lst->next->pos;
		ptr_lst->c = ptr_lst->next->c;
		ptr_lst = ptr_lst->next;
	}
	ptr_lst->stack = temp;
	ptr_lst->pos = temp2;
	if (x == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stacks **lsta, t_stacks **lstb)
{
	ra(lsta, -1);
	rb(lstb, -1);
	write(1, "rr\n", 3);
}
