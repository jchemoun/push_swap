/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:31:48 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/03 15:11:35 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*re;

	i = 0;
	s_len = 0;
	while (s && s[s_len])
		s_len++;
	if (start > s_len)
	{
		re = malloc(1);
		re[0] = '\0';
		return (re);
	}
	re = malloc(len + 1);
	if (!re)
		return (0);
	while (i < len && s[start + i])
	{
		re[i] = s[start + i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
