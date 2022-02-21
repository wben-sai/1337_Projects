/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:02:05 by wben-sai          #+#    #+#             */
/*   Updated: 2021/07/10 14:19:16 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number(char *s)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			res++;
		i++;
	}
	if (res > 1 || strlen(s) > 12 || s[0] == '-')
		return (-1);
	else if (res == 1 && s[0] != '-' && s[0] != '+')
		return (-1);
	i = 0;
	if (res == 1)
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	getsign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ')
		i++;
	sign = getsign(str, &i);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		return (0);
	return (result * sign);
}

long	get_time_ms(void)
{
	struct timeval	current_time;
	long			res;

	gettimeofday(&current_time, NULL);
	res = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (res);
}

void	myusleep(long time)
{
	long	cur_time;

	cur_time = get_time_ms();
	usleep((time * 1000) - 20000);
	while (get_time_ms() - cur_time < time)
		continue ;
}
