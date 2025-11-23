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
#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

// print an integer
int ft_printf_integer (va_list infos)
{
	char *value;

	value = ft_itoa((int)va_arg(infos, int));
	ft_putstr_fd(value, 1);
	return (ft_strlen(value));
}
//print positive integer
int ft_printf_unsigned_int (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	if ( value >= 0)
		ft_putnbr_fd(value, 1);
	else
		return;
}
//print a single caracter
int ft_printf_char (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	ft_putchar_fd(value, 1);
}
//print a string
int ft_printf_string (va_list infos)
{
	char *value;

	value = (char *)va_arg(infos, char *);
	if (value[0] == '\0')
	{
		ft_putchar_fd(value[0], 1);
		return ;
	}
	ft_putstr_fd(value, 1);
	return (ft_strlen(value));
}
//print hexadecimal in lowcase
int ft_printf_hexadecimallow (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	ft_putstr_fd(ft_hexadecimal(0,value), 1);
}
//printf hexadecimal upcase
int ft_printf_hexadecimalup (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	ft_putstr_fd(ft_hexadecimal(1,value), 1);
}
//print poiter's address
int ft_printf_pointer (va_list infos)
{
	ft_pointeradress(infos);
}
//display a percent
int ft_printf_percent(va_list infos)
{
	(void)infos;
	ft_putchar_fd('%', 1);
}
// initialize the list
t_flag *init_flag(int element, func_va_t f)
{
	t_flag *flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (flag == NULL)
		return (NULL);
	flag->element = element;
	flag->f = f;
	flag->next = NULL;
	return (flag);
}
// make a new node
int add_flag(t_flag *root, int element, func_va_t f)
{
	t_flag *flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (flag == NULL)
		return (-1);
	while (root->next != NULL)
		root = root->next;
	root->next = flag;
	flag->next = NULL;
	flag->f = f;
	flag->element = element;
	return (0);
}
// fill the first node
int start_printf_function(t_flag *root, char c, va_list infos)
{
	t_flag *flag;

	flag = root;
	while (flag != NULL)
		{
			if (flag->element == c) {
				flag->f(infos);
				return (1);
			}
			flag = flag->next;
		}
	return (0);
}
// free everything in the list
void end_printf_function(t_flag *root)
{
	t_flag *tmp;

    while (root != NULL)
    {
        tmp = root->next;
        free(root);         
        root = tmp;         
    }
}

// main function
int ft_printf(const char *s, ...)
{
	t_flag *root;
	va_list infos;

	int i;
	int result;
	va_start(infos, s);

	root = init_flag('c', &ft_printf_char);
	add_flag(root, 'd', &ft_printf_integer);
	add_flag(root, 'i', &ft_printf_integer);
	add_flag(root, 's', &ft_printf_string);
	add_flag(root, 'x', &ft_printf_hexadecimallow);
	add_flag(root, 'X', &ft_printf_hexadecimalup);
	add_flag(root, 'p', &ft_printf_pointer);
	add_flag(root, 'u', &ft_printf_unsigned_int);
	add_flag(root, '%', &ft_printf_percent);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			{
				if (s[i + 1] == '\0')
					break ;
				result = start_printf_function(root, s[i + 1], infos);
				if (result == 0)
					ft_putchar_fd(s[i+1], 1);
				i++;
			}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	end_printf_function(root);
	va_end(infos);
	return (i);
}/*
int	main()
{
		ft_printf("%X %X", 186456, 18644564556);
}*/