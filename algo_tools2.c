/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:21:41 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/09 18:23:03 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_double_operations(t_operations *op)
{
	if (op->ra < op->rb)
	{
		op->rr = op->ra;
		op->rb -= op->ra;
		op->ra = 0;
	}
	else
	{
		op->rr = op->rb;
		op->ra -= op->rb;
		op->rb = 0;
	}
	if (op->rra < op->rrb)
	{
		op->rrr = op->rra;
		op->rrb -= op->rra;
		op->rra = 0;
	}
	else
	{
		op->rrr = op->rrb;
		op->rra -= op->rrb;
		op->rrb = 0;
	}
	op->total = op->ra + op->rb + op->rr + op->rra + op->rrb + op->rrr + 1;
}

void	handle_reverse_operations(t_operations *op, int size_a, int size_b)
{
	if (op->ra > size_a / 2)
	{
		op->rra = size_a - op->ra;
		op->ra = 0;
	}
	else
		op->rra = 0;
	if (op->rb > size_b / 2)
	{
		op->rrb = size_b - op->rb;
		op->rb = 0;
	}
	else
		op->rrb = 0;
}

void	update_new_best(t_operations *best, t_operations *current)
{
	if (current->total < best->total)
	{
		best->ra = current->ra;
		best->rb = current->rb;
		best->rr = current->rr;
		best->rra = current->rra;
		best->rrb = current->rrb;
		best->rrr = current->rrr;
		best->total = current->total;
	}
}
