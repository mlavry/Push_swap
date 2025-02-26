/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:09 by mlavry            #+#    #+#             */
/*   Updated: 2025/02/10 19:19:12 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Bonus/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

//------------------------Handle inputs---------------------

long					ft_atol(const char *s);
void					free_split(char **split);
void					free_errors_split(t_stack_node **stack, char **argv);
void					error_instruction(char *line);

//------------------------Stack initiation---------------------

void					init_stack_a(t_stack_node **a, char **argv);
void					free_errors(t_stack_node **stack);
bool					error_syntax(const char *str);
int						error_duplicate(t_stack_node *stack, int n);
void					free_stack(t_stack_node **stack);
void					append_node(t_stack_node **stack, int n);

//------------------------Nodes initiation---------------------

void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *stack);
void					current_index(t_stack_node *stack);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);

//------------------------Stack utils---------------------

bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);

//------------------------Commands---------------------

void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);

//------------------------Algorithms---------------------

void					cost_analysis_a(t_stack_node *a, t_stack_node *b);
void					sort_three(t_stack_node **a);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					rrotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
