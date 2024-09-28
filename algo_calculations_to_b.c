/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_calculations_to_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:42:00 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 13:39:29 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cheapest_op_to_b(t_stack *stack_a, t_stack *stack_b,
	int *sizes, t_operations *best)
{
	int				i;
	t_operations	current;

	i = 0;
	while (i < sizes[0])
	{
		if (is_min(stack_a->val, stack_b, sizes[1]))
			current.rb = get_min_place(stack_a->val, stack_b, sizes[1], 'b');
		else if (is_max(stack_a->val, stack_b, sizes[1]))
			current.rb = get_max_place(stack_a->val, stack_b, sizes[1], 'b');
		else
			current.rb = get_inner_place(stack_a->val, stack_b, sizes[1], 'b');
		current.ra = i;
		handle_reverse_operations(&current, sizes[0], sizes[1]);
		handle_double_operations(&current);
		update_new_best(best, &current);
		stack_a = stack_a->next;
		i++;
	}
}

/*
	sizes[0] = size_a;
	sizes[1] = size_b;
*/

void	calculate_to_b(t_stacks *stacks, t_operations *op)
{
	int		sizes[2];
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stacks->a;
	stack_b = stacks->b;
	sizes[0] = ft_stacksize(stack_a);
	sizes[1] = ft_stacksize(stack_b);
	get_cheapest_op_to_b(stack_a, stack_b, sizes, op);
}

void	calculate_and_operate_to_b(t_stacks *stacks,
	t_operations *op)
{
	int	j;

	j = 0;
	op->total = 1000000000;
	calculate_to_b(stacks, op);
	j = 0;
	while (j++ < op->rr)
		ft_rr(stacks, 1);
	j = 0;
	while (j++ < op->rrr)
		ft_rrr(stacks, 1);
	j = 0;
	while (j++ < op->ra)
		ft_rotate(&stacks->a, 'a', 1);
	j = 0;
	while (j++ < op->rra)
		ft_rrotate(&stacks->a, 'a', 1);
	j = 0;
	while (j++ < op->rb)
		ft_rotate(&stacks->b, 'b', 1);
	j = 0;
	while (j++ < op->rrb)
		ft_rrotate(&stacks->b, 'b', 1);
	ft_push_b(stacks, 1);
}
