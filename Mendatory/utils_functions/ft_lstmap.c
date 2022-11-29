/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:49 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/14 14:41:51 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_list(t_list **lst, t_list *node, void (*del)(void *))
{
	while (lst)
	{
		node = (*lst)->next;
		(*del)(node->content);
		free(*lst);
		*lst = node;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;

	result = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			free_list(&result, node, del);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
