/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:58:54 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 17:07:01 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **list, t_list **dest, char *cmd, int i)
{
	t_list	*list2;

	list2 = *dest;
	if (list2 == NULL)
		return ;
	*dest = (*dest)->next;
	list2->next = *list;
	*list = list2;
	if (i == 1)
		write(1, cmd, 3);
}

void	set_index(t_list *list)
{
	t_list	*tmp;
	t_list	*first;
	int		flag;

	tmp = list;
	first = list;
	while (list)
	{
		flag = 0;
		while (tmp)
		{
			if (tmp->value < list->value)
				flag++;
			tmp = tmp->next;
		}
		list->index = flag;
		list = list->next;
		tmp = first;
	}
}

void	set_order(t_list *list)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (list)
	{
		list->order = i;
		list = list->next;
		i++;
	}
}

void	max_and_mid_index_in_stack(t_stack *stack)
{
	int		max;
	t_list	*list;

	list = stack->a;
	max = -1;
	while (list)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	stack->max = max;
	stack->mid = stack->max / 2 + 1;
}

void	min_index_in_stack(t_stack *stack)
{
	int		min;
	t_list	*list;

	list = stack->a;
	min = list->index;
	while (list)
	{
		if (min > list->index)
			min = list->index;
		list = list->next;
	}
	stack->min = min;
}
