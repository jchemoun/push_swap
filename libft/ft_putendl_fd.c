/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:01:44 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 14:56:42 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int ret;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	ret = write(fd, s, i);
	ret = write(fd, "\n", 1);
	(void)ret;
}
