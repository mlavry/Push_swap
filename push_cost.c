/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:17:37 by mlavry            #+#    #+#             */
/*   Updated: 2025/02/06 22:18:41 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost(int index, int len, bool above_median)
{
	if (above_median)
		return (index);
	return (len - index);
}

static int	calculate_push_cost(t_stack_node *a, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = calculate_cost(a->index, len_a, a->above_median);
	cost_b = calculate_cost(a->target_node->index, len_b,
			a->target_node->above_median);
	if ((a->above_median && a->target_node->above_median) || (!a->above_median
			&& !a->target_node->above_median))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = calculate_push_cost(a, len_a, len_b);
		a = a->next;
	}
}
