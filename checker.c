/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:22:49 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/28 13:20:58 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->argc = 0;
	stack->argv = NULL;
}

void	sort(t_stack *stack, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(&stack->a, "sa\n", 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(&stack->b, "sb\n", 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push(&stack->a, &stack->b, "pa\n", 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(&stack->b, &stack->a, "pb\n", 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(&stack->a, "ra\n", 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(&stack->b, "rb\n", 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rr_ab(&stack->a, "rra\n", 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rr_ab(&stack->b, "rrb\n", 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss_swap(stack, "ss\n", 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr_rotate(&stack->a, &stack->b, "rr\n", 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(&stack->a, &stack->b, "rrr\n", 0);
	else
		ft_error();
}

void	checker(t_stack *stack)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		sort(stack, str);
	}
	if (check_sort(stack->a) == 0)
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack(stack);
	stack->argc = argc;
	stack->argv = argv;
	stack->a = record_number(stack);
	check_dubs(stack->a);
	checker(stack);
	return (0);
}
