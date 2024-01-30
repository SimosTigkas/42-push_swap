/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:40:31 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/30 15:57:13 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copy_av(int ac, char **av)
{
	int		i;
	int		j;
	char	*str_str;

	i = 0;
	j = 1;
	strs = malloc(ac * sizeof(int));
	if (strs == 0)
		return (0);
	while (i < (ac - 1))
	{
		strs[i] = strs[j];
		i++;
		j++;
	}
	return (strs);
}

int	syntax_check(char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		if (strs[i][j] == '-')
			j++;
		while (strs[i][j])
		{
			if (strs[i][j] >= '0' || strs[i][j] <= '9')
				j++;
			else
				return (-1);
		}
		i++;
		j = 0;
	}
	return (0);
}

char	**split_copy_av(int ac, char **av)
{
	char	**strs;

	if (ac == 2)
	{
		strs = ft_split(str, ' ');
		if (strs[0] == 0)
		{
			free(strs);
			return (0);
		}
		if (strs == 0 || syntax_check(strs) < 0)
			return (0);
	}
	else
	{
		strs = copy_av(av, ac);
		if (strs == 0 || syntax_check(strs) < 0)
			return (0);
	}
	return (strs);
}

int	main(int ac, char *av[])
{
	char	**strs;
	t_stack	*headstack_a;
	t_stack	*headstack_b;

	headstack_a = (t_stack *)malloc(sizeof(t_stack));
	headstack_b = (t_stack *)malloc(sizeof(t_stack));
	*headstack_a = NULL;
	*headstack_b = NULL;
	if (!ac)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ac == 1 || (ac == 2 && av[1][0] == 0))
		return (0);
	strs = split_copy_av(ac, av);
	get_the_stack(strs, headstack_a, headstack_b, ac);
	return (0);
}
