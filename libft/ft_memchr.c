/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:58:08 by wipion            #+#    #+#             */
/*   Updated: 2025/10/23 20:09:46 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (char *)s;
	if (n == 0)
		return (NULL);
	if (*(char *)a == c)
		return (a);
	while (i < n - 1)
	{
		if (*(char *)a == (char)c)
			return (a);
		a++;
		i++;
	}
	if (*(char *)a == (char)c)
		return (a);
	a = NULL;
	return (a);
}
