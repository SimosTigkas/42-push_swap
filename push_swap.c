/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:40:31 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/07 14:11:37 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	get_the_stack(t_stack **head_a, int ac, char *av[])
{
	t_stack	*node;
	char	**args;
	int		i;
	int		nbr;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		node = ft_stacknew(nbr);
		ft_stackadd_back(head_a, node);
		i++;
	}
	index_the_stack(head_a);
	if (ac == 2)
		ft_free(args);
}

void	sort_the_stack(t_stack **head_a, t_stack **head_b)
{
	if (ft_stack_size(*head_a) <= 5)
		small_sort(head_a, head_b);
	else
		radix_sort(head_a, head_b);
}

int	is_sorted(t_stack **head_a)
{
	t_stack	*temp;

	temp = *head_a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_stack	**head_a;
	t_stack	**head_b;

	head_a = (t_stack **)malloc(sizeof(t_stack));
	head_b = (t_stack **)malloc(sizeof(t_stack));
	*head_a = NULL;
	*head_b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == 0))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	validity_of_args(ac, av);
	get_the_stack(head_a, ac, av);
	if (is_sorted(head_a))
	{
		free_stack(head_a);
		free_stack(head_b);
		return (0);
	}
	sort_the_stack(head_a, head_b);
	free_stack(head_a);
	free_stack(head_b);
	return (0);
}
