/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:04:09 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/30 12:15:33 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	i = count * size;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i > 0)
	{
		*(char *)ptr++ = 0;
		i--;
	}
	return (ptr - (count * size));
}
