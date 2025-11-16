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
static char    *ft_makestr(char *str, char *letters, int count, int nb)
{
    while (count >= 0)
    {
        if ((nb % 16) > 9)
            str[count] = letters[(nb % 16) - 10];
        else 
            str[count] = (nb % 16) + (48);
        nb /= 16;
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
    int    minus;
    char    *letters;
    char    *str;

    count = count + setsize(nb) - 1;
    str = malloc(sizeof(char) * (count + 1));
    if (!str)
        return (NULL);
    letters = ft_checklowupcase(a);
    ft_makestr(str, letters, count, nb);
    free(letters);
    return (str);
}
