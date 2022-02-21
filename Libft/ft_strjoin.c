/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:03:49 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 14:19:14 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	ptr = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (len_s1 > 0 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	len_s1 = 0;
	while (len_s2 > 0 && s2[len_s1] != '\0')
		ptr[i++] = s2[len_s1++];
	ptr[i] = '\0';
	return (ptr);
}
