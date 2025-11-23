#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
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
static char    *ft_makestr(char *str,char *letters, int count, int infos)
{
    while (count >= 0)
    {
        if ((infos% 16) > 9)
            str[count] = letters[(infos % 16) - 10];
        else 
            str[count] = (infos % 16) + (48);
        infos /= 16;
        count--;
    }
    return (str);
}
static int setsize(int nb)
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

char    *ft_hexadecimal(int a, int nb)
{
    int    count;
    char    *letters;
    char    *str;

    count = 0;
    count = count + setsize(nb);
    str = malloc(sizeof(char) * count);
    if (!str)
        return (NULL);
    letters = ft_checklowupcase(a);
    ft_makestr(str, letters, count, nb);
    free(letters);
    return (str);
}
