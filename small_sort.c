/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:52:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/16 14:43:27 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_5(t_stack **head_a, t_stack **head_b)
{
	int	distance;

	distance = get_distance(head_a, is_max(head_a, -1));
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
	ra(head_a);
}

void	sort_4(t_stack **head_a, t_stack **head_b)
{
	int	distance;

	if (is_sorted(head_a))
		return ;
	distance = get_distance(head_a, is_max(head_a, -1));
	if (distance == 1)
		ra(head_a);
	else if (distance == 2)
	{
		ra(head_a);
		ra(head_a);
	}
	else if (distance == 3)
		rra(head_a);
	pb(head_a, head_b);
	sort_3(head_a);
	pa(head_a, head_b);
	ra(head_a);
}

void	sort_3(t_stack **head_a)
{
	t_stack	*head;

	head = *head_a;
	if ((head->index == 0) && (head->next->index == 2))
	{
		ra(head_a);
		sa(head_a);
	}
	else if (head->index == 1)
	{
		if (head->next->index == 0)
			sa(head_a);
		else
			rra(head_a);
	}
	else
	{
		if (head->next->index == 0)
			ra(head_a);
		else
		{
			ra(head_a);
			sa(head_a);
		}
	}
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
