/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:20:38 by wben-sai          #+#    #+#             */
/*   Updated: 2021/07/10 14:07:43 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philo *lst)
{
	if (lst->ptr->nbr_otepme != -1 && lst->nbr_eat == lst->ptr->nbr_otepme)
	{
		lst->ptr->stop = 1;
		return (-1);
	}
	lst->start_time = get_time_ms();
	print_msg(lst, 0);
	lst->nbr_eat += 1;
	lst->is_eating = -1;
	myusleep(lst->ptr->time_to_eat);
	lst->is_eating = 1;
	return (0);
}

void	sleeping(t_philo *lst)
{
	print_msg(lst, 1);
	myusleep(lst->ptr->time_to_sleep);
}

void	thinking(t_philo *lst)
{
	print_msg(lst, 2);
}
