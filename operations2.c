/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:06:56 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 13:37:49 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char letter, int is_printing)
{
	if (stack && ft_stacksize(*stack) > 1)
	{
		*stack = (*stack)->next;
		if (is_printing)
			ft_printf("r%c\n", letter);
	}
}

void	ft_rr(t_stacks *stacks, int is_printing)
{
	ft_rotate(&stacks->a, 'a', 0);
	ft_rotate(&stacks->b, 'b', 0);
	if (is_printing)
		ft_printf("rr\n");
}

void	ft_rrotate(t_stack **stack, char letter, int is_printing)
{
	if (stack && ft_stacksize(*stack) > 1)
	{
		*stack = (*stack)->prev;
		if (is_printing)
			ft_printf("rr%c\n", letter);
	}
}

void	ft_rrr(t_stacks *stacks, int is_printing)
{
	ft_rrotate(&stacks->a, 'a', 0);
	ft_rrotate(&stacks->b, 'b', 0);
	if (is_printing)
		ft_printf("rrr\n");
}
