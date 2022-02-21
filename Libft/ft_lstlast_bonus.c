/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:56:16 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/26 12:51:45 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list *l_fin;

	if (lst == NULL)
		return (NULL);
	l_fin = lst;
	while (l_fin->next)
	{
		l_fin = l_fin->next;
	}
	return (l_fin);
}
