/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:03:00 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/10 15:07:23 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_double_newline(char *op_list_str)
{
	int	i;

	i = 0;
	while (op_list_str[i])
	{
		if (op_list_str[i] == '\n' && op_list_str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	init_variables(int *str_len, int *read_val, char *buf,
	char **op_list_str)
{
	*str_len = 1;
	*read_val = read(0, buf, READ_SIZE);
	*op_list_str = malloc(sizeof(char));
	if (!(*op_list_str))
		return (0);
	return (1);
}

char	**get_op_list(void)
{
	char	buf[READ_SIZE + 1];
	char	*op_list_str;
	char	**op_list;
	int		read_val;
	int		str_len;

	if (!init_variables(&str_len, &read_val, buf, &op_list_str))
		return (NULL);
	op_list_str[0] = '\0';
	while (read_val > 0)
	{
		buf[read_val] = '\0';
		op_list_str = ft_realloc(op_list_str, str_len, str_len + read_val);
		if (!op_list_str)
			return (NULL);
		str_len += read_val;
		ft_strlcat(op_list_str, buf, str_len);
		read_val = read(0, buf, READ_SIZE);
	}
	if (!check_double_newline(op_list_str))
		return (free(op_list_str), NULL);
	op_list = ft_split(op_list_str, '\n');
	if (!op_list)
		return (free(op_list_str), NULL);
	return (free(op_list_str), op_list);
}

int	make_an_operation(t_stacks *stacks, char *operation)
{
	if (ft_strncmp(operation, "sa", 10) == 0)
		ft_swap(&stacks->a, 'a', 0);
	else if (ft_strncmp(operation, "sb", 10) == 0)
		ft_swap(&stacks->b, 'b', 0);
	else if (ft_strncmp(operation, "ss", 10) == 0)
		ft_ss(stacks, 0);
	else if (ft_strncmp(operation, "ra", 10) == 0)
		ft_rotate(&stacks->a, 'a', 0);
	else if (ft_strncmp(operation, "rb", 10) == 0)
		ft_rotate(&stacks->b, 'b', 0);
	else if (ft_strncmp(operation, "rr", 10) == 0)
		ft_rr(stacks, 0);
	else if (ft_strncmp(operation, "rra", 10) == 0)
		ft_rrotate(&stacks->a, 'a', 0);
	else if (ft_strncmp(operation, "rrb", 10) == 0)
		ft_rrotate(&stacks->b, 'b', 0);
	else if (ft_strncmp(operation, "rrr", 10) == 0)
		ft_rrr(stacks, 0);
	else if (ft_strncmp(operation, "pa", 10) == 0)
		ft_push_a(stacks, 0);
	else if (ft_strncmp(operation, "pb", 10) == 0)
		ft_push_b(stacks, 0);
	else
		return (0);
	return (1);
}
