/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_of_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:46:31 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/08 17:29:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_duplicated(int nbr, char **args, int i)
{
	while (args[i])
	{
		if (ft_atoi(args[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
}

void	validity_of_args(int ac, char *av[])
{
	int		i;
	long	temp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i++;
		args = av;
	}
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (ft_isalpha(temp))
			ft_error("Error");
		if (is_duplicated(temp, args, i))
			ft_error("Error");
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
