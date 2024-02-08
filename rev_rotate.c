/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:15:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/08 17:07:59 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*stack) || ft_stack_size(*stack) <= 1)
		return (-1);
	head = *stack;
	last = ft_stacklast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

void	rra(t_stack **stack_a)
{
	if (rev_rotate(stack_a) == -1)
		ft_error("Error\n");
	else
		write(1, &"rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	if (rev_rotate(stack_b) == -1)
		ft_error("Error\n");
	else
		write(1, &"rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) <= 1 || ft_stack_size(*stack_b) <= 1)
		ft_error("Error\n");
	else
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		write(1, &"rrr\n", 4);
	}
}
