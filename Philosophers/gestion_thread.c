/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:21:37 by wben-sai          #+#    #+#             */
/*   Updated: 2021/07/10 14:11:56 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_init(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->len)
	{
		pthread_mutex_init(&(param->fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(param->print), NULL);
}

void	mutex_destroy(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->len)
	{
		pthread_mutex_destroy(&(param->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(param->print));
}

int	join_thread(t_param *param, t_philo **philo)
{
	int	i;

	while (param->stop == 0)
	{
		i = 0;
		while (i < param->len)
		{
			if (get_time_ms() - philo[i]->start_time
				> philo[i]->ptr->time_to_die
				&& philo[i]->is_eating != -1)
			{
				print_msg(philo[i], 3);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

int	create_thread(t_param *param, t_philo **philo)
{
	int	i;

	i = 0;
	param->stop = 0;
	while (i < param->len)
	{
		pthread_create(&(param->th[i]), NULL, &routine, philo[i]);
		i += 2;
	}
	usleep (1000);
	i = 1;
	while (i < param->len)
	{
		pthread_create(&(param->th[i]), NULL, &routine, philo[i]);
		i += 2;
	}
	usleep(1000);
	return (join_thread(param, philo));
}

void	*routine(void *arg)
{
	t_philo	*lst;

	lst = (t_philo *)arg;
	lst->start_time = get_time_ms();
	lst->time = get_time_ms();
	while (1)
	{
		pthread_mutex_lock(&(lst->ptr->fork[lst->id]));
		print_msg(lst, 4);
		pthread_mutex_lock(&(lst->ptr->fork[((lst->id + 1)
					% (lst->ptr->len))]));
		print_msg(lst, 4);
		if (eating(lst) == -1)
			break ;
		pthread_mutex_unlock(&(lst->ptr->fork[lst->id]));
		pthread_mutex_unlock(&(lst->ptr->fork[((lst->id + 1)
					% (lst->ptr->len))]));
		sleeping(lst);
		thinking(lst);
	}
	return (NULL);
}
