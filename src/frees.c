/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:08:03 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/27 16:00:03 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_lstint(t_lstint **alst)
{
	t_lstint	*elem;
	t_lstint	*next;

	elem = *alst;
	next = elem->next;
	while (next)
	{
		free(elem);
		elem = next;
		next = next->next;
	}
	free(elem);
	alst = 0;
}

void	free_lstint_b(t_lstint **alst)
{
	t_lstint	*elem;
	t_lstint	*next;

	elem = *alst;
	next = 0;
	if (elem)
		next = elem->next;
	while (next)
	{
		free(elem);
		elem = next;
		next = next->next;
	}
	free(elem);
	free(alst);
	alst = 0;
}

void	free_srt(t_sort *srt)
{
	free(srt->ops);
	free(srt);
}
