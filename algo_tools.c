/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:27:40 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 11:05:19 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(int value, t_stack *stack, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (stack->val < value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	is_max(int value, t_stack *stack, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (stack->val > value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	get_min_place(int value, t_stack *stack, int stack_size, char letter)
{
	int	i;
	int	diff;

	i = 0;
	diff = stack->val - value;
	while (i < stack_size)
	{
		if (diff > stack->val - value)
			diff = stack->val - value;
		stack = stack->next;
		i++;
	}
	i = 0;
	while (i < stack_size)
	{
		if (diff == stack->val - value)
		{
			if (letter == 'a')
				return (i);
			return (i + 1);
		}
		stack = stack->next;
		i++;
	}
	return (i + 1);
}

int	get_max_place(int value, t_stack *stack, int stack_size, char letter)
{
	int	i;
	int	diff;

	i = 0;
	diff = value - stack->val;
	while (i < stack_size)
	{
		if (diff > value - stack->val)
			diff = value - stack->val;
		stack = stack->next;
		i++;
	}
	i = 0;
	while (i < stack_size)
	{
		if (diff == value - stack->val)
		{
			if (letter == 'a')
				return (i + 1);
			return (i);
		}
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_inner_place(int value, t_stack *stack, int stack_size, char letter)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (letter == 'a')
		{
			if (value < stack->val && value > stack->prev->val)
				return (i);
		}
		else
			if (value > stack->val && value < stack->prev->val)
				return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
