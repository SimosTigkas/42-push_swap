/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:52:21 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/08 16:28:55 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*node;

	if (stack == NULL)
		return (NULL);
	node = stack;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*node;

	if (!stack || !new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = new;
}

t_stack	*ft_stacknew(int v)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = v;
	node->next = NULL;
	return (node);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	if (!(stack))
		return ;
	node = *stack;
	while (node)
	{
		next = (*stack)->next;
		free(node);
		node = next;
	}
	*stack = NULL;
}
