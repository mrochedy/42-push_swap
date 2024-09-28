/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:42:59 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 15:02:58 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**op_list;
	int			i;

	if (argc <= 1)
		return (0);
	stacks.a = get_args_stack(argc, argv);
	if (!stacks.a)
		return (ft_putstr_fd("Error\n", 2), 1);
	stacks.b = NULL;
	op_list = get_op_list();
	if (!op_list)
		return (ft_stackclear(&stacks.a), ft_putstr_fd("Error\n", 2), 1);
	i = 0;
	while (op_list[i])
		if (!make_an_operation(&stacks, op_list[i++]))
			return (ft_stackclear(&stacks.a), ft_stackclear(&stacks.b),
				free_array(op_list), ft_putstr_fd("Error\n", 2), 1);
	if (is_stack_sorted(stacks.a) && !stacks.b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(&stacks.a);
	ft_stackclear(&stacks.b);
	return (free_array(op_list), 0);
}
