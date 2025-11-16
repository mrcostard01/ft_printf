/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:07:19 by wipion            #+#    #+#             */
/*   Updated: 2025/11/09 19:09:18 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft.h"

void call_base (char *s, char *c)
{
    if (c[1] == 's')
        return (ft_putstr_fd(s, 1));
    else if (c[1] == 'c')
        return (ft_putchar_fd(s[0], 1));
    else if (c[1] == 'i' || c[1] == 'd')
        return (ft_atoi(s));
    else if (c[1] == 'x')
        return (ft_hexadecimal(0, s));
    else if (c[1] == 'X')
        return (ft_hexadecimal(1, s));
    else if (c[1] == 'p')
        return (ft_pointeradress(s));
    else if (c[1] == 'u')
    {
        while(s == '-' || s == ' ' || s == '+')
            s++;
        return (ft_putstr_fd(s, 1));
    }
    else if (c[1] == '%')
        return (ft_putchar_fd('%', 1));
    else
        return ;
}

int ft_printf(const char *s, ...)
{
    va_list    argv;
    va_list    arg_copy;
    int         i;
    int         len;
    char        **operand;

    len = 0;
    va_start(argv, s);
    va_copy(arg_copy, argv);
    if (s[0] != '%')
        return (0);
    while (va_arg(arg_copy, char *) != NULL)
    {
        operand[len] = va_arg(arg_copy, char *);
        len++;
    }
    va_end(argv);
    i = 0;
    while (i < len - 1)
    {
        call_base(s,operand[i]);
        i++;
    }
    return (0);
}

