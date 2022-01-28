/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_for_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:03:06 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 19:10:32 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	else
		node -> value = content;
	node -> index = 0;
	node -> order = 0;
	node -> next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp -> next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = (lst)-> next;
		free(tmp);
		lst = tmp;
	}
	free(lst);
	lst = NULL;
}
