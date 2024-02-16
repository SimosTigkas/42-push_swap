/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_of_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:46:31 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/16 08:57:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_int(char **args, int counter)
{
	int		i;
	int		number;
	char	**nums;
	int		arg_len;

	i = 0;
	number = 0;
	nums = (char **)malloc((counter + 1) * sizeof(char **));
	if (!nums)
		return (0);
	while (i < counter)
	{
		number = ft_atoi(args[i]);
		nums[i] = ft_itoa(number);
		arg_len = ft_strlen(args[i]);
		if (ft_strncmp(args[i], nums[i], arg_len) != 0)
		{
			ft_free(nums, i);
			return (0);
		}
		else
			i++;
	}
	ft_free(nums, i - 1);
	return (1);
}

int	is_digit(char **args, int counter)
{
	int	is_valid;
	int	i;
	int	j;

	i = 0;
	j = 0;
	is_valid = 1;
	while (i < counter)
	{
		while (args[i][j])
		{
			is_valid = ft_isdigit(args[i][j]);
			if ((!is_valid) && args[i][j] != '-' \
				&& (ft_isdigit(args[i][j] != 1)))
				return (0);
			if (j > 11)
				return (0);
			j++;
		}
		i++;
	}
	return (is_valid);
}

int	is_duplicated(char **args, int counter)
{
	int	is_valid;
	int	arg_len;
	int	i;
	int	j;

	is_valid = 1;
	i = 0;
	while ((i < counter - 1) && (is_valid))
	{
		j = i + 1;
		while ((j < counter) && (is_valid != 0))
		{
			if (ft_strlen(args[i]) == ft_strlen(args[j]))
			{
				arg_len = ft_strlen(args[i]);
				if (ft_strncmp(args[i], args[j], arg_len) == 0)
					is_valid = 0;
			}
			j++;
		}
		i++;
	}
	return (is_valid);
}

int	in_asc_order(char **args, int counter)
{
	int	i;

	i = 0;
	while (i + 1 < counter)
	{
		if (ft_atoi(args[i]) < ft_atoi(args[i + 1]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	validity_of_args(char **args, int counter)
{
	int		is_valid;

	is_valid = 1;
	is_valid = is_digit(args, counter);
	if (!is_valid)
		return (0);
	is_valid = is_duplicated(args, counter);
	if (!is_valid)
		return (0);
	is_valid = is_int(args, counter);
	if (!is_valid)
		return (0);
	is_valid = in_asc_order(args, counter);
	if (!is_valid)
		return (0);
	return (is_valid);
}
