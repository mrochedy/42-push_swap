/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:45:15 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 15:06:09 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define READ_SIZE 64

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

char	*ft_strjoin_argv(int argc, char **argv, char *sep);
t_stack	*tab_to_stack(char **args_tab);
char	**get_op_list(void);
int		make_an_operation(t_stacks *stacks, char *operation);
int		is_stack_sorted(t_stack *stack);
int		ft_atoi_check(const char *nptr);
int		check_double_arg(t_stack *stack, int nb);
void	free_array(char **array);
t_stack	*ft_stacknew(int value);
void	ft_stackadd(t_stack **stack, t_stack *new, int is_front);
int		ft_stacksize(t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	ft_stackreset(t_stack *stack);
void	ft_swap(t_stack **stack, char letter, int is_printing);
void	ft_ss(t_stacks *stacks, int is_printing);
void	ft_push_a(t_stacks *stacks, int is_printing);
void	ft_push_b(t_stacks *stacks, int is_printing);
void	ft_rotate(t_stack **stack, char letter, int is_printing);
void	ft_rr(t_stacks *stacks, int is_printing);
void	ft_rrotate(t_stack **stack, char letter, int is_printing);
void	ft_rrr(t_stacks *stacks, int is_printing);

#endif
