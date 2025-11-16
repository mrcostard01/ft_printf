/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:36:08 by wipion            #+#    #+#             */
/*   Updated: 2025/10/22 21:47:54 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(str);
	while (i <= length)
	{
		if (str[i] == (char)to_find)
			return ((char *)&str[i]);
		i++;
	}
	str = 0;
	return ((char *)str);
}
