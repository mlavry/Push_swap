/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:58:01 by mlavry            #+#    #+#             */
/*   Updated: 2025/02/10 19:06:50 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stack(t_stack_node *stack)
// {
//     t_stack_node *current = stack;
//     while (current)
//     {
//         printf("%d ", current->nbr);
//         current = current->next;
//     }
//     printf("\n");
// }

// void print_strings(char **strings)
// {
// 	int i = 0;
// 	while (strings[i])
// 	{
// 		printf("%s\n", strings[i]);
// 		i++;
// 	}
// }
/*void	free_split(char **split)
{
	int	i;
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}*/

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
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
