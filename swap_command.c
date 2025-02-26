/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:35:33 by mlavry            #+#    #+#             */
/*   Updated: 2025/01/08 19:24:08 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	if (*head == NULL || head == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}

/* #include <stdio.h>

void	print_stack(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current)
	{
		printf("nbr: %d, index: %d\n", current->nbr, current->index);
		current = current->next;
	}
	printf("\n");
}

// Fonction principale pour tester
int	main(void)
{
	// Initialisation manuelle des nœuds de la pile
	t_stack_node node1 = {42, 0, 0, false, false, NULL, NULL, NULL};
	t_stack_node node2 = {21, 1, 0, false, false, NULL, NULL, NULL};
	t_stack_node node3 = {84, 2, 0, false, false, NULL, NULL, NULL};

	// Lier les nœuds entre eux
	node1.next = &node2;
	node2.prev = &node1;
	node2.next = &node3;
	node3.prev = &node2;

	// Pointeur vers le sommet de la pile
	t_stack_node *stack_a = &node1;

	// Afficher la pile avant sa
	printf("Pile avant sa :\n");
	print_stack(stack_a);

	// Appliquer sa
	sa(&stack_a, false);

	// Afficher la pile après sa
	printf("Pile après sa :\n");
	print_stack(stack_a);

	return (0);
} */
