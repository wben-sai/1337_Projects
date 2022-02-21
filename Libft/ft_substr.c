/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:33:14 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 21:37:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static unsigned int	size_s(char const *s)
{
	int x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x + 1);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > size_s(s))
	{
		ptr = malloc(sizeof(char) * 1);
		len = 0;
	}
	else
		ptr = malloc((sizeof(char) * len) + 1);
	if (ptr == NULL)
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start];
		if (s[start] != '\0')
			start++;
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
