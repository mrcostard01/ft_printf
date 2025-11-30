/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:24:43 by wipion            #+#    #+#             */
/*   Updated: 2025/11/06 17:12:48 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"



typedef int (*func_va_t)(va_list);
struct s_flag{
	char element;
	func_va_t f;
struct s_flag *next;
};
typedef struct s_flag t_flag;
char	*ft_pointeradress(va_list infos);
int		add_flag(t_flag *root, int element, func_va_t f);
void	*call_flag(void);
void *call_flag2(t_flag *root);
int ft_printf_char (va_list infos);
int ft_printf_integer (va_list infos);
int ft_printf_unsigned_int (va_list infos);
int ft_printf_string (va_list infos);
t_flag *init_flag(int element, func_va_t f);
int		ft_printf(const char *s, ...);
#endif
