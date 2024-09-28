/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:52:19 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/11 10:35:59 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(const char *nptr)
{
	long	nbr;
	int		indexes[2];
	int		sign;

	nbr = 0;
	indexes[0] = 0;
	indexes[1] = 0;
	sign = 1;
	if (nptr[indexes[0]] == '+' || nptr[indexes[0]] == '-')
		if (!nptr[indexes[0] + 1])
			return (0);
	if (nptr[indexes[0]] == '+' || nptr[indexes[0]] == '-')
		if (nptr[indexes[0]++] == '-')
			sign = -1;
	while (nptr[indexes[0]] == '0')
		indexes[0]++;
	while (nptr[indexes[0]] >= '0' && nptr[indexes[0]] <= '9')
	{
		nbr = nbr * 10 + nptr[indexes[0]++] - '0';
		indexes[1]++;
	}
	if (nptr[indexes[0]] || indexes[1] > 10 || nbr * sign > 2147483647
		|| nbr * sign < -2147483648)
		return (0);
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	check_double_arg(t_stack *stack, int nb)
{
	int	i;
	int	size;

	i = 0;
	size = ft_stacksize(stack);
	while (i < size)
	{
		if (stack->val == nb)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
