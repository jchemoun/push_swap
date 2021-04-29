/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:49:53 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:27:24 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	merge_front_into_a(t_sort *srt, int n)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while (rt < n / 2 - 1)
	{
		srt->ops[srt->i++] = 7;
		ps_rt(srt->stack_b);
		rt++;
	}
	while (i < n / 2)
	{
		if (i < n / 2 && i != 0 && srt->b_size > 2)
		{
			srt->ops[srt->i++] = 10;
			ps_rrt(srt->stack_b);
		}
		srt->ops[srt->i++] = 4;
		ps_push_2in1(srt->stack_a, srt->stack_b);
		srt->b_size--;
		srt->a_size++;
		i++;
	}
}

void	merge_front_into_b(t_sort *srt, int n)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while (rt < n / 2  + n % 2 - 1)
	{
		srt->ops[srt->i++] = 6;
		ps_rt(srt->stack_a);
		rt++;
	}
	while (i < n / 2 + n % 2)
	{
		if (i < n / 2 + n % 2 && i != 0 && srt->a_size > 2)
		{
			srt->ops[srt->i++] = 9;
			ps_rrt(srt->stack_a);
		}
		srt->ops[srt->i++] = 5;
		ps_push_2in1(srt->stack_b, srt->stack_a);
		srt->b_size++;
		srt->a_size--;
		i++;
	}
}
