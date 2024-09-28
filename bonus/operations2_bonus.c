/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:06:56 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 14:20:58 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
