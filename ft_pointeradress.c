/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeradress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:31:22 by wipion            #+#    #+#             */
/*   Updated: 2025/11/28 18:31:29 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

char  *ft_pointeradress(va_list infos)
{
    char    *str;
	void	*p;

	p = va_arg(infos, void *);
	if (p == NULL)
		return (ft_strdup("(nil)"));
    str = ft_unsigned_int_to_char((unsigned long long)p, "0123456789abcdef");
    return (str);
}
