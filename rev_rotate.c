/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:15:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/23 15:13:59 by stigkas          ###   ########.fr       */
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
	last = *stack; //head
	while (last->next) //null
	{
		seclast = last; // n3
		last = last->next; // n4
	}
	seclast->next = NULL; //n3 -> next = Null
	last->next = *stack; //n4 is pointing to the head
	*stack = last; //head gets the address of the head
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
