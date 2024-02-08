/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:16:01 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/08 17:08:32 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*stack) || ft_stack_size(*stack) <= 1)
		return (-1);
	head = *stack;
	last = ft_stacklast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (0);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a) == -1)
		ft_error("Error\n");
	else
		write(1, &"ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b) == -1)
		ft_error("Error\n");
	else
		write(1, &"rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) <= 1 || ft_stack_size(*stack_b) <= 1)
		ft_error("Error\n");
	else
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, &"rr\n", 3);
	}
}
