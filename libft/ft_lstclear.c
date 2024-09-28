/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:37:05 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 13:51:47 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (lst && del)
	{
		elem = *lst;
		while (elem)
		{
			next = elem->next;
			ft_lstdelone(elem, del);
			elem = next;
		}
		*lst = NULL;
	}
}
