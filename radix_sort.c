/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:32:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/16 15:15:56 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	check_and_push(t_stack **h_a, t_stack **h_b, int m_b, int m_bits)
{
	t_stack	*temp;
	int		counter;

	temp = *h_b;
	counter = ft_stack_size(temp);
	if (m_b < m_bits - 1)
	{
		while (counter > 0)
		{
			if (((temp->index >> (m_b + 1)) & 1) == 1)
				pa(h_a, h_b);
			else
				rb(h_b);
			temp = *h_b;
			counter--;
		}
	}
	else
	{
		while (ft_stack_size(temp) != 0)
		{
			pa(h_a, h_b);
			temp = *h_b;
		}
	}
}

void	div_by_bits(t_stack **h_a, t_stack **h_b, int m_bits, int m_index)
{
	t_stack	*temp;
	int		m_b;
	int		m_i;

	temp = *h_a;
	m_i = 0;
	m_b = -1;
	while (m_b + 1 < m_bits)
	{
		temp = *h_a;
		m_index = ft_stack_size(temp);
		while ((m_index) && (!is_sorted(h_a)))
		{
			m_i = temp->index;
			if ((m_i >> (m_b + 1)) & 1)
				ra(h_a);
			else
				pb(h_a, h_b);
			temp = *h_a;
			m_index--;
		}
		m_b++;
		check_and_push(h_a, h_b, m_b, m_bits);
	}
}

void	radix_sort(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		max_index;
	int		max_bits;

	max_bits = 0;
	temp = *head_a;
	max_index = ft_stack_size(temp) - 1;
	while (max_index >> max_bits)
		max_bits++;
	div_by_bits(head_a, head_b, max_bits, max_index);
}
