/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:52:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/16 08:37:19 by stigkas          ###   ########.fr       */
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
	int		max;
	int		next_max;

	head = *head_a;
	max = is_max(head_a, -1);
	next_max = is_max(head_a, max);
	if (is_sorted(head_a))
		return ;
	if ((head->index == max) && (head->next->index != next_max))
		ra(head_a);
	else if ((head->index == next_max) && (head->next->index == max))
		rra(head_a);
	else if ((head->index == next_max) && (head->next->index != max))
		sa(head_a);
	else if (head->next->index == next_max)
	{
		ra(head_a);
		sa(head_a);
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
