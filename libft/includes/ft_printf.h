/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:04:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/07/03 12:10:23 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define MALLOC_SIZE 64

typedef struct s_print
{
	int		size;
	char	*str;
}	t_print;

int	add_to_print(va_list *args_list, const char *str, int *i,
		t_print *to_print);
int	add_char(char c, t_print *to_print);
int	add_str(char *str, t_print *to_print);
int	add_nbr(int nbr, t_print *to_print);
int	add_nbr_base(unsigned int nbr, char *base, t_print *to_print);
int	add_addr(unsigned long addr, char *hex, t_print *to_print);
int	deal_with_plus(va_list *args_list, const char *str,
		int *i, t_print *to_print);
int	deal_with_space(va_list *args_list, const char *str,
		int *i, t_print *to_print);
int	deal_with_hash(va_list *args_list, const char *str,
		int *i, t_print *to_print);

#endif
