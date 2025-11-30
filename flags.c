#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

//printf hexadecimal in lowcase
static int ft_printf_hexadecimallow (va_list infos)
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
//printf hexadecimal in upcase
static int ft_printf_hexadecimalup (va_list infos)
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
static int ft_printf_pointer (va_list infos)
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
static int ft_printf_percent(va_list infos)
{
	(void)infos;
	ft_putchar_fd('%', 1);
    return (1);
}

// make a new node
void *call_flag(void)
{
    t_flag *root;
    root = init_flag('c', &ft_printf_char);
    add_flag(root, 'd', &ft_printf_integer);
    add_flag(root, 'i', &ft_printf_integer);
    add_flag(root, 's', &ft_printf_string);
    add_flag(root, 'x', &ft_printf_hexadecimallow);
    add_flag(root, 'X', &ft_printf_hexadecimalup);
    add_flag(root, 'p', &ft_printf_pointer);
    add_flag(root, 'u', &ft_printf_unsigned_int);
    add_flag(root, '%', &ft_printf_percent);
    return(root);
}
