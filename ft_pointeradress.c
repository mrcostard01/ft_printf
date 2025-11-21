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

char    *ft_long_hexadecimal(int a, size_t nb)
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
    return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void    ft_pointeradress(void *p)
{
    size_t  val_ptr;
    val_ptr = (size_t)p;
    ft_putstr_fd("0x", 1);
    ft_putstr_fd(ft_long_hexadecimal(0,val_ptr), 1);
}
