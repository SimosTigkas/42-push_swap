/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:21:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/16 08:55:46 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	get_distance(t_stack **head_a, int index)
{
	t_stack	*head;
	int		distance;

	head = *head_a;
	distance = 0;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	is_max(t_stack **stack, int nbr)
{
	t_stack	*head;
	int		max;

	head = *stack;
	max = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index > max) && (head->index != nbr))
			max = head->index;
	}
	return (max);
}

t_stack	*getthe_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	has_min = 0;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && ((has_min == 0) || head->data < min->data))
		{
			min = head;
			has_min = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_the_stack(t_stack **stack)
{
	t_stack	*cmin;
	t_stack	*temp;
	int		counter;
	int		i;

	i = 0;
	temp = *stack;
	counter = ft_stack_size(temp);
	while (i < counter)
	{
		cmin = getthe_next_min(&temp);
		cmin->index = i;
		i++;
	}
}
