/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/11/27 20:31:58 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen_without_sp(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

int		len_split(char **s)
{
	int i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

char	*ft_strdup_bylen(char *s1, int len)
{
	char	*ptr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	ptr = malloc((len * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		j++;
		i++;
		len--;
	}
	while (len > 0)
	{
		ptr[j] = ' ';
		len--;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int		test_max_min(long y, int z)
{
	if (y > 2147483648 && z == -1)
		return (0);
	if (y > 2147483647 && z == 1)
		return (-1);
	return (y * z);
}

int		is_number(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
