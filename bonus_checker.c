/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:25:03 by christian         #+#    #+#             */
/*   Updated: 2024/10/09 15:53:58 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_operation(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(b, a, 0);
    else if (!ft_strncmp(command, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, 0);
	else
		error_fd(1);
}

int     main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*command;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = read_args(argc, argv);
	command = get_next_line(0);
	while (command)
	{
		do_operation(&a, &b, command);
		free(command);
		command = get_next_line(0);
	}
	if (a && !b && check_if_sorted(a))
		putstr_fd("OK\n", 1);
	else
		putstr_fd("KO\n", 1);
	free_stack(&a);
    free_stack(&b);
	return (0);
}