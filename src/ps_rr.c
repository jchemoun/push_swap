/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:02 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/27 15:59:31 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_rt(t_lstint **stack)
{
	t_lstint	*first;

	if (stack == 0 || *stack == 0 || (*stack)->next == 0)
		return ;
	ft_lstintadd_back(stack, *stack);
	first = *stack;
	*stack = (first->next);
	first->next = 0;
}

void	ps_rr(t_lstint **stack_a, t_lstint **stack_b)
{
	ps_rt(stack_a);
	ps_rt(stack_b);
}

void	ps_rrt(t_lstint **stack)
{
	t_lstint	*last;
	t_lstint	*blast;

	if (stack == 0 || *stack == 0 || (*stack)->next == 0)
		return ;
	blast = *stack;
	while (blast->next->next)
		blast = blast->next;
	last = blast->next;
	blast->next = 0;
	ft_lstintadd_front(stack, last);
}

void	ps_rrr(t_lstint **stack_a, t_lstint **stack_b)
{
	ps_rrt(stack_a);
	ps_rrt(stack_b);
}
