/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:21:37 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 18:21:37 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*lstnew(int stack, int pos, char c)
{
	t_stacks	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	nouveau->stack = stack;
	nouveau->pos = pos;
	nouveau->c = c;
	nouveau->next = NULL;
	return (nouveau);
}

void	lstadd_back(t_stacks **list_shell, t_stacks *new)
{
	t_stacks	*ptr_list_shell;

	ptr_list_shell = *list_shell;
	if (*list_shell == NULL)
	{
		*list_shell = new;
		new->next = NULL;
	}
	else
	{
		while (ptr_list_shell->next)
			ptr_list_shell = ptr_list_shell->next;
		ptr_list_shell->next = new;
		new->next = NULL;
	}
}

int	len_stack(t_stacks *lst)
{
	t_stacks	*temp1;
	int			i;

	temp1 = lst;
	i = 0;
	while (temp1 != NULL)
	{
		i++;
		temp1 = temp1->next;
	}
	return (i);
}

int	val_pos(t_stacks *lst, int pos)
{
	while (lst != NULL)
	{
		if (lst->pos == pos)
			return (lst->stack);
		lst = lst->next;
	}
	return (-1);
}

int	is_in(t_stacks *lst, int pos)
{
	while (lst != NULL)
	{
		if (lst->pos == pos)
			return (1);
		lst = lst->next;
	}
	return (-1);
}
