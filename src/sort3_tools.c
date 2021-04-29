/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:46:37 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/28 11:47:40 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pb_sa_pb_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
}

void	ra_sa_pb_pb_rra_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 6;
	ps_rt(srt->stack_a);
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 9;
	ps_rrt(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
}

void	sa(t_sort *srt)
{
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
}
