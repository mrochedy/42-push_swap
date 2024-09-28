/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:59:40 by mrochedy          #+#    #+#             */
/*   Updated: 2024/05/21 13:37:51 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

/*
int	main(void)
{
	ft_putstr_fd("TEST\n", 0);
	ft_putstr_fd("Everything is fine!\n", 1);
	ft_putstr_fd("An error occured...\n", 2);
	return (0);
}
*/
