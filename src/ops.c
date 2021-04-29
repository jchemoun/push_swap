/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:23:50 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:37:39 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	check_op(char *op)
{
	if (!ft_strncmp("sa", op, 9999))
		return (1);
	if (!ft_strncmp("sb", op, 9999))
		return (2);
	if (!ft_strncmp("ss", op, 9999))
		return (3);
	if (!ft_strncmp("pa", op, 9999))
		return (4);
	if (!ft_strncmp("pb", op, 9999))
		return (5);
	if (!ft_strncmp("ra", op, 9999))
		return (6);
	if (!ft_strncmp("rb", op, 9999))
		return (7);
	if (!ft_strncmp("rr", op, 9999))
		return (8);
	if (!ft_strncmp("rra", op, 9999))
		return (9);
	if (!ft_strncmp("rrb", op, 9999))
		return (10);
	if (!ft_strncmp("rrr", op, 9999))
		return (11);
	return (0);
}

char	*translate_ops(char **ops)
{
	char	*line;
	int		size_tab;
	int		i;
	char	tmp;

	size_tab = 0;
	while (ops[size_tab])
		size_tab++;
	line = malloc(size_tab + 1);
	if (!line)
		proper_exit(0, 0);
	i = 0;
	while (i < size_tab)
	{
		tmp = check_op(ops[i]);
		if (tmp == 0)
			proper_exit(0, 0);
		line[i] = tmp;
		i++;
	}
	free_tab(ops);
	line[i] = 0;
	return (line);
}

char	*get_ops(t_lstint **stack_a)
{
	char	buf[BUF_SIZE + 1];
	char	*line;
	int		buf_len;

	buf_len = 1;
	line = malloc(1);
	if (!line)
		proper_exit(stack_a, 1);
	line[0] = 0;
	while (buf_len != 0)
	{
		buf_len = read(0, &buf, BUF_SIZE);
		buf[buf_len] = 0;
		line = ft_strjoinfree1(line, buf);
	}
	if (check_line(line))
		proper_exit(0, 0);
	line = translate_ops(ft_split_free(line, '\n'));
	return (line);
}

void	do_op(t_lstint **stack_a, t_lstint **stack_b, char op)
{
	if (op == 1)
		ps_s(stack_a);
	if (op == 2)
		ps_s(stack_b);
	if (op == 3)
		ps_ss(stack_a, stack_b);
	if (op == 4 && *stack_b)
		ps_push_2in1(stack_a, stack_b);
	if (op == 5 && *stack_a)
		ps_push_2in1(stack_b, stack_a);
	if (op == 6)
		ps_rt(stack_a);
	if (op == 7)
		ps_rt(stack_b);
	if (op == 8)
		ps_rr(stack_a, stack_b);
	if (op == 9)
		ps_rrt(stack_a);
	if (op == 10)
		ps_rrt(stack_b);
	if (op == 11)
		ps_rrr(stack_a, stack_b);
}

void	do_ops(t_lstint **stack_a, t_lstint **stack_b, char *ops)
{
	int	i;

	i = 0;
	while (ops[i])
	{
		do_op(stack_a, stack_b, ops[i]);
		i++;
	}
}
