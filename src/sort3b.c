/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:41:17 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/28 11:45:02 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pb_pb_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
}

void	sa_pb_sa_pb_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
}

void	sa_pb_pb_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	pb_pb_pb(srt);
}

void	ra_sa_pb_rra_pb_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 6;
	ps_rt(srt->stack_a);
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 9;
	ps_rrt(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
}

void	sort_3_intob(t_sort *srt)
{
	if ((*srt->stack_a)->nbr < (*srt->stack_a)->next->nbr)
	{
		if ((*srt->stack_a)->next->nbr < (*srt->stack_a)->next->next->nbr)
			ra_sa_pb_pb_rra_pb(srt);
		else if ((*srt->stack_a)->nbr < (*srt->stack_a)->next->next->nbr)
			sa_pb_sa_pb_pb(srt);
		else
			sa_pb_pb_pb(srt);
	}
	else
	{
		if ((*srt->stack_a)->next->nbr > (*srt->stack_a)->next->next->nbr)
			pb_pb_pb(srt);
		else if ((*srt->stack_a)->nbr < (*srt->stack_a)->next->next->nbr)
			ra_sa_pb_rra_pb_pb(srt);
		else
			pb_sa_pb_pb(srt);
	}
}
