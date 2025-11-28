#include "ft_printf.h"
#include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
static char    *ft_checklowupcase(int a)
{
    char    *letters;

    if (a == 1)
        letters = ft_strdup("ABCDEF");
    else if (a == 0)
        letters = ft_strdup("abcdef");
    if (!letters)
        return (NULL);
    return (letters);
}
static char    *ft_makestr(char *str, char *letters, int count, size_t nb)
{
    while (count >= 0)
    {
        if ((nb % 16) >= 10)
            str[count] = letters[(nb % 16) - 10];
        else 
            str[count] = (nb % 16) + 48;
        nb /= 16;
        count--;
    }
    return (str);
}
static int setsize(size_t nb)
{
    int    count;

    count = 0;
    while (nb > 0)
    {
        nb = nb / 16;
        count++;
    }
    return (count);
}

void    *ft_long_hexadecimal(int a, size_t nb)
{
    int     count;
    char    *letters;
    char    *str;

    count = setsize(nb) - 1;
    str = malloc(sizeof(char) * (count + 1));
    if (!str)
        return (NULL);
    letters = ft_checklowupcase(a);
    ft_makestr(str, letters, count, nb);
    free(letters);
    ft_putstr_fd(str, 1);
    return(str);
}
#include <stdio.h>

char  *ft_pointeradress(va_list infos)
{
    char    *str;
	void	*p;

	p = va_arg(infos, void *);
	if (p == NULL)
		return (ft_strdup("(nil)"));

	/*if ((int)va_arg(infos, int) < 0)
		val_ptr = 4294967295 + (int)va_arg(infos, int);*/
	//else
    //val_ptr = (size_t)p;

    str = ft_unsigned_int_to_char((unsigned long long)p, "0123456789abcdef");
    return (str);
}