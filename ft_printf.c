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
static int start_printf_function(t_flag *root, char c, va_list infos)
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
static void end_printf_function(t_flag *root)
{
    t_flag *tmp;

    while (root != NULL)
    {
        tmp = root->next;
        free(root);
        root = tmp;
    }
}
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

static int ft_create_str(const char *s, t_flag *root,va_list infos, int result)
{
	int tmpresult;
	int i;

	tmpresult = 0;
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
			else
			{
				ft_putchar_fd(s[i], 1);
				result++;
			}
			i++;
	}
	va_end(infos);
	return (result);
}
// main function
int ft_printf(const char *s, ...)
{
	t_flag *root;
	va_list infos;
	int result;

	va_start(infos, s);
	result = 0;
	root = call_flag();
	result = ft_create_str(s, root, infos, result);
	end_printf_function(root);
	return (result);
}
