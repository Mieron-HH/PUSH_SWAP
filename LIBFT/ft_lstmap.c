/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:22:51 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/18 23:01:10 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*next;
	t_list	*first;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	if (first == NULL)
		return (NULL);
	current = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		next = ft_lstnew((*f)(lst->content));
		if (next == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		current->next = next;
		current = next;
	}
	return (first);
}
