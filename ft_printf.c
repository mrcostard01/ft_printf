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
#include "ft_printf.h"
#include "libft/libft.h"

// print an integer
void ft_printf_integer (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	ft_putnbr_fd(value, 1);
}
//print a single caracter
void ft_printf_char (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	ft_putchar_fd(value, 1);
}
// initialize the list
t_flag *init_flag(int element, void (*f)(va_list))
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
int add_flag(t_flag *root, int element, void (*f)(va_list))
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
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			{
				if (s[i + 1] == '\0')
					break;
				result = start_printf_function(root, s[i + 1], infos);
				if (result == 0)
					ft_putchar_fd(s[i+1], 1);
				i++;
			}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(infos);
	return (0);
}

