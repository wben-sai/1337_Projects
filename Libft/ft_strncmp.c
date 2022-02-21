/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:15:40 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 14:46:58 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (ptr_s1[i] == '\0' && ptr_s2[i] == '\0')
			return (0);
		if (ptr_s1[i] == '\0')
			return (-1);
		if (ptr_s2[i] == '\0')
			return (1);
		if (ptr_s1[i] > ptr_s2[i])
			return (1);
		if (ptr_s1[i] < ptr_s2[i])
			return (-1);
		i++;
		n--;
	}
	return (0);
}
