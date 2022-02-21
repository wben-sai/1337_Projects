/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:55 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 14:38:20 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	y;
	int		len_src;

	i = 0;
	y = 1;
	len_src = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (len_src);
	while (y < size && len_src > i)
	{
		dst[i] = src[i];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (len_src);
}
