/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:28:32 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 15:11:05 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*get_args_stack(int argc, char **argv)
{
	char	*args_str;
	char	**args_tab;

	args_str = ft_strjoin_argv(argc, argv, " ");
	if (!args_str)
		return (NULL);
	args_tab = ft_split(args_str, ' ');
	if (!args_tab)
		return (free(args_str), NULL);
	return (free(args_str), tab_to_stack(args_tab));
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc <= 1)
		return (0);
	stacks.a = get_args_stack(argc, argv);
	if (!stacks.a)
		return (ft_putstr_fd("Error\n", 2), 1);
	stacks.b = NULL;
	if (ft_stacksize(stacks.a) == 2)
	{
		if (stacks.a->val > stacks.a->next->val)
			ft_swap(&stacks.a, 'a', 1);
	}
	else if (ft_stacksize(stacks.a) == 3)
		sort_three(&stacks);
	else if (!is_stack_sorted(stacks.a))
		sort_stack(&stacks);
	ft_stackclear(&stacks.a);
	ft_stackclear(&stacks.b);
	return (0);
}
