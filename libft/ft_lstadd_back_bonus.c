/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:27:49 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/16 11:29:02 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **alst, t_list *newe)
{
	t_list	*ptr;

	ptr = (*alst);
	if (!(*alst))
	{
		newe->next = *alst;
		*alst = newe;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = newe;
	}
}
