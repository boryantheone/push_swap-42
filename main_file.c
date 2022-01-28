/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:01:37 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/28 16:35:24 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->min = 0;
}

void	init_moves(t_move *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->len = 0;
	moves->index = 0;
}

void	sort_more_five(t_stack *stack, t_move *moves)
{
	distribution(stack);
	sort_three(stack);
	set_order(stack->b);
	min_index_in_stack(stack);
	while (ft_lstsize(stack->b))
		sort_main(stack, moves);
	final_sort(stack, moves);
}

t_list	*record_number(t_stack *stack)
{
	int		i;
	int		j;
	char	**numbers;
	t_list	*list;

	j = 0;
	list = NULL;
	while (stack->argv[++j])
	{
		i = 0;
		numbers = ft_split(stack->argv[j], ' ');
		while (numbers[i])
		{
			check_argv(numbers[i]);
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(numbers[i])));
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_move	*moves;

	stack = (t_stack *)malloc(sizeof(t_stack));
	moves = (t_move *)malloc(sizeof(t_move));
	init_stack(stack);
	stack->argc = argc;
	stack->argv = argv;
	stack->a = record_number(stack);
	if (check_sort(stack->a) == 1)
		return (0);
	stack->size_a = ft_lstsize(stack->a);
	set_index(stack->a);
	max_and_mid_index_in_stack(stack);
	if (stack->size_a <= 5)
		sort_less_five(stack);
	else if (stack->size_a > 5)
		sort_more_five(stack, moves);
	ft_lstclear(stack->a);
	// while (1) ;
	return (0);
}
