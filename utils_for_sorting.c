/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 16:24:08 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_way(int ret, t_move *mv)
{
	int	i;

	i = mv->ra;
	if (mv->ra > mv->rb)
		i = mv->rb;
	while (i)
	{
		ret--;
		i--;
	}
	i = mv->rra;
	if (mv->rra > mv->rrb)
		i = mv->rrb;
	while (i)
	{
		ret--;
		i--;
	}
	return (ret);
}

int	find_place_in_stack(t_list *list, int place_b)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = list;
	while (tmp->order != place_b)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_place_in_stack_a(t_stack *stack, int index_b)
{
	t_list	*tmp;
	int		i;
	int		prev;
	int		next;

	i = 1;
	tmp = stack->a->next;
	prev = stack->a->index;
	next = tmp->index;
	if (index_b < stack->min)
		return (get_in_stack(stack->a, stack->min));
	else if (index_b > stack->max)
		return (get_in_stack(stack->a, stack->max) + 1);
	while (1)
	{
		i++;
		if (prev < index_b && index_b < next)
			return (i);
		prev = tmp->index;
		if (!tmp->next)
			tmp = stack->a;
		else
			tmp = tmp->next;
		next = tmp->index;
	}
}

int	get_in_stack(t_list *list, int start)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = list;
	while (tmp->index != start)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	distribution(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 3)
	{
		if (stack->a->index <= stack->mid)
			push(&stack->b, &stack->a, "pb\n", 1);
		else if (stack->a->index > stack->mid)
		{
			push(&stack->b, &stack->a, "pb\n", 1);
			rotate(&stack->b, "rb\n", 1);
		}
		else
			rotate(&stack->a, "ra\n", 1);
		i++;
	}
}
