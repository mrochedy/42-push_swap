/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:40 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 14:07:30 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_operations;

char	*ft_strjoin_argv(int argc, char **argv, char *sep);
int		check_double_arg(t_stack *stack, int nb);
t_stack	*ft_stacknew(int value);
void	ft_stackadd(t_stack **stack, t_stack *new, int is_front);
int		ft_stacksize(t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	ft_stackreset(t_stack *stack);
int		ft_atoi_check(const char *nptr);
void	free_array(char **array);
void	ft_swap(t_stack **stack, char letter, int is_printing);
void	ft_ss(t_stacks *stacks, int is_printing);
void	ft_push_a(t_stacks *stacks, int is_printing);
void	ft_push_b(t_stacks *stacks, int is_printing);
void	ft_rotate(t_stack **stack, char letter, int is_printing);
void	ft_rr(t_stacks *stacks, int is_printing);
void	ft_rrotate(t_stack **stack, char letter, int is_printing);
void	ft_rrr(t_stacks *stacks, int is_printing);
void	ft_print_stacks(t_stacks *stacks);
int		is_min(int value, t_stack *stack, int stack_size);
int		is_max(int value, t_stack *stack, int stack_size);
int		get_min_place(int value, t_stack *stack, int stack_size, char letter);
int		get_max_place(int value, t_stack *stack, int stack_size, char letter);
int		get_inner_place(int value, t_stack *stack, int stack_size, char letter);
void	handle_double_operations(t_operations *op);
void	handle_reverse_operations(t_operations *op, int size_a, int size_b);
void	update_new_best(t_operations *best, t_operations *current);
void	sort_stack(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
int		is_stack_sorted(t_stack *stack);
void	calculate_and_operate_to_b(t_stacks *stacks, t_operations *op);
void	calculate_and_operate_to_a(t_stacks *stacks, t_operations *op);

#endif
