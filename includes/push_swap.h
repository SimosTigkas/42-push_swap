/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:42:10 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/30 15:48:15 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}				t_stack;

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
int		ft_stack_size(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*stack_init(int len, char **str_of_str);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stacknew(int *data);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_strcmp(char *s1, char *s2);
char	**split_copy_av(int ac, char **av);
int		syntax_check(char **str_of_str);
char	**copy_av(int ac, char **av);
int		is_duplicated(t_stack **stack_a, int nbr);
void	index_the_stack(t_stack **stack);


#endif