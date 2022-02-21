/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:24:39 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 21:39:18 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	size_t	i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	ptr = malloc((sizeof(char) * len_s) + 1);
	if (ptr == NULL)
		return (NULL);
	while (len_s > i)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
