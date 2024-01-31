/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:52:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/31 13:59:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *head_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = head_a;
	min = is_min(head_a, -1);
	next_min = is_min(head_a, min);
	if (is_sorted(head_a))
		return ;
	if ((head->index == min) && (head->next->next == next_min))
	{
		rra(head_a);
		sa(head_a);
	}
	//The_rest_of_it_tomorrow!!
}

void	small_sort(t_stack **head_a, t_stack **head_b)
{
	int	size;

	if (is_sorted(head_a) || ft_stack_size(*head_a) == 0
		|| ft_stack_size(*head_a) == 1)
		return ;
	size = ft_stack_size(*head_a);
	if (size == 2)
		sa(*head_a);
	else if (size == 3)
		sort_3(*head_a);
	else if (size == 4)
		sort_4(*head_a);
	else if (size == 5)
		sort_5(*head_a);
}
