/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:10:20 by wben-sai          #+#    #+#             */
/*   Updated: 2021/07/10 18:00:14 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(t_philo *lst, int type)
{
	pthread_mutex_lock(&(lst->ptr->print));
	if (type == 0)
		printf("%ld %d is eating\n", get_time_ms() - lst->time, lst->id + 1);
	else if (type == 1)
		printf("%ld %d is sleeping\n", get_time_ms() - lst->time, lst->id + 1);
	else if (type == 2)
		printf("%ld %d is thinking\n", get_time_ms() - lst->time, lst->id + 1);
	else if (type == 3)
		printf("%ld %d died\n", get_time_ms() - lst->time, lst->id + 1);
	else if (type == 4)
		printf("%ld %d has taken a fork\n", get_time_ms()
			- lst->time, lst->id + 1);
	if (type != 3)
		pthread_mutex_unlock(&(lst->ptr->print));
}

int	check_args(int ac, char **av, t_param *param)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (is_number(av[i]) == -1)
			return (-1);
		if (i == 1 && (ac == 5 || ac == 4))
		{
			param->th = malloc(sizeof(pthread_t) * ft_atoi(av[i]));
			param->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[i]));
			param->len = ft_atoi(av[i]);
		}
		else if (i == 2 && (ac == 5 || ac == 4))
			param->time_to_die = ft_atoi(av[i]);
		else if (i == 3 && (ac == 5 || ac == 4))
			param->time_to_eat = ft_atoi(av[i]);
		else if (i == 4 && (ac == 5 || ac == 4))
			param->time_to_sleep = ft_atoi(av[i]);
		else if (i == 5 && (ac == 5 || ac == 4))
			param->nbr_otepme = ft_atoi(av[i]);
		else
			return (-1);
	}
	return (0);
}

void	fill_struct(t_philo **philo, t_param *param, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = i;
		philo[i]->start_time = 0;
		philo[i]->nbr_eat = 0;
		philo[i]->ptr = param;
		i++;
	}
	philo[i] = NULL;
}

void	free_arg(t_param *param, t_philo **philo)
{
	int	i;

	free(param->th);
	free(param);
	i = -1;
	while (philo[++i])
		free(philo[i]);
	free(philo);
}

int	main(int ac, char **av)
{
	t_param	*param;
	t_philo	**philo;

	if (ac != 5 && ac != 6)
		return (0);
	param = malloc(sizeof(t_param));
	param->nbr_otepme = -1;
	if (check_args(ac - 1, av, param) == -1)
		return (0);
	philo = malloc(sizeof(t_philo *) * ft_atoi(av[1]) + 1);
	fill_struct(philo, param, ft_atoi(av[1]));
	mutex_init(param);
	create_thread(param, philo);
	mutex_destroy(param);
	free_arg(param, philo);
	return (0);
}
