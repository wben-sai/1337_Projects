/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:39:02 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 12:11:49 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *ptr_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_dst = dst;
	while (n > 0)
	{
		if (*(char *)ptr_dst != *(char *)src)
			*(char *)ptr_dst++ = *(char *)src++;
		else
		{
			ptr_dst++;
			src++;
		}
		n--;
	}
	return (dst);
}
