/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:31:20 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 13:38:51 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_stack_in_final_order(t_stacks *stacks)
{
	int		i;
	int		smallest;
	int		smallest_index;
	t_stack	*stack_a;

	i = 0;
	smallest = 2147483647;
	stack_a = stacks->a;
	while (i < ft_stacksize(stack_a))
	{
		if (stack_a->val < smallest)
		{
			smallest = stack_a->val;
			smallest_index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	if (smallest_index <= ft_stacksize(stacks->a) / 2)
		while (stacks->a->val != smallest)
			ft_rotate(&stacks->a, 'a', 1);
	else
		while (stacks->a->val != smallest)
			ft_rrotate(&stacks->a, 'a', 1);
}

void	sort_three(t_stacks *stacks)
{
	if (is_stack_sorted(stacks->a))
		return ;
	else if (is_stack_sorted(stacks->a->next))
		ft_rotate(&stacks->a, 'a', 1);
	else if (is_stack_sorted(stacks->a->prev))
		ft_rrotate(&stacks->a, 'a', 1);
	else
	{
		ft_swap(&stacks->a, 'a', 1);
		if (is_stack_sorted(stacks->a))
			return ;
		else if (is_stack_sorted(stacks->a->next))
			ft_rotate(&stacks->a, 'a', 1);
		else if (is_stack_sorted(stacks->a->prev))
			ft_rrotate(&stacks->a, 'a', 1);
	}
}

void	sort_stack(t_stacks *stacks)
{
	int				i;
	int				sizes[2];
	t_operations	op;

	ft_push_b(stacks, 1);
	ft_push_b(stacks, 1);
	i = 0;
	sizes[0] = ft_stacksize(stacks->a);
	while (i++ < sizes[0] - 3)
		calculate_and_operate_to_b(stacks, &op);
	sort_three(stacks);
	i = 0;
	sizes[1] = ft_stacksize(stacks->b);
	while (i++ < sizes[1])
		calculate_and_operate_to_a(stacks, &op);
	put_stack_in_final_order(stacks);
}
