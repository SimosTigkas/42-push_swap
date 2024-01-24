/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:07:55 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/24 14:29:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int len, char **str_of_str)
{
	t_stack	*stack;
	t_stack	*node;
	int		*chunks;
	int		i;

	i = 0;
	chunks = str_to_chunks(len, str_of_str); //function_to_build_tomorrow
	if (chunks == 0)
		return ;
	stack = NULL;
	while (i < len)
	{
		node = ft_stacknew(chunks[i]);
		if (node == NULL)
		{
			free(chunks);
			ft_stackclear(stack);
			free(stack);
		}
		ft_stackadd_back(&stack, node);
		i++;
	}
	free(chunks);
	return (stuck);
}
