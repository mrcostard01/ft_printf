/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:48 by wipion            #+#    #+#             */
/*   Updated: 2025/10/20 16:52:35 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strmaker(char *dest, const char *src, int limit, int len_des)
{
	unsigned int		i;

	i = 0;
	while (src[i] && i < (unsigned int)limit)
	{
		dest[i + len_des] = src[i];
		i++;
	}
	dest[len_des + i] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	limit;
	unsigned int	len_des;
	unsigned int	len_src;

	if (size == 0 && src[0] == '\0')
		return (size);
	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	len_des = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_des >= size)
		return (len_src + size);
	if (src[0] == '\0' && len_des == 0)
		return (0);
	if (src[0] == '\0' && len_des == size)
		return (len_des + len_src);
	limit = size - len_des - 1;
	ft_strmaker(dest, src, limit, len_des);
	return (len_des + len_src);
}
