/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:48:41 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/19 12:52:54 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoinfree1(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*re;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	re = malloc(len + 1);
	if (!re)
		return (0);
	while (s1 && s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		re[i + j] = s2[j];
		j++;
	}
	re[i + j] = '\0';
	free((void *)s1);
	return (re);
}

char	*ft_strjoinfree2(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*re;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	re = malloc(len + 1);
	if (!re)
		return (0);
	while (s1 && s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		re[i + j] = s2[j];
		j++;
	}
	re[i + j] = '\0';
	free((void *)s2);
	return (re);
}
