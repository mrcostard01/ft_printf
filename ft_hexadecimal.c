/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:31:05 by wipion            #+#    #+#             */
/*   Updated: 2025/11/28 22:58:56 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

static int	ft_size_number(unsigned long long n, int length)
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

char	*ft_unsigned_int_to_char(unsigned long long nb, char *base)
{
	unsigned long long		n;
	char					*number;
	int						size;

	size = 0;
	n = nb;
	size = ft_size_number(n, ft_strlen(base));
	number = malloc(sizeof(char) * (size + 2));
	if (!number)
		return (NULL);
	if (nb == 0)
	{
		number[0] = base[0];
		number[1] = '\0';
		return (number);
	}
	number[size] = '\0';
	n = nb;
	while (n > 0)
	{
		number[size - 1] = base[n % ft_strlen(base)];
		size--;
		n = n / ft_strlen(base);
	}
	return (number);
}
