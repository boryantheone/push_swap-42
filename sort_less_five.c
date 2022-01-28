/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:22:11 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 17:07:31 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_five(t_stack *stack)
{
	if (stack->size_a == 1)
		return ;
	if (stack->size_a == 2)
		swap(&stack->a, "sa\n", 1);
	if (stack->size_a == 3)
		sort_three(stack);
	if (stack->size_a == 4)
		sort_four(stack);
	if (stack->size_a == 5)
		sort_five(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->a->value < stack->a->next->value)
	{	
		if (stack->a->value < stack->a->next->next->value
			&& stack->a->next->value > stack->a->next->next->value)
		{
			swap(&stack->a, "sa\n", 1);
			rotate(&stack->a, "ra\n", 1);
		}
		else if (stack->a->value > stack->a->next->next->value)
			rr_ab(&stack->a, "rra\n", 1);
	}
	else if (stack->a->value > stack->a->next->value)
	{
		if (stack->a->value < stack->a->next->next->value)
			swap(&stack->a, "sa\n", 1);
		else if (stack->a->value > stack->a->next->next->value
			&& stack->a->next->value < stack->a->next->next->value)
			rotate(&stack->a, "ra\n", 1);
		else if (stack->a->value > stack->a->next->next->value
			&& stack->a->next->value > stack->a->next->next->value)
		{
			swap(&stack->a, "sa\n", 1);
			rr_ab(&stack->a, "rra\n", 1);
		}
	}
}

void	sort_four(t_stack *stack)
{
	set_index(stack->a);
	while (stack->a->index != 0)
		rotate(&stack->a, "ra\n", 1);
	if (stack->a->index == 0)
		push(&stack->b, &stack->a, "pb\n", 1);
	sort_three(stack);
	push(&stack->a, &stack->b, "pa\n", 1);
}

void	sort_five(t_stack *stack)
{
	set_index(stack->a);
	while (stack->size_a--)
	{
		if (stack->a->index == 0 || stack->a->index == 1)
			push(&stack->b, &stack->a, "pb\n", 1);
		else
			rotate(&stack->a, "ra\n", 1);
	}
	sort_three(stack);
	set_index(stack->b);
	while (stack->b->index != 1)
		swap(&stack->b, "sb\n", 1);
	if (stack->b->index == 1)
		push(&stack->a, &stack->b, "pa\n", 1);
	push(&stack->a, &stack->b, "pa\n", 1);
}
