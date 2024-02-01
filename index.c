/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:21:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/01 14:49:33 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack **head_a, int index)
{
	t_stack	*head;
	int		distance;

	head = *head_a;
	distance = 0;
	while (head)
	{
		if (head->index == index)
			break ; //or-> return (distance)
		distance++;
		head = head->next;
	}
	return (distance);
}

int	is_min(t_stack *stack, int nbr)
{
	t_stack	*head;
	int		min;

	head = stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && (head->index != nbr))
			min = head->index;
	}
	return (min);
}

t_stack	*getthe_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && ((!has_min) || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
}

void	index_the_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = getthe_next_min(stack);
	while (head)
	{
		head->index = index + 1;
		head = getthe_next_min(stack);
	}
}
