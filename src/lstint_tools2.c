/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:07:01 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 11:52:24 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lstint	*get_tlstint_n(t_lstint *elem, int n)
{
	int	i;

	i = 0;
	while (elem->next && i < n - 1)
	{
		elem = elem->next;
		i++;
	}
	return (elem);
}

int	lstint_size(t_lstint *elem)
{
	int	re;

	re = 0;
	while (elem)
	{
		re++;
		elem = elem->next;
	}
	return (re);
}
