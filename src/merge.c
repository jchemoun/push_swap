/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:49:54 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:05:50 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	merge_rotb(t_sort *srt, int rrt)
{
	int	rt;

	rt = srt->b_size - rrt;
	if (rt < rrt)
	{
		while (rt)
		{
			srt->ops[srt->i++] = 7;
			ps_rt(srt->stack_b);
			rt--;
		}
	}
	else
	{
		while (rrt)
		{
			srt->ops[srt->i++] = 10;
			ps_rrt(srt->stack_b);
			rrt--;
		}
	}
}

void	merge_into_b(t_sort *srt, int n)
{
	int	nap;
	int	rt;
	int	j;

	nap = n / 2 + n % 2;
	rt = 0;
	j = n / 2;
	while (nap && j)
	{
		if ((*srt->stack_a)->nbr < (*srt->stack_b)->nbr)
		{
			srt->ops[srt->i++] = 5;
			ps_push_2in1(srt->stack_b, srt->stack_a);
			srt->b_size++;
			srt->a_size--;
			nap--;
		}
		else
			j--;
		srt->ops[srt->i++] = 6 + !!(++rt);
		ps_rt(srt->stack_b);
	}
	if (nap)
		append_ainb(srt, nap);
	merge_rotb(srt, rt);
}

void	merge_rota(t_sort *srt, int rrt)
{
	int	rt;

	rt = srt->a_size - rrt;
	if (rt < rrt)
	{
		while (rt)
		{
			srt->ops[srt->i++] = 6;
			ps_rt(srt->stack_a);
			rt--;
		}
	}
	else
	{
		while (rrt)
		{
			srt->ops[srt->i++] = 9;
			ps_rrt(srt->stack_a);
			rrt--;
		}
	}
}

void	merge_into_a(t_sort *srt, int n)
{
	int	nap;
	int	rt;
	int	j;

	nap = n / 2;
	j = n / 2 + n % 2;
	rt = 0;
	while (j && nap)
	{
		if ((*(srt->stack_b))->nbr < (*srt->stack_a)->nbr)
		{
			srt->ops[srt->i++] = 4;
			ps_push_2in1(srt->stack_a, (srt->stack_b));
			srt->b_size--;
			srt->a_size++;
			nap--;
		}
		else
			j--;
		srt->ops[srt->i++] = 5 + !!(++rt);
		ps_rt(srt->stack_a);
	}
	if (nap)
		append_bina(srt, nap);
	merge_rota(srt, rt);
}
