/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:03:36 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/16 13:25:08 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_s(t_lstint **stack)
{
	t_lstint	*elem;
	int			tmp;

	elem = *stack;
	if (elem->next == 0)
		return ;
	tmp = elem->nbr;
	elem->nbr = elem->next->nbr;
	elem->next->nbr = tmp;
}

void	ps_ss(t_lstint **stack_a, t_lstint **stack_b)
{
	ps_s(stack_a);
	ps_s(stack_b);
}
