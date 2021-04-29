/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:07:38 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:21:56 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lstint	*ft_lstintnew(int nbr)
{
	t_lstint	*list;

	list = malloc(sizeof(t_lstint));
	if (!list)
		return (NULL);
	list->nbr = nbr;
	list->next = NULL;
	return (list);
}

void	ft_lstintadd_back(t_lstint **alst, t_lstint *newe)
{
	t_lstint	*ptr;

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

void	ft_lstintadd_front(t_lstint **alst, t_lstint *newe)
{
	if (!newe || !alst)
		return ;
	newe->next = *alst;
	*alst = newe;
}

void	ft_lstint_print(t_lstint *elem)
{
	int			tmp;
	t_lstint	*wtf;

	wtf = elem;
	if (!wtf)
		return ;
	while (wtf->next)
	{
		tmp = wtf->nbr;
		ft_putnbr_fd(tmp, 1);
		ft_putchar_fd(' ', 1);
		wtf = wtf->next;
	}
	tmp = wtf->nbr;
	ft_putnbr_fd(tmp, 1);
}

t_lstint	*ft_lstintlast(t_lstint *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
