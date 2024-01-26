/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:56:09 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/15 15:41:34 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (s == NULL)
	{
		c = h(c, ft_putstr_fd("(null)", 1));
		if (c == -1)
			return (-1);
		return (6);
	}
	while (*s)
	{
		c = h(c, write(fd, s, 1));
		if (c == -1)
			return (-1);
		s++;
	}
	return (c);
}
