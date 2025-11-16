/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:23:24 by wipion            #+#    #+#             */
/*   Updated: 2025/11/06 17:23:28 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;
	int		length;

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
