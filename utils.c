/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:14:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/30 16:01:45 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	get_the_stack(char **strs, t_stack **stack_a, t_stack **stack_b, int ac)
{
	int	iscreated;

	iscreated = create_stack(strs, stack_a);
	if (iscreated)
	{
		write(2, "Error\n", 6);
		free(strs);
		ft_stackclear(stack_a);
		exit(0);
	}
}

int	create_stack(char **strs, t_stack **stack_a)
{
	t_stack	*node;
	int		nbr;
	int		i;

	node = NULL;
	*stack_a = NULL;
	nbr = 0;
	i = 0;
	while (strs[i])
	{
		nbr = ft_atoi(&strs[i][0]);
		if (is_duplicated(stack_a, nbr))
			return (1);
		node = ft_stacknew(nbr);
		if (node == NULL)
			return (1);
		ft_stackadd_back(stack_a, node);
		i++;
	}
	index_the_stack(stack_a);
	return (0);
}

int	is_duplicated(t_stack **stack_a, int nbr)
{
	t_stack	*current;

	current = (*stack_a);
	if (!current)
		return (0);
	while (current)
	{
		if (current->data == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
