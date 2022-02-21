/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:41:02 by wben-sai          #+#    #+#             */
/*   Updated: 2019/10/30 17:43:47 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*nouv;
	int		i;

	i = 0;
	if (i > 0)
	{
		nouv = malloc(sizeof(t_list));
		if (nouv == NULL)
		{
			ft_lstclear(&nouv, del);
			return (NULL);
		}
		nouv->content = f(lst->content);
		nouv->next = NULL;
	}
	return (NULL);
}
