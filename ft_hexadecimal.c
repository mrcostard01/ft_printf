#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

char    *ft_unsigned_int_to_char(unsigned long long nb, char *base)
{
    int size;
    unsigned long long n;
    char *number;

    size = 0;
    n = nb;

    while (n > 0) {
        size++;
        n = n / ft_strlen(base);
    }
    number = malloc(sizeof(char) * (size + 2));
    if (!number)
        return (NULL);
    if (nb == 0) {
            number[0] = base[0];
            number[1] = '\0';
            return number;
        }
    number[size] = '\0';
    n = nb;
    while (n > 0)
        {
            number[size-1] = base[n % ft_strlen(base)];
            size--;
            n = n / ft_strlen(base);
        }
    return (number);
}




char    *ft_int_to_char(long long nb, char *base)
{
    int size;
    long long n;
    char *number;
    char negative;

    negative = 0;
    size = 0;
    n = nb;
    if (n < 0) {
            n *= -1;
            negative = 1;
        }
    while (n > 0) {
        size++;
        n = n / ft_strlen(base);
    }
    number = malloc(sizeof(char) * (size + negative + 2));
    if (!number)
        return (NULL);
    if (nb == 0) {
            number[0] = base[0];
            number[1] = '\0';
            return number;
        }
    if (negative)
        number[0] = '-';
    number[size+negative] = '\0';
    n = nb;
    if (negative == 1)
        n *= -1;
    while (n > 0)
        {
            number[size+negative-1] = base[n % ft_strlen(base)];
            size--;
            n = n / ft_strlen(base);
        }
    return (number);
}
