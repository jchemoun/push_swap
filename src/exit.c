/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:26:19 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 14:59:23 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	proper_exit(t_lstint **stack_a, int mal)
{
	int	re;

	if (stack_a)
		free_lstint(stack_a);
	if (mal == 1)
		re = write(1, "MALLOC\n", 8);
	re = write(1, "ERROR\n", 7);
	exit(re);
}
