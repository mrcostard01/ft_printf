/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:29:00 by wipion            #+#    #+#             */
/*   Updated: 2025/11/28 21:53:03 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_duplicate(char c1, char c2, char *number)
{
	number[0] = c1;
	number[1] = c2;
	return (number);
}

static void	ft_makstr(char *number, long long n, char *base, int size)
{
	while (n > 0)
	{
		number[size - 1] = base[n % ft_strlen(base)];
		size--;
		n = n / ft_strlen(base);
	}
}

static int	ft_size_number(long long n, int length)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		size++;
		n = n / length;
	}
	return (size);
}

char	*ft_int_to_char(long long nb, char *base)
{
	long long	n;
	char		*number;
	int			size;
	char		negative;

	negative = 0;
	n = nb;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	size = ft_size_number(n, ft_strlen(base));
	number = malloc(sizeof(char) * (size + negative + 2));
	if (!number)
		return (NULL);
	if (nb == 0)
		return (ft_duplicate(base[0], '\0', number));
	if (negative)
		number[0] = '-';
	number[size + negative] = '\0';
	if (negative == 1)
		nb *= -1;
	ft_makstr(number, nb, base, (size + negative));
	return (number);
}
