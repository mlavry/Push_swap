/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <taaikiazerolier@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:17:25 by mlavry            #+#    #+#             */
/*   Updated: 2025/02/10 19:21:29 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_instruction(char *line)
{
	free(line);
	ft_putstr_fd("Error\n", 2);
	exit(2);
}
