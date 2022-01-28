/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:47:00 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 18:28:01 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list, char *cmd, int i)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = *list;
	list2 = (*list)->next;
	if (list2 == NULL)
		return ;
	list3 = list2->next;
	list2->next = list1;
	list1->next = list3;
	*list = list2;
	if (i == 1)
		write(1, cmd, 3);
}

void	ss_swap(t_stack *stack, char *cmd, int i)
{
	swap(&stack->a, "sa\n", 0);
	swap(&stack->b, "sb\n", 0);
	if (i == 1)
		write(1, cmd, 3);
}

void	rotate(t_list **list, char *cmd, int i)
{
	t_list	*list1;

	list1 = *list;
	if (list1->next == NULL)
		return ;
	*list = (*list)->next;
	list1->next = NULL;
	ft_lstadd_back(list, list1);
	if (i == 1)
		write(1, cmd, 3);
}

void	rr_ab(t_list **list, char *cmd, int i)
{
	t_list	*list1;
	t_list	*last;
	int		size;

	list1 = *list;
	if (list1 == NULL)
		return ;
	last = ft_lstlast(*list);
	size = ft_lstsize(*list);
	if (size > 1)
	{
		while ((size - 2) > 0)
		{
			list1 = list1->next;
			size--;
		}
		list1->next = NULL;
		last->next = *list;
		*list = last;
	}
	if (i == 1)
		write(1, cmd, 4);
}

void	rrr(t_list **list, t_list **dest, char *cmd, int i)
{
	rr_ab(list, "rra\n", 0);
	rr_ab(dest, "rrb\n", 0);
	if (i == 1)
		write(1, cmd, 4);
}
