/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/11/21 17:33:51 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}

int		sheck_namexpm(char *s)
{
	int i;

	i = ft_strlen(s);
	if (ft_tolower(s[i - 1]) == 'm'
	&& ft_tolower(s[i - 2]) == 'p'
	&& ft_tolower(s[i - 3]) == 'x')
		return (1);
	else
		return (0);
}

int		quit(t_list **lst)
{
	freepath(lst);
	return (0);
}

int		len_manexpm(char *s)
{
	int x;
	int y;

	x = 0;
	y = ft_strlen(s);
	while (s[x] != ' ')
		x++;
	while (s[x] == ' ')
		x++;
	return (y - x);
}

char	*sheck_namexpm2(char *line)
{
	char	*s;
	int		i;
	int		j;
	int		z;

	i = 0;
	j = len_manexpm(line);
	z = 0;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	s = malloc(sizeof(char *) * j + 1);
	while (j >= 0)
	{
		s[z] = line[i];
		i++;
		z++;
		j--;
	}
	s[z] = '\0';
	return (s);
}
