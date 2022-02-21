/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:16:06 by wben-sai          #+#    #+#             */
/*   Updated: 2020/11/28 11:57:50 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		len_c(char *s, char c)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			i++;
		x++;
	}
	return (i);
}

void	ft_error(char *s)
{
	write(1, "\033[1;31mError : \n", 16);
	write(1, s, ft_strlen(s));
	exit(0);
}

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	int				i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (n >= 0)
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

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len_s1;
	int		j;
	int		i;

	j = 0;
	len_s1 = ft_strlen(s1);
	i = 0;
	ptr = malloc((len_s1 * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
