/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:14:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/16 08:56:53 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	ft_free(char **args, int counter)
{
	int	i;

	i = 0;
	while (i <= counter)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	num_count(char *str)
{
	int		nums;
	char	c;

	nums = 0;
	c = ' ';
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			while ((*str != c) && (*str))
				str++;
			nums++;
		}
	}
	return (nums);
}

char	**args_array(char **av, int counter)
{
	char	**args;
	int		i;

	i = 0;
	args = (char **)malloc((counter + 1) * sizeof(char **));
	if (!args)
		return (NULL);
	while (i < counter)
	{
		args[i] = ft_strdup(av[1 + i]);
		if (!args[i])
		{
			ft_free(args, i);
			return (NULL);
		}
		i++;
	}
	args[counter] = 0;
	return (args);
}

t_stack	*create_stack(t_stack **stack, char **args, int counter)
{
	t_stack	*new;
	long	num;
	int		i;

	i = 0;
	stack = NULL;
	new = NULL;
	num = ft_atoi(args[i]);
	new = ft_stacknew(num);
	if (!new)
		return (NULL);
	stack = &new;
	i++;
	while (i <= counter)
	{
		num = ft_atoi(args[i]);
		if (!new)
			return (NULL);
		ft_stackadd_back(stack, ft_stacknew(num));
		i++;
	}
	return (new);
}
