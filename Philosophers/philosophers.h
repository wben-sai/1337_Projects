/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:12:30 by wben-sai          #+#    #+#             */
/*   Updated: 2021/07/10 14:29:07 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_param
{
	pthread_t		*th;
	pthread_mutex_t	*fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_otepme;
	int				stop;
	int				len;
	pthread_mutex_t	print;
}	t_param;

typedef struct s_philo
{
	int		id;
	long	start_time;
	long	time;
	int		is_eating;
	int		nbr_eat;
	t_param	*ptr;
}	t_philo;

int		is_number(char *s);
long	get_time_ms(void);
void	myusleep(long time);
void	print_msg(t_philo *lst, int type);
int		eating(t_philo *lst);
void	sleeping(t_philo *lst);
void	thinking(t_philo *lst);
void	*routine(void *arg);
int		check_args(int ac, char **av, t_param *param);
int		check_args(int ac, char **av, t_param *param);
void	fill_struct(t_philo **philo, t_param *param, int len);
void	mutex_init(t_param *param);
void	mutex_destroy(t_param *param);
int		join_thread(t_param *param, t_philo **philo);
int		create_thread(t_param *param, t_philo **philo);
void	free_arg(t_param *param, t_philo **philo);
int		ft_atoi(const char *str);
int		getsign(const char *str, int *i);
#endif