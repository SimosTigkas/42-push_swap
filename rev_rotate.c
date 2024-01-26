/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:15:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/24 14:13:05 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*seclast;

	if (!(*stack) || ft_stack_size(*stack) <= 1)
		return ;
	seclast = NULL;
	last = *stack;
	while (last->next)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, &"rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, &"rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, &"rrr\n", 4);
}
