/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
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

typedef void (*func_va_t)(va_list);
struct s_flag{
char element;
 func_va_t f;
struct s_flag *next;
};
typedef struct s_flag t_flag;

char    *ft_hexadecimal(int a, int nb);
void     ft_pointeradress(void *p);
int    ft_printf(const char *s, ...);
#endif
