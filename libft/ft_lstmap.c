/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:59:34 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/15 14:28:17 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(lst->content);
		if (!new_elem)
			return (ft_lstclear(&new_list, del), NULL);
		new_elem->content = (*f)(new_elem->content);
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
