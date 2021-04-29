/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:16:28 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/16 11:28:44 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_front(t_list **alst, t_list *newe)
{
	if (!newe || !alst)
		return ;
	newe->next = *alst;
	*alst = newe;
}
