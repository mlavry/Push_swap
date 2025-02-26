/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:44:42 by mlavry            #+#    #+#             */
/*   Updated: 2025/02/10 19:19:52 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_instruction(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, true);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, true);
	else
		error_instruction(line);
}

static void	read_and_execute(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_instruction(line, a, b);
		free(line);
	}
}

void	init_stack_splitted(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 1 && (argv[i][0] == '+' || argv[i][0] == '-'))
			free_errors_split(a, argv);
		if (error_syntax(argv[i]))
			free_errors_split(a, argv);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors_split(a, argv);
		if (error_duplicate(*a, (int)n))
			free_errors_split(a, argv);
		append_node(a, (int)n);
		i++;
	}
}

void	split_chain(t_stack_node **a, char **argv)
{
	argv = ft_split(argv[1], ' ');
	init_stack_splitted(a, argv);
	free_split(argv);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		split_chain(&a, argv);
	else
		init_stack_a(&a, argv + 1);
	read_and_execute(&a, &b);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
