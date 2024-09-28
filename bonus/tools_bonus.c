/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:18 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/11 10:48:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*tab_to_stack(char **args_tab)
{
	t_stack	*args_stack;
	t_stack	*new;
	int		i;
	int		nbr;

	i = 0;
	while (args_tab[i])
		if (!ft_atoi_check(args_tab[i++]))
			return (free_array(args_tab), NULL);
	i = 0;
	args_stack = NULL;
	while (args_tab[i])
	{
		nbr = ft_atoi(args_tab[i++]);
		if (!check_double_arg(args_stack, nbr))
			return (ft_stackclear(&args_stack), free_array(args_tab), NULL);
		new = ft_stacknew(nbr);
		if (!new)
			return (ft_stackclear(&args_stack), free_array(args_tab), NULL);
		ft_stackadd(&args_stack, new, 0);
	}
	return (free_array(args_tab), args_stack);
}

int	is_stack_sorted(t_stack *stack)
{
	int	i;
	int	stack_size;

	i = 0;
	stack_size = ft_stacksize(stack);
	while (i < stack_size - 1)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
