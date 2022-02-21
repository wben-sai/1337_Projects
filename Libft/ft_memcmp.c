/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:26:30 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/30 11:38:56 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if ((s1 == NULL && s2 == NULL) || ((s1 == NULL || s2 == NULL) && n == 0))
		return (0);
	if (ptr_s1[i] == '\0' && ptr_s2[i] == '\0')
		return (0);
	while (n > 0)
	{
		if (ptr_s1[i] == ptr_s2[i])
			i++;
		else
			return (ptr_s1[i] - ptr_s2[i]);
		n--;
	}
	return (0);
}
