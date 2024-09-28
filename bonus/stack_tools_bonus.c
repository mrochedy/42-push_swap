/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:22:23 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 14:18:17 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackadd(t_stack **stack, t_stack *new, int is_front)
{
	if (!stack || !new)
		return ;
	if (*stack)
	{
		if ((*stack)->next)
		{
			new->next = *stack;
			new->prev = (*stack)->prev;
			(*stack)->prev->next = new;
			(*stack)->prev = new;
		}
		else
		{
			new->next = *stack;
			new->prev = *stack;
			(*stack)->next = new;
			(*stack)->prev = new;
		}
		if (is_front)
			*stack = new;
	}
	else
		*stack = new;
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*first;

	if (!stack)
		return (0);
	first = stack;
	stack = stack->next;
	i = 1;
	while (stack && stack != first)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*next;
	int		size;
	int		i;

	if (stack)
	{
		i = 0;
		size = ft_stacksize(*stack);
		while (i < size)
		{
			next = (*stack)->next;
			free(*stack);
			*stack = next;
			i++;
		}
		*stack = NULL;
	}
}

void	ft_stackreset(t_stack *stack)
{
	stack->next = NULL;
	stack->prev = NULL;
}
