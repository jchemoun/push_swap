/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:38:08 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:26:02 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3(t_sort *srt, int mod)
{
	if (mod)
	{
		srt->b_size += 3;
		srt->a_size -= 3;
		sort_3_intob(srt);
	}
	else
		sort_3_intoa(srt);
}

void	sort_2(t_sort *srt, int mod)
{
	if (mod)
	{
		srt->b_size += 2;
		srt->a_size -= 2;
		srt->ops[srt->i++] = 5;
		srt->ops[srt->i++] = 5;
		ps_push_2in1(srt->stack_b, srt->stack_a);
		ps_push_2in1(srt->stack_b, srt->stack_a);
		if ((*srt->stack_b)->nbr > (*srt->stack_b)->next->nbr)
		{
			srt->ops[srt->i++] = 2;
			ps_s(srt->stack_b);
		}
	}
	else if ((*srt->stack_a)->nbr > (*srt->stack_a)->next->nbr)
	{
		srt->ops[srt->i++] = 1;
		ps_s(srt->stack_a);
	}
}

void	merge_sort(t_sort *srt, int mod, int n)
{
	t_lstint	*naiem;
	t_lstint	*nbiem;

	naiem = get_tlstint_n(*(srt->stack_a), n / 2 + n % 2);
	nbiem = get_tlstint_n(*(srt->stack_b), n / 2);
	if (!mod)
	{
		if (naiem->nbr < (*srt->stack_b)->nbr)
			append_sorted_into_a(srt, n);
		else if (nbiem->nbr < (*srt->stack_a)->nbr)
			merge_front_into_a(srt, n);
		else
			merge_into_a(srt, n);
	}
	else
	{
		if (nbiem->nbr < (*srt->stack_a)->nbr)
			append_sorted_into_b(srt, n);
		else if (naiem->nbr < (*srt->stack_b)->nbr)
			merge_front_into_b(srt, n);
		else
			merge_into_b(srt, n);
	}
}

void	sort_recu(t_sort *srt, int mod, int n)
{
	if (n == 1)
		return ;
	else if (n == 2)
		sort_2(srt, mod);
	else if (n == 3)
		sort_3(srt, mod);
	else
	{
		sort_recu(srt, 1, n / 2);
		sort_recu(srt, 0, n / 2 + n % 2);
		merge_sort(srt, mod, n);
	}
}

char	*sort_stacks(t_lstint **stack_a, t_lstint **stack_b)
{
	t_sort	*srt;
	char	*ret;

	srt = malloc(sizeof(t_sort));
	if (!srt)
		proper_exit(stack_a, 1);
	srt->a_size = lstint_size(*stack_a);
	srt->b_size = 0;
	srt->ops = malloc(srt->a_size * 200);
	if (!srt->ops)
		proper_exit(stack_a, 1);
	srt->i = 0;
	srt->stack_a = stack_a;
	srt->stack_b = stack_b;
	sort_recu(srt, 0, srt->a_size);
	srt->ops[srt->i] = 0;
	ret = ft_strdup(srt->ops);
	free_srt(srt);
	return (ret);
}
