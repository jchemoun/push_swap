/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:48:11 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/28 11:48:30 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	append_ainb(t_sort *srt, int nap)
{
	int	j;

	j = 1;
	while (j < nap)
	{
		srt->ops[srt->i++] = 6;
		ps_rt(srt->stack_a);
		j++;
	}
	while (j)
	{
		srt->ops[srt->i++] = 5;
		ps_push_2in1(srt->stack_b, srt->stack_a);
		srt->a_size--;
		srt->b_size++;
		j--;
		if (j)
		{
			srt->ops[srt->i++] = 9;
			ps_rrt(srt->stack_a);
		}
	}
}

void	append_bina(t_sort *srt, int nap)
{
	int	j;

	j = 1;
	while (j < nap)
	{
		srt->ops[srt->i++] = 7;
		ps_rt(srt->stack_b);
		j++;
	}
	while (j && srt->b_size)
	{
		srt->ops[srt->i++] = 4;
		ps_push_2in1(srt->stack_a, srt->stack_b);
		srt->b_size--;
		srt->a_size++;
		j--;
		if (j)
		{
			srt->ops[srt->i++] = 10;
			ps_rrt(srt->stack_b);
		}
	}
}
