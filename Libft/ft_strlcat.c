/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:01:43 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 21:32:15 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	len_dst_cat_src;
	int		i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	len_dst_cat_src = len_dst;
	i = 0;
	if (len_dst >= size)
		return (size + len_src);
	else
	{
		while (len_dst_cat_src < size - 1 && src[i] != '\0')
			dst[len_dst_cat_src++] = src[i++];
	}
	dst[len_dst_cat_src] = '\0';
	return (len_src + len_dst);
}
