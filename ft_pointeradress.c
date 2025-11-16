#include <unistd.h>
#include <stdlib.h>

char    *ft_strdup(const char *s)
{
    char    *arr;
    int     i;
    int     length;

    length = 0;
    i = 0;
    while (s[length])
        length++;
    arr = malloc(sizeof(char) * (length + 1));
    if (!arr)
        return (NULL);
    if (s[i] == '\0')
    {
        arr[0] = '\0';
        return (arr);
    }
    while (s[i] && i <= length)
    {
        arr[i] = s[i];
        i++;
    }
    arr[i] = '\0';
    return (arr);
}
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
    write(1, "0x", 2);
    ft_putstr_fd(ft_long_hexadecimal(0,val_ptr), 1);
    write(1, "\n", 2);
}
int main()
{
    int a;
    void *p;
    p = &a;
    ft_pointeradress(p);
}