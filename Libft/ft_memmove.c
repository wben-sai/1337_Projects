/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:43:56 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 12:12:15 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *ptr_dst;

	ptr_dst = dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (len-- > 0)
			*(char *)ptr_dst++ = *(char *)src++;
	}
	else
	{
		ptr_dst += len;
		src += len;
		while (len-- > 0)
			*(char *)--ptr_dst = *(char *)--src;
	}
	return (dst);
}
