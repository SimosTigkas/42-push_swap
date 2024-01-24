/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:40:31 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/24 14:28:44 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	stack_ac2(char *str)
{
	t_stack	**stack_a;
	char	**str_of_str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str_of_str = ft_split(str, ' ');
	if (str_of_str == 0)
		return (0);
	while (str_of_str[len])
		len++;
	stack_init(len, stack_a);
	while (str_of_str[i])
	{
		free(str_of_str[i]);
		i++;
	}
	free(str_of_str);
	return (stack_a);
}

int	main(int ac, char *av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	*stack_a = NULL;
	*stack_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		stack_a = stack_ac2(av[1]);
	else
		stack_a = stack_init(ac - 1, &av[1]);
	free(stack_a);
	free(stack_b);
	//More_to_be_done_here(?)
	return (0);
}
