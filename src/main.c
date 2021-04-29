/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchemoun <jchemoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:11:08 by jchemoun          #+#    #+#             */
/*   Updated: 2021/04/29 15:22:33 by jchemoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	checker(int argc, char **argv)
{
	t_lstint	**stack_a;
	t_lstint	**stack_b;
	char		*ops;

	stack_b = malloc(sizeof(t_lstint *));
	if (!stack_b)
		proper_exit(0, 1);
	*stack_b = 0;
	pre_check_arg(argc, argv);
	stack_a = fill_a(argc, argv);
	check_dup(stack_a);
	ops = get_ops(stack_a);
	do_ops(stack_a, stack_b, ops);
	free(ops);
	if (is_sorted(stack_a, stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_lstint_b(stack_a);
	free_lstint_b(stack_b);
}

void	push_swap(int argc, char **argv)
{
	t_lstint	**stack_a;
	t_lstint	**stack_b;
	char		*ops;

	stack_b = malloc(sizeof(t_lstint *));
	if (!stack_b)
		proper_exit(0, 1);
	*stack_b = 0;
	pre_check_arg(argc, argv);
	stack_a = fill_a(argc, argv);
	check_dup(stack_a);
	if (!is_sorted(stack_a, stack_b))
	{
		ops = sort_stacks(stack_a, stack_b);
		print_ops(ops);
		free(ops);
	}
	if (stack_a)
		free_lstint_b(stack_a);
	free_lstint_b(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (!ft_strncmp(argv[0], "./checker", 9999))
		checker(argc, argv);
	else if (!ft_strncmp(argv[0], "./push_swap", 9999))
		push_swap(argc, argv);
	return (0);
}
