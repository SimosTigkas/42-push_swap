/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:42:10 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/13 18:29:28 by stigkas          ###   ########.fr       */
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
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stacknew(int v);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		validity_of_args(char **args, int counter);
void	sort_the_stack(t_stack **head_a, t_stack **head_b);
t_stack	*init_list(int ac, char **av);
t_stack	*create_stack(t_stack **stack, char **args, int counter);
int		is_duplicated(char **args, int counter);
void	index_the_stack(t_stack **stack);
void	ft_error(char *str);
void	ft_free(char **args, int counter);
void	free_stack(t_stack *stack);
void	small_sort(t_stack **head_a, t_stack **head_b);
int		is_sorted(t_stack **head_a);
int		is_digit(char **args, int counter);
t_stack	*getthe_next_min(t_stack **stack);
int		is_min(t_stack **stack, int nbr);
void	sort_3(t_stack **head_a);
void	sort_4(t_stack **head_a, t_stack **head_b);
void	sort_5(t_stack **head_a, t_stack **head_b);
int		get_distance(t_stack **head_a, int index);
void	radix_sort(t_stack **head_a, t_stack **head_b);
void	div_by_bits(t_stack **h_a, t_stack **h_b, int m_bits, int m_index);
void	check_and_push(t_stack **h_a, t_stack **h_b, int m_b, int m_bits);
int		num_count(char *str);
char	**args_array(char **av, int counter);

#endif