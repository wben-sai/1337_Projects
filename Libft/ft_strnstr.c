/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:39:03 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 21:41:59 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;
	size_t	y;

	i = 0;
	y = 0;
	len_needle = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len > i && haystack[i] != '\0')
	{
		if (haystack[i] == needle[y] && haystack[i] != '\0')
			y++;
		else
		{
			i = i - y;
			y = 0;
		}
		if (len_needle == y)
			return ((char *)haystack + i - y + 1);
		i++;
	}
	return (NULL);
}
