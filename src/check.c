/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:27:22 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/28 11:33:49 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_dup2(t_lstint *stack_a)
{
	int			len;
	int			i;
	int			j;
	int			tmp;
	t_lstint	*elem;

	len = lstint_size(stack_a);
	i = 0;
	while (i < len)
	{
		tmp = stack_a->nbr;
		j = i + 1;
		elem = stack_a->next;
		while (j < len)
		{
			if (elem->nbr == tmp)
				return (1);
			elem = elem->next;
			j++;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}

void	check_dup(t_lstint **stack_a)
{
	t_lstint	*save;

	save = *stack_a;
	if (check_dup2(*stack_a))
		proper_exit(stack_a, 0);
	*stack_a = save;
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isinset(line[i], CMD_SET)
			|| (i != 0 && (line[i] == '\n' && line[i - 1] == '\n')))
			return (1);
		i++;
	}
	if (i != 0 && line[i - 1] != '\n')
		return (1);
	return (0);
}

void	pre_check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] == ' ' || argv[i][j] == '-'
				|| ft_isdigit(argv[i][j])))
				proper_exit(0, 0);
			j++;
		}
		if (!ft_isdigit(argv[i][j - 1]))
			proper_exit(0, 0);
		i++;
	}
}

int	is_sorted(t_lstint **stack_a, t_lstint **stack_b)
{
	int			tmp;
	t_lstint	*elem;

	if (*stack_b)
		return (0);
	elem = *stack_a;
	tmp = elem->nbr;
	while (elem->next)
	{
		elem = elem->next;
		if (tmp > elem->nbr)
			return (0);
		tmp = elem->nbr;
	}
	return (1);
}
