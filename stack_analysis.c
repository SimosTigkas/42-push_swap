/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:52:21 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/23 10:59:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*ptr;

	size = 0;
	if (stack == NULL)
		return (0);
	ptr = stack;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
