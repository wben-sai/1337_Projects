/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:45:42 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 12:33:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr_b;

	ptr_b = b;
	while (len > 0)
	{
		*(char *)ptr_b++ = c;
		len--;
	}
	return (b);
}
