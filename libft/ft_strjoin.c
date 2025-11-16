/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:23:49 by wipion            #+#    #+#             */
/*   Updated: 2025/10/31 23:23:50 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*checkstr(const char *s)
{
	char	*newstr;

	newstr = malloc(sizeof(char) * 2);
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s, 2);
	return (newstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	size_t	count;

	count = 0;
	if (s1 == NULL)
		return (checkstr(s2));
	if (s2 == NULL)
		return (checkstr(s1));
	count = (ft_strlen(s1) + ft_strlen(s2)) - 1;
	newstr = malloc(sizeof(char) * (count + 2));
	if (!newstr)
		return (NULL);
	newstr[0] = '\0';
	ft_strlcat(newstr, s1, (count + 2));
	ft_strlcat(newstr, s2, (count + 2));
	return (newstr);
}
