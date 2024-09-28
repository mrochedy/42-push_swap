/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:37:17 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 13:37:05 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char letter, int is_printing)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = first->prev;
	second = first->next;
	third = second->next;
	if (ft_stacksize(*stack) != 2)
	{
		last->next = second;
		third->prev = first;
		first->prev = second;
		first->next = third;
		second->prev = last;
		second->next = first;
	}
	*stack = second;
	if (is_printing)
		ft_printf("s%c\n", letter);
}

void	ft_ss(t_stacks *stacks, int is_printing)
{
	ft_swap(&stacks->a, 'a', 0);
	ft_swap(&stacks->b, 'b', 0);
	if (is_printing)
		ft_printf("ss\n");
}

void	ft_push_a(t_stacks *stacks, int is_printing)
{
	t_stack	*b_last;
	t_stack	*b_first;
	t_stack	*b_second;

	if (!stacks->b)
		return ;
	b_first = stacks->b;
	b_last = b_first->prev;
	b_second = b_first->next;
	if (ft_stacksize(stacks->b) == 2)
	{
		b_second->next = NULL;
		b_second->prev = NULL;
	}
	else if (ft_stacksize(stacks->b) != 1)
	{
		b_last->next = b_second;
		b_second->prev = b_last;
	}
	stacks->b = b_second;
	ft_stackreset(b_first);
	ft_stackadd(&stacks->a, b_first, 1);
	if (is_printing)
		ft_printf("pa\n");
}

void	ft_push_b(t_stacks *stacks, int is_printing)
{
	t_stack	*a_last;
	t_stack	*a_first;
	t_stack	*a_second;

	if (!stacks->a)
		return ;
	a_first = stacks->a;
	a_last = a_first->prev;
	a_second = a_first->next;
	if (ft_stacksize(stacks->a) == 2)
	{
		a_second->next = NULL;
		a_second->prev = NULL;
	}
	else if (ft_stacksize(stacks->a) != 1)
	{
		a_last->next = a_second;
		a_second->prev = a_last;
	}
	stacks->a = a_second;
	ft_stackreset(a_first);
	ft_stackadd(&stacks->b, a_first, 1);
	if (is_printing)
		ft_printf("pb\n");
}
