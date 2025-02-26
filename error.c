/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:34:36 by mlavry            #+#    #+#             */
/*   Updated: 2025/02/06 20:00:32 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_errors(t_stack_node **stack)
{
	if (stack)
		free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(2);
}

bool	error_syntax(const char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (true);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (true);
		i++;
	}
	return (false);
}

int	error_duplicate(t_stack_node *stack, int n)
{
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	free_errors_split(t_stack_node **stack, char **argv)
{
	if (stack)
		free_stack(stack);
	if (argv)
		free_split(argv);
	ft_putstr_fd("Error\n", 2);
	exit(2);
}
