/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:48:07 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 16:48:07 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(char **av)
{
	int	i;

	i = 1;
	t_param.min = ft_atoi(av[1]);
	while (av[i])
	{
		lstadd_back(&t_param.stacka, lstnew(ft_atoi(av[i]), i - 1, 'a'));
		if (t_param.min > ft_atoi(av[i]))
			t_param.min = ft_atoi(av[i]);
		i++;
	}
	sort_stack(&t_param.stacka);
}

void	check_rules(int len)
{
	len = len_stack(t_param.stackb) + t_param.i;
	if (is_in(t_param.stackb, len - 1) != -1)
	{
		if (t_param.stackb->pos == len - 1)
			pa(&t_param.stacka, &t_param.stackb);
		else if (t_param.stackb->stack < t_param.stacka->stack
			&& t_param.stackb->stack > t_param.min)
		{
			pa(&t_param.stacka, &t_param.stackb);
			t_param.min = t_param.stacka->stack;
			ra(&t_param.stacka, 1);
			t_param.i++;
		}
		else
			get_right_nbr(val_pos(t_param.stackb, len - 1));
	}
	else
	{
		t_param.min = t_param.stacka->stack;
		rra(&t_param.stacka, 1);
		t_param.i--;
		if (t_param.i == 0)
			t_param.min = t_param.back;
	}
}

void	re_push(void)
{
	int	len;

	len = len_stack(t_param.stackb);
	t_param.i = 0;
	while (len_stack(t_param.stackb) != 0)
		check_rules(len);
	while (check_sort(t_param.stacka) != 1)
		rra(&t_param.stacka, 1);
}

void	let_go(int ac)
{
	int	n;

	while (1)
	{
		n = ((ac - 5) / 3) + 1;
		if (ac > 5)
			push_close_n_nbr(n);
		else
		{
			sort_stack(&t_param.stacka);
			sort_n_nbr(len_stack(t_param.stacka), &t_param.stacka);
			t_param.min--;
			t_param.back = t_param.min;
			sort_stack(&t_param.stackb);
			re_push();
			break ;
		}
		ac = ac - n;
	}
}

int	main(int ac, char **av)
{
	if (check_argv(av) == -1)
		write(1, "Error\n", 6);
	else if (ac > 1)
	{
		fill_stack(av);
		if (check_sort(t_param.stacka) == 1)
			return (0);
		if (ac > 6)
			let_go(ac - 1);
		else
			sort_n_nbr(ac - 1, &t_param.stacka);
		freestack();
	}
	return (0);
}
