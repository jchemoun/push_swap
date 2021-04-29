/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:21:39 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:04:53 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sb_pa_pa(t_sort *srt)
{
	srt->ops[srt->i++] = 2;
	ps_s(srt->stack_b);
	srt->ops[srt->i++] = 4;
	ps_push_2in1(srt->stack_a, srt->stack_b);
	srt->ops[srt->i++] = 4;
	ps_push_2in1(srt->stack_a, srt->stack_b);
	srt->b_size -= 2;
	return (2);
}

int	sa_pb_pb(t_sort *srt)
{
	srt->ops[srt->i++] = 1;
	ps_s(srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->ops[srt->i++] = 5;
	ps_push_2in1(srt->stack_b, srt->stack_a);
	srt->a_size -= 2;
	return (2);
}

void	append_sorted_into_a(t_sort *srt, int n)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while ((srt->a_size != n / 2 + n % 2) && (rt < n / 2 + n % 2))
	{
		srt->ops[srt->i++] = 5 + !!(++rt);
		ps_rt(srt->stack_a);
	}
	if ((n == 4 || n == 5) && (srt->a_size != n / 2 + n % 2))
		i = sb_pa_pa(srt);
	while (i < n / 2)
	{
		srt->ops[srt->i++] = 4;
		ps_push_2in1(srt->stack_a, srt->stack_b);
		srt->b_size -= 1;
		if (srt->a_size != n / 2 + n % 2)
			rt++;
		srt->ops[srt->i++] = 6;
		ps_rt(srt->stack_a);
		i++;
	}
	srt->a_size += i;
	merge_rota(srt, rt);
}

void	append_sorted_into_b(t_sort *srt, int n)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while ((srt->b_size != n / 2) && (rt < n / 2))
	{
		srt->ops[srt->i++] = 6 + !!(++rt);
		ps_rt(srt->stack_b);
	}
	if (n == 4 && (srt->b_size != n / 2))
		i = sa_pb_pb(srt);
	while (i < n / 2 + n % 2)
	{
		srt->ops[srt->i++] = 5;
		ps_push_2in1(srt->stack_b, srt->stack_a);
		srt->a_size -= 1;
		if (srt->b_size != n / 2)
			rt++;
		srt->ops[srt->i++] = 7;
		ps_rt(srt->stack_b);
		i++;
	}
	srt->b_size += i;
	merge_rotb(srt, rt);
}
