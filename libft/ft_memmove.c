/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:15:17 by wipion            #+#    #+#             */
/*   Updated: 2025/10/22 17:27:43 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	char	*dchar;
	char	*schar;

	dchar = (char *)d;
	schar = (char *)s;
	if (dchar <= schar)
	{
		while (n--)
			*dchar++ = *schar++;
	}
	if (dchar > schar)
	{
		dchar += n - 1;
		schar += n - 1;
		while (n--)
			*dchar-- = *schar--;
	}
	return (d);
}
