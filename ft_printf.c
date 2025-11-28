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
	int value;
	char	*str;
    int    len;

    len = 0;
	value = (int)va_arg(infos, int);
	str = ft_int_to_char((long long)value, "0123456789");
	ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    free(str);
	return (len);
}
//print positive integer
int ft_printf_unsigned_int (va_list infos)
{
	unsigned int value;
	char	*str;
    int    len;

    len = 0;
	value = (unsigned int)va_arg(infos, unsigned int);
	str = ft_int_to_char((long long)value, "0123456789");
	ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    free(str);
	return (len);
}
//print a single caracter
int ft_printf_char (va_list infos)
{
	int value;

	value = (int)va_arg(infos, int);
	ft_putchar_fd(value, 1);
	return (1);
}
//print a string
int ft_printf_string (va_list infos)
{
	char *value;
	int	len;

	value = (char *)va_arg(infos, char *);
	if (value == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(value);
	if (len == 1)
		ft_putchar_fd(value[0], 1);
	else
		ft_putstr_fd(value, 1);
	return (len);
}
//print hexadecimal in lowcase
int ft_printf_hexadecimallow (va_list infos)
{
	unsigned int value;
	char *str;
	int len;


	value = (unsigned int)va_arg(infos, unsigned int);
	str = ft_int_to_char((long long)value , "0123456789abcdef");
	if (str == NULL)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
    return (len);
}
//printf hexadecimal upcase
int ft_printf_hexadecimalup (va_list infos)
{
	unsigned int	value;
	char *str;
	int len;


	value = (unsigned int)va_arg(infos, unsigned int);
	str = ft_int_to_char((long long)value , "0123456789ABCDEF");
	if (str == NULL)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
    return (len);
}
//print poiter's address
int ft_printf_pointer (va_list infos)
{
	int	len;
	char *value;

	len = 0;
	value = ft_pointeradress(infos);
	len = ft_strlen(value);
	//ft_strncmp(value, "(nil)", 5));
	if (ft_strncmp(value, "(nil)", 5) == 0) {
			ft_putstr_fd(value, 1);
			len = ft_strlen(value);
			free(value);
			return (len);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(value, 1);
	len = ft_strlen(value);
	free(value);
	return (len + 2);
}
//display a percent
int ft_printf_percent(va_list infos)
{
	(void)infos;
	ft_putchar_fd('%', 1);
    return (1);
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
	int 	len;

	len = 0;
	flag = root;
	while (flag != NULL)
		{
			if (flag->element == c) {
				len += flag->f(infos);
				return (len);
			}
			flag = flag->next;
		}
	return (len);
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
	int	tmpresult;
	int result;
	va_start(infos, s);

	result = 0;
	tmpresult = 0;
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
				tmpresult = start_printf_function(root, s[i + 1], infos);
				if (tmpresult < 0 )
					return (-1);
				if (tmpresult > 0)
					result += tmpresult;
				i++;
			}
		else {
			ft_putchar_fd(s[i], 1);
			result++;
		}
		i++;
	}
	end_printf_function(root);
	va_end(infos);
	return (result);
}
#include <limits.h>
/*#include <stdio.h>
int	main()
{

printf("p: %p\n", 0);
ft_printf("ft_p: %p\n", 0);
printf("p null: %p\n", LONG_MAX);
ft_printf("ft_p null: %p\n", LONG_MAX);
}*/