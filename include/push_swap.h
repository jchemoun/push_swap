/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:12:10 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:27:48 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# define BUF_SIZE 2048
# define CMD_SET "sprab\n"

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <ft_printf.h>

typedef struct s_lstint
{
	struct s_lstint	*next;
	int				nbr;
}				t_lstint;

typedef struct s_sort
{
	t_lstint	**stack_a;
	t_lstint	**stack_b;
	char		*ops;
	int			a_size;
	int			b_size;
	int			i;
}				t_sort;

t_lstint	*ft_lstintnew(int nbr);
void		ft_lstintadd_back(t_lstint **alst, t_lstint *newe);
void		ft_lstint_print(t_lstint *alst);
void		ft_lstintadd_front(t_lstint **alst, t_lstint *newe);
t_lstint	*ft_lstintlast(t_lstint *lst);
int			lstint_size(t_lstint *elem);
t_lstint	*get_tlstint_n(t_lstint *elem, int n);

void		free_lstint(t_lstint **alst);
void		free_lstint_b(t_lstint **alst);
void		free_srt(t_sort *srt);

void		do_ops(t_lstint **stack_a, t_lstint **stack_b, char *ops);
void		do_op(t_lstint **stack_a, t_lstint **stack_b, char op);
char		*get_ops(t_lstint **stack_a);
char		*translate_ops(char **ops);
char		check_op(char *op);

int			check_line(char *line);
void		check_dup(t_lstint **stack_a);
int			check_dup2(t_lstint *stack_a);
void		pre_check_arg(int argc, char **argv);
int			is_sorted(t_lstint **stack_a, t_lstint **stack_b);

void		print_ops(char *ops);
int			print_op(char op);

int			atoi_push_swap(char *nptr, int *j);
t_lstint	**fill_a(int argc, char **argv);

void		sort_3(t_sort *srt, int mod);
void		sort_2(t_sort *srt, int mod);
void		merge_sort(t_sort *srt, int mod, int n);
void		sort_recu(t_sort *srt, int mod, int n);
char		*sort_stacks(t_lstint **stack_a, t_lstint **stack_b);

void		merge_into_b(t_sort *srt, int n);
void		merge_into_a(t_sort *srt, int n);
void		merge_rota(t_sort *srt, int rrt);
void		merge_rotb(t_sort *srt, int rrt);

void		append_bina(t_sort *srt, int nap);
void		append_ainb(t_sort *srt, int nap);

void		append_sorted_into_a(t_sort *srt, int n);
void		append_sorted_into_b(t_sort *srt, int n);

void		merge_front_into_a(t_sort *srt, int n);
void		merge_front_into_b(t_sort *srt, int n);

void		sort_3_intob(t_sort *srt);
void		ra_sa_pb_rra_pb_pb(t_sort *srt);
void		sa_pb_pb_pb(t_sort *srt);
void		sa_pb_sa_pb_pb(t_sort *srt);
void		pb_pb_pb(t_sort *srt);

void		sa(t_sort *srt);
void		ra_sa_pb_pb_rra_pb(t_sort *srt);
void		pb_sa_pb_pb(t_sort *srt);

void		sort_3_intoa(t_sort *srt);
void		sa_pb_sa_pa_sa(t_sort *srt);
void		sa_pb_sa_pa(t_sort *srt);
void		pb_sa_pa_sa(t_sort *srt);
void		pb_sa_pa(t_sort *srt);

void		proper_exit(t_lstint **stack_a, int mal);

void		ps_push_2in1(t_lstint **stack_a, t_lstint **stack_b);
void		ps_rt(t_lstint **stack);
void		ps_rr(t_lstint **stack_a, t_lstint **stack_b);
void		ps_rrt(t_lstint **stack);
void		ps_rrr(t_lstint **stack_a, t_lstint **stack_b);
void		ps_s(t_lstint **stack);
void		ps_ss(t_lstint **stack_a, t_lstint **stack_b);

#endif