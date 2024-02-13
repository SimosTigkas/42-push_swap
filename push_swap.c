/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:40:31 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/13 18:29:46 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

t_stack	*init_list(int ac, char **av)
{
	t_stack	*node;
	char	**args;
	int		counter;
	int		is_valid;

	counter = ac - 1;
	node = NULL;
	is_valid = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		write(1, "heeereee", 8);
		counter = num_count(av[1]);
	}
	else
		args = args_array(av, counter);
	if (!args)
		return (NULL);
	is_valid = validity_of_args(args, counter);
	if (is_valid != 1)
	{
		ft_error("Error");
		ft_free(args, counter);
		return (NULL);
	}
	node = create_stack(&node, args, counter - 1);
	ft_free(args, counter - 1);
	return (node);
}

void	sort_the_stack(t_stack **head_a, t_stack **head_b)
{
	int	counter;

	counter = ft_stack_size(*head_a);
	if ((counter >= 2) && (counter <= 5))
		small_sort(head_a, head_b);
	else if (counter > 5)
		radix_sort(head_a, head_b);
	else
		return ;
}

int	is_sorted(t_stack **head_a)
{
	t_stack	*temp;

	temp = *head_a;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = NULL;
	if (ac < 2)
		return (0);
	head_a = init_list(ac, av);
	write(1, &"Here too", 8);
	if (!(head_a))
		return (0);
	index_the_stack(&head_a);
	if (is_sorted(&head_a))
		return (0);
	sort_the_stack(&head_a, &head_b); //here
	free_stack(head_a);
	free_stack(head_b);
	return (0);
}
