/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:10:01 by wipion            #+#    #+#             */
/*   Updated: 2025/10/22 18:52:33 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j])
			{
				if (little[j + 1] == '\0' && (j + i) < len)
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
