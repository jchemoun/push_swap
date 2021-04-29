/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:34:35 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/28 11:34:52 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	atoi_push_swap(char *nptr, int *j)
{
	long long int	re;
	int				signe;

	re = 0;
	signe = 1;
	while (nptr[*j] == ' ' || (nptr[*j] > 8 && nptr[*j] < 14))
		*j = *j + 1;
	if (nptr[*j] == '-')
	{
		signe = -1;
		*j = *j + 1;
	}
	while (ft_isdigit(nptr[*j]))
	{
		re = re * 10 + (signe * (nptr[*j] - 48));
		*j = *j + 1;
	}
	if (re > 2147483747 || re < -2147483748)
		proper_exit(0, 0);
	return ((int)re);
}

t_lstint	**fill_a(int argc, char **argv)
{
	t_lstint	**stack_a;
	int			i;
	int			j;

	i = 1;
	stack_a = malloc(sizeof(t_lstint *));
	*stack_a = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (*stack_a == 0)
			{
				*stack_a = ft_lstintnew(atoi_push_swap(argv[i], &j));
			}
			else
				ft_lstintadd_back(stack_a,
					ft_lstintnew(atoi_push_swap(argv[i], &j)));
		}
		i++;
	}
	return (stack_a);
}
