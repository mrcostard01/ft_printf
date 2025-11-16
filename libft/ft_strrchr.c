/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:48:18 by wipion            #+#    #+#             */
/*   Updated: 2025/10/22 21:38:35 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int	length;

	length = ft_strlen(str);
	while (length >= 0)
	{
		if (str[length] == (char)to_find)
			return ((char *)&str[length]);
		length--;
	}
	str = 0;
	return ((char *)str);
}
