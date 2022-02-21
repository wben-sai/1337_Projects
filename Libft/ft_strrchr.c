/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:29:15 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 15:08:58 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int y;

	i = 0;
	y = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			y = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (y == -1)
		return (NULL);
	else
		return ((char *)s + y);
}
