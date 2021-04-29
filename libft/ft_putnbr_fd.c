/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:04:08 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 14:57:09 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;
	int				ret;

	if (n < 0)
	{
		ret = write(fd, "-", 1);
		n2 = -n;
	}
	else
		n2 = n;
	if (n2 < 10)
		ft_putchar_fd((n2 + 48), fd);
	else
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
	(void)ret;
}
