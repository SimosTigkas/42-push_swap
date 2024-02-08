/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:16:19 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/08 17:20:44 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		temp_data;
	int		temp_index;

	if (!stack || ft_stack_size(*stack) <= 1)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error\n");
	temp_data = head->data;
	temp_index = head->index;
	head->data = next->data;
	head->index = next->index;
	next->data = temp_data;
	next->index = temp_index;
	return (0);
}

void	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		ft_error("Error\n");
	else
		write(1, &"sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		ft_error("Error\n");
	else
		write(1, &"sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) <= 1 || ft_stack_size(*stack_b) <= 1)
		ft_error("Error\n");
	else
	{
		sa(stack_a);
		sb(stack_b);
		write(1, &"ss\n", 3);
	}
}
