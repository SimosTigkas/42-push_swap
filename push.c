/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:14:10 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/08 17:05:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*head_a;
	t_stack	*head_b;

	if (ft_stack_size(*stack_b) == 0)
		ft_error("Error\n");
	head_a = *stack_a;
	head_b = *stack_b;
	temp = head_b;
	head_b = head_b->next;
	*stack_b = head_b;
	if (!head_a)
	{
		head_a = temp;
		head_a->next = NULL;
		*stack_a = head_a;
	}
	else
	{
		temp->next = head_a;
		*stack_a = temp;
	}
	write(1, &"pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*head_a;
	t_stack	*head_b;

	if (ft_stack_size(*stack_a) == 0)
		ft_error("Error\n");
	head_a = *stack_a;
	head_b = *stack_b;
	temp = head_a;
	head_a = head_a->next;
	*stack_a = head_a;
	if (!head_b)
	{
		head_b = temp;
		head_b->next = NULL;
		*stack_b = head_b;
	}
	else
	{
		temp->next = head_b;
		*stack_b = temp;
	}
	write(1, &"pb\n", 3);
}
