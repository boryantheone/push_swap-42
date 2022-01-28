/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:32:54 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 18:25:48 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					flag;
	long int			c;

	c = 0;
	flag = 1;
	i = 0;
	if (str[i] == '-')
	{
		flag *= -1;
		i++;
	}
	if (str[i] >= 47 && str[i] <= 57)
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			c = c * 10 + (str[i] - '0');
			i++;
		}
		if ((c * flag) > 2147483647 || (c * flag) < -2147483648)
			ft_error();
		return ((int)(c * flag));
	}
	return (0);
}

void	check_argv(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			ft_error();
		i++;
	}
}

void	check_dubs(t_list *list)
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
			if (tmp->value == list->value)
				flag++;
			if (flag >= 2)
				ft_error();
			tmp = tmp->next;
		}
		list = list->next;
		tmp = first;
	}
}

int	check_sort(t_list *list)
{
	t_list	*tmp;

	if (list)
	{
		check_dubs(list);
		tmp = list;
		while (tmp->next != NULL)
		{
			if (tmp->value > tmp->next->value)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
