/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:46:56 by wipion            #+#    #+#             */
/*   Updated: 2025/10/31 23:28:33 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*insertnumber(char *str, int count, int minus, int n)
{
	count--;
	while (count >= 0)
	{
		str[count] = (n % 10) + 48;
		n = n / 10;
		count--;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}

static char	*returnzero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	setsize(int nb, int count)
{
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nb;
	int		count;
	int		minus;

	minus = 0;
	count = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (returnzero());
	if (n <= 0)
	{
		n = n *(-1);
		count++;
		minus++;
	}
	nb = n;
	count = setsize(nb, count);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	insertnumber(str, count, minus, n);
	return (str);
}
