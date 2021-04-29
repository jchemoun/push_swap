/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:44:50 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 11:14:02 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pb_sa_pa(t_sort *srt)
{
	if (srt->a_size == 3)
	{
		sa(srt);
		srt->ops[srt->i++] = 6;
		ps_rt(srt->stack_a);
	}
	else
	{
		srt->ops[srt->i++] = 5;
		ps_push_2in1(srt->stack_b, srt->stack_a);
		sa(srt);
		srt->ops[srt->i++] = 4;
		ps_push_2in1(srt->stack_a, srt->stack_b);
	}
}

void	pb_sa_pa_sa(t_sort *srt)
{
	if (srt->a_size == 3)
	{
		srt->ops[srt->i++] = 9;
		ps_rrt(srt->stack_a);
	}
	else
	{
		pb_sa_pa(srt);
		sa(srt);
	}
}

void	sa_pb_sa_pa(t_sort *srt)
{
	if (srt->a_size == 3)
	{
		srt->ops[srt->i++] = 6;
		ps_rt(srt->stack_a);
	}
	else
	{
		sa(srt);
		pb_sa_pa(srt);
	}
}

void	sa_pb_sa_pa_sa(t_sort *srt)
{
	if (srt->a_size == 3)
	{
		sa(srt);
		srt->ops[srt->i++] = 9;
		ps_rrt(srt->stack_a);
	}
	else
	{
		sa(srt);
		pb_sa_pa(srt);
		sa(srt);
	}
}

void	sort_3_intoa(t_sort *srt)
{
	if ((*srt->stack_a)->nbr < (*srt->stack_a)->next->nbr)
	{
		if ((*srt->stack_a)->next->nbr < (*srt->stack_a)->next->next->nbr)
			return ;
		else if ((*srt->stack_a)->nbr < (*srt->stack_a)->next->next->nbr)
			pb_sa_pa(srt);
		else
			pb_sa_pa_sa(srt);
	}
	else
	{
		if ((*srt->stack_a)->next->nbr > (*srt->stack_a)->next->next->nbr)
			sa_pb_sa_pa_sa(srt);
		else if ((*srt->stack_a)->nbr < (*srt->stack_a)->next->next->nbr)
			sa(srt);
		else
			sa_pb_sa_pa(srt);
	}
}
