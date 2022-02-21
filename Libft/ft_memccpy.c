/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:56:57 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 12:09:02 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr;
	int		i;

	ptr = dst;
	i = 0;
	while (n > 0)
	{
		*(char *)ptr = *(char *)src;
		if (*(char *)src == (char)c)
		{
			break ;
		}
		ptr++;
		src++;
		n--;
		i++;
	}
	if (n == 0)
		return (NULL);
	*(char *)ptr = *(char *)src;
	return (dst + ++i);
}
