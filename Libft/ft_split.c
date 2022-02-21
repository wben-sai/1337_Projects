/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:57:20 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/29 21:41:12 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*filling_ptr(char *p, char const *s, int end_w, int start_w)
{
	int x;
	int n;

	x = 0;
	n = end_w - start_w;
	while (start_w > 0)
	{
		p[x] = s[n];
		n++;
		x++;
		start_w--;
	}
	p[x] = '\0';
	return (p);
}

static char	*create_ptr(char const *s, int c, int i_word)
{
	int		start_w;
	char	*p;
	int		end_w;

	start_w = 0;
	end_w = 0;
	while (i_word-- > 0)
	{
		while (s[end_w] == c && s[end_w] != '\0')
			end_w++;
		while (s[end_w] != c && s[end_w] != '\0')
			end_w++;
	}
	while (s[end_w] == c && s[end_w] != '\0')
		end_w++;
	while (s[end_w] != c && s[end_w] != '\0')
	{
		start_w++;
		end_w++;
	}
	p = malloc((sizeof(char) * start_w) + 1);
	if (p == NULL)
		return (NULL);
	return (filling_ptr(p, s, end_w, start_w));
}

static char	**create_t_ptr(char const *s, int c, int nbr_word)
{
	char	**t_ptr;
	int		i_word;

	i_word = 0;
	t_ptr = malloc((sizeof(char *) * nbr_word) + 1);
	if (t_ptr == NULL)
		return (NULL);
	while (nbr_word > 0)
	{
		if (create_ptr(s, c, i_word) != NULL)
			t_ptr[i_word] = create_ptr(s, c, i_word);
		else
		{
			while (i_word >= 0)
			{
				free(t_ptr[i_word--]);
			}
			free(t_ptr);
			return (NULL);
		}
		i_word++;
		nbr_word--;
	}
	t_ptr[i_word] = 0;
	return (t_ptr);
}

static char	**con_nbr_word(char const *s, int c)
{
	size_t	len_s;
	size_t	i;
	int		nbr_word;

	len_s = ft_strlen(s);
	i = 0;
	nbr_word = 1;
	while (s[i] == c)
		i++;
	while (len_s - 1 > i)
	{
		if (s[i] == c)
		{
			i++;
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] != '\0')
				nbr_word++;
			i--;
		}
		i++;
	}
	return (create_t_ptr(s, c, nbr_word));
}

char		**ft_split(char const *s, char c)
{
	size_t		i;
	char		**t_ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	if (i == ft_strlen(s))
	{
		t_ptr = malloc((sizeof(char *) * 1));
		t_ptr[0] = 0;
		return (t_ptr);
	}
	return (con_nbr_word(s, c));
}
