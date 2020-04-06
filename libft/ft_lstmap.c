/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:05:42 by qdang             #+#    #+#             */
/*   Updated: 2019/09/27 15:35:32 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst)
		return (NULL);
	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);		
	new = f(lst);
	while (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
