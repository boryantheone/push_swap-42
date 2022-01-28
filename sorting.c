/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:10:53 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 20:10:43 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number_of_move(t_move *moves, t_stack *stack, int place_b, \
int index_b)
{
	int	sum;

	init_moves(moves);
	moves->len = ft_lstsize(stack->b);
	moves->index = find_place_in_stack(stack->b, place_b);
	if (moves->index <= moves->len / 2)
		moves->rb = moves->index - 1;
	else
		moves->rrb = moves->len - moves->index + 1;
	moves->len = ft_lstsize(stack->a);
	max_and_mid_index_in_stack(stack);
	min_index_in_stack(stack);
	moves->index = find_place_in_stack_a(stack, index_b);
	if (moves->index <= moves->len / 2)
		moves->ra = moves->index - 1;
	else
		moves->rra = moves->len - moves->index + 1;
	sum = moves->ra + moves->rb + moves->rra + moves->rrb;
	return (find_optimal_way(sum, moves));
}

void	do_operation_2(t_stack *stack, t_move *moves)
{
	if (moves->ra > 0)
	{
		rotate(&stack->a, "ra\n", 1);
		moves->ra -= 1;
	}
	else if (moves->rb > 0)
	{
		rotate(&stack->b, "rb\n", 1);
		moves->rb -= 1;
	}
	else if (moves->rrb > 0)
	{
		rr_ab(&stack->b, "rrb\n", 1);
		moves->rrb -= 1;
	}
	else if (moves->rra > 0)
	{
		rr_ab(&stack->a, "rra\n", 1);
		moves->rra -= 1;
	}
}

void	do_operation_1(t_stack *stack, t_move *moves)
{
	while (moves->ra || moves->rra || moves->rb || moves->rrb)
	{
		if (moves->ra && moves->rb)
		{
			rotate(&stack->a, "ra\n", 0);
			rotate(&stack->b, "rr\n", 1);
			moves->ra -= 1;
			moves->rb -= 1;
		}
		else if (moves->rra && moves->rrb)
		{
			rrr(&stack->a, &stack->b, "rrr\n", 1);
			moves->rra -= 1;
			moves->rrb -= 1;
		}
		else
			do_operation_2(stack, moves);
	}
	if (stack->b)
		push(&stack->a, &stack->b, "pa\n", 1);
}

void	final_sort(t_stack *stack, t_move *moves)
{
	init_moves(moves);
	moves->len = ft_lstsize(stack->a);
	moves->index = get_in_stack(stack->a, 0);
	if (moves->len / 2 >= moves->index)
		moves->ra = moves->index - 1;
	else if (moves->len > 1)
		moves->rra = moves->len - moves->index + 1;
	do_operation_1(stack, moves);
}

void	sort_main(t_stack *stack, t_move *moves)
{
	t_list	*tmp;
	t_list	*list_b;
	int		min_count;
	int		count_moves;

	min_count = -1;
	list_b = stack->b;
	while (list_b)
	{
		count_moves = count_number_of_move(moves, stack, list_b->order, \
		list_b->index);
		if (count_moves <= min_count || min_count == -1)
		{
			min_count = count_moves;
			tmp = list_b;
		}
		list_b = list_b->next;
	}
	min_count = count_number_of_move(moves, stack, tmp->order, tmp->index);
	do_operation_1(stack, moves);
}
