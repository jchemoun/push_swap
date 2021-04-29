/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:10:55 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/27 16:00:21 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_push_2in1(t_lstint **stack_a, t_lstint **stack_b)
{
	t_lstint	*save;

	if (stack_b == 0)
		return ;
	save = (*stack_b)->next;
	ft_lstintadd_front(stack_a, *stack_b);
	*stack_b = save;
}
