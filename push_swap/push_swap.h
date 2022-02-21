/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:47:44 by wben-sai          #+#    #+#             */
/*   Updated: 2021/06/30 16:47:44 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 

typedef struct s_stacks
{
	int					stack;
	int					pos;
	char				c;
	struct s_stacks		*next;
}	t_stacks;

struct s_param
{
	t_stacks	*stacka;
	t_stacks	*stackb;
	int			middle;
	long		min;
	long		back;
	int			i;
	int			res;
	int			nbr;
}	t_param;

void					sa(t_stacks **lst, int x);
void					sb(t_stacks **lst, int b);
void					ss(t_stacks **lsta, t_stacks **lstb);
void					ra(t_stacks **lst, int x);
void					rb(t_stacks **lst, int x);
void					rr(t_stacks **lsta, t_stacks **lstb);
void					rra(t_stacks **lst, int x);
void					rrb(t_stacks **lst, int x);
void					rrr(t_stacks **lsta, t_stacks **lstb);
void					pb(t_stacks **lsta, t_stacks **lstb);
void					pa(t_stacks **lsta, t_stacks **lstb);
int						is_number(char *s);
int						nbr_pos(t_stacks *lst, int pos);
int						pos_nbr_in_lst(t_stacks *lst, int nbr);
int						check_argv(char **av);
int						is_in(t_stacks *lst, int pos);
int						val_pos(t_stacks *lst, int pos);
int						len_stack(t_stacks *lst);
void					lstadd_back(t_stacks **list_shell, t_stacks *new);
t_stacks				*lstnew(int stack, int pos, char c);
void					sort_n_nbr(int n, t_stacks **stack);
int						check_sort(t_stacks *lst);
void					sort_stack(t_stacks **stacka);
void					sort_3_nbr(t_stacks **stack);
void					push_close_n_nbr(int n);
int						push_close_nbr(int n, t_stacks **lst);
void					get_right_nbr_in_a(int nbr);
void					get_right_nbr(int nbr);
void					get_close_nbr(int nbr, t_stacks **lst);
int						get_position_nbr(t_stacks *lst, int nbr);
void					let_go(int ac);
void					re_push(void);
void					check_rules(int len);
void					fill_stack(char **av);
void					freestack(void);
int						ft_atoi(const char *str);
int						getsign(const char *str, int *i);
int						ft_strlen(char *s);
#endif
