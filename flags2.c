#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

int ft_printf_integer (va_list infos)
{
    int value;static
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

