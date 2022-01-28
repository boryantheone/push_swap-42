/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:22:45 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 19:15:57 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rotate(t_list **list, t_list **dest, char *cmd, int i)
{
	rotate(list, "ra\n", 0);
	rotate(dest, "rb\n", 0);
	if (i == 1)
		write(1, cmd, 3);
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
