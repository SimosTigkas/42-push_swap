/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:14:10 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/07 13:56:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, &"pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, &"pb\n", 3);
}
