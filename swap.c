/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:16:19 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/07 13:55:38 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, &"sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, &"sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, &"ss\n", 3);
}
