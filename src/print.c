/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:32:02 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:24:33 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	clc(char *str)
{
	ft_putstr_fd(str, 1);
	return (1);
}

int	print_op(char op)
{
	if (op == 1)
		return (clc("sa"));
	else if (op == 2)
		return (clc("sb"));
	else if (op == 3)
		return (clc("ss"));
	else if (op == 4)
		return (clc("pa"));
	else if (op == 5)
		return (clc("pb"));
	else if (op == 6)
		return (clc("ra"));
	else if (op == 7)
		return (clc("rb"));
	else if (op == 8)
		return (clc("rr"));
	else if (op == 9)
		return (clc("rra"));
	else if (op == 10)
		return (clc("rrb"));
	else if (op == 11)
		return (clc("rrr"));
	else
		return (0);
}

char	convert_ops(char *ops, int *i)
{
	if ((ops[*i] == 1 && ops[*i + 1] == 2)
		|| (ops[*i] == 2 && ops[*i + 1] == 1))
		return (2 + !!(++*i));
	else if ((ops[*i] == 6 && ops[*i + 1] == 7)
		|| (ops[*i] == 7 && ops[*i + 1] == 6))
		return (7 + !!(++*i));
	else if ((ops[*i] == 9 && ops[*i + 1] == 10)
		|| (ops[*i] == 10 && ops[*i + 1] == 9))
		return (10 + !!(++*i));
	else
		return (ops[*i]);
}

char	*opti_ops(char *ops)
{
	int		i;
	int		j;
	int		len;
	char	*nops;

	i = 0;
	j = 0;
	len = ft_strlen(ops);
	nops = malloc(len + 1);
	if (!nops)
		proper_exit(0, 1);
	while (i < len)
	{
		nops[j] = convert_ops(ops, &i);
		j++;
		i++;
	}
	nops[j] = 0;
	return (nops);
}

void	print_ops(char *ops)
{
	int		i;
	char	*nops;

	i = 0;
	nops = opti_ops(ops);
	while (nops && nops[i])
	{
		if (print_op(nops[i]))
			ft_putchar_fd('\n', 1);
		i++;
	}
	free(nops);
}
