/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:52:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/13 15:28:26 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_5(t_stack **head_a, t_stack **head_b)
{
	int	distance;

	distance = get_distance(head_a, is_min(head_a, -1));
	if (distance == 1)
		sa(head_a);
	else if (distance == 2)
	{
		ra(head_a);
		sa(head_a);
	}
	else if (distance == 3)
	{
		rra(head_a);
		rra(head_a);
	}
	else if (distance == 4)
		rra(head_a);
	if (is_sorted(head_a))
		return ;
	pb(head_a, head_b);
	sort_4(head_a, head_b);
	pa(head_a, head_b);
}

void	sort_4(t_stack **head_a, t_stack **head_b)
{
	int	distance;

	if (is_sorted(head_a))
		return ;
	distance = get_distance(head_a, is_min(head_a, -1));
	if (distance == 1)
		ra(head_a);
	else if (distance == 2)
	{
		ra(head_a);
		sa(head_a);
	}
	else if (distance == 3)
		rra(head_a);
	if (is_sorted(head_a))
		return ;
	pb(head_a, head_b);
	sort_3(head_a);
	pa(head_a, head_b);
}

void	sort_3(t_stack **head_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *head_a;
	min = is_min(head_a, -1);
	next_min = is_min(head_a, min);
	// if (is_sorted(head_a))
	// 	return ;
	if ((head->index == min) && (head->next->index != next_min))
	{
		rra(head_a);
		sa(head_a);
	}
	else if ((head->index == next_min) && (head->next->index == min))
		sa(head_a);
	else if ((head->index == next_min) && (head->next->index != min))
		rra(head_a);
	else if (head->next->index == next_min)
	{
		sa(head_a);
		rra(head_a);
	}
	else
		ra(head_a);
}

void	small_sort(t_stack **head_a, t_stack **head_b)
{
	int	size;

	size = ft_stack_size(*head_a);
	if (size == 2)
		sa(head_a);
	else if (size == 3)
		sort_3(head_a);
	else if (size == 4)
		sort_4(head_a, head_b);
	else if (size == 5)
		sort_5(head_a, head_b);
	else
		return ;
}
