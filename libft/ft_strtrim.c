/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:43:50 by wipion            #+#    #+#             */
/*   Updated: 2025/10/31 23:23:15 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_char_in_list(char c, char const *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list[i] != '\0')
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	startcounter(char const *s1, char const *set)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (s1[i] != '\0')
	{
		if (ft_char_in_list(s1[i], set))
			start++;
		else
			break ;
		i++;
	}
	return (start);
}

static int	endcounter(char const *s1, char const *set)
{
	int		i;
	int		end;

	i = ft_strlen(s1) - 1;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 2)
		return (ft_strlen(s1) - 1);
	while (s1[i] != '\0')
	{
		if (ft_char_in_list(s1[i], set) && end > 0)
			end--;
		else
			break ;
		i--;
	}
	return (end);
}

static char	*ft_strnull(void)
{
	char	*output;

	output = malloc(sizeof(char) * 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	return (output);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		start;
	unsigned int		end;
	char				*output;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = startcounter(s1, set);
	end = endcounter(s1, set);
	if (end == 0)
		return (ft_strnull());
	if (start > end)
		output = malloc(sizeof(char) * (start + end + 2));
	else if (end == 1)
		output = malloc(sizeof(char) * (end + start) + 1);
	else
		output = malloc(sizeof(char) * (end - start + 2));
	if (!output)
		return (NULL);
	s1 += start;
	if (start > end)
		ft_strlcpy(output, (char *)s1, (end + start) + 2);
	else
		ft_strlcpy(output, (char *)s1, (end - start) + 2);
	return (output);
}
