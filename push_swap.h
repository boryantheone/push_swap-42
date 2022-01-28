/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:33:55 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 19:38:12 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stdio.h"
# include "./libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				order;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		size_a;
	int		size_b;
	int		argc;
	char	**argv;
	int		mid;
	int		max;
	int		min;
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	len;
	int	index;
}	t_move;

//error
void	ft_error(void);

//list_function
void	init_stack(t_stack *stack);
void	init_moves(t_move *moves);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstput(t_list *lst);
void	ft_lstclear(t_list *lst);

//check_argv and recording
void	check_argv(char *num);
int		ft_atoi(const char *str);
t_list	*record_number(t_stack *stack);
int		check_sort(t_list *list);
void	check_dubs(t_list *list);

//operation
void	push(t_list **list, t_list **dest, char *cmd, int i);
void	swap(t_list **list, char *cmd, int i);
void	ss_swap(t_stack *stack, char *cmd, int i);
void	rotate(t_list **list, char *cmd, int i);
void	rr_ab(t_list **list, char *cmd, int i);
void	rrr(t_list **list, t_list **dest, char *cmd, int i);
void	rr_rotate(t_list **list, t_list **dest, char *cmd, int i);

//for algorithm
void	sort_more_five(t_stack *stack, t_move *moves);
void	set_index(t_list *list);
void	set_order(t_list *list);
void	sort_less_five(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);
void	distribution(t_stack *stack);
void	sort_main(t_stack *stack, t_move *moves);
void	max_and_mid_index_in_stack(t_stack *stack);
void	min_index_in_stack(t_stack *stack);
int		find_max(int num1, int num2);
int		find_place_in_stack_a(t_stack *stack, int index_b);
int		find_place_in_stack(t_list *list, int place_b);
int		count_number_of_move(t_move *moves, t_stack *stack, int place_b, \
int index_b);
void	do_operation_1(t_stack *stack, t_move *moves);
void	do_operation_2(t_stack *stack, t_move *moves);
void	final_sort(t_stack *stack, t_move *moves);
int		find_optimal_way(int count, t_move *moves);
int		get_in_stack(t_list *list, int start);

//checker
char	*get_next_line(int fd);
//int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, char c);
void	sort(t_stack *stack, char *line);
void	checker(t_stack *stack);

#endif