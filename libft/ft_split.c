/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:42:17 by wipion            #+#    #+#             */
/*   Updated: 2025/11/06 17:17:12 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*getword(int *start, char *s, int c)
{
	int		i;
	char	*str;

	i = *start;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = malloc((i -(*start) + 1) * sizeof(char));
	if (str == NULL)
	{
		(*start)++;
		return (NULL);
	}
	i = 0;
	while (s[(*start)] != c && s[(*start)] != '\0')
	{
		str[i] = s[(*start)];
		i++;
		(*start)++;
	}
	str[i] = '\0';
	while (s[(*start)] == c)
		(*start)++;
	return (str);
}

static char	**make_empty_array(char *str_to_free)
{
	char	**arr;

	if (str_to_free != NULL)
		free(str_to_free);
	arr = malloc((1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

static char	**make_one_line_array(const char *s)
{
	char	**arr;

	arr = malloc((2) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[0] = ft_strdup(s);
	if (arr[0] == NULL)
	{
		free(arr);
		return (NULL);
	}
	arr[1] = NULL;
	return (arr);
}

static char	**run_split(int len, char **array, char *s_trimmed, char c)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (i < (len + 1))
	{
		array[i] = getword(&start, s_trimmed, c);
		if (array[i] == NULL)
		{
			free(s_trimmed);
			ft_free_array(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	free(s_trimmed);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**array;
	char	*s_trimmed;

	if (s == NULL || *s == '\0')
		return (make_empty_array(NULL));
	if (c == '\0' || (ft_strlen(s) == 1 && s[0] != c))
		return (make_one_line_array(s));
	s_trimmed = ft_strtrim(s, &c);
	if (!s_trimmed)
		return (NULL);
	if (s_trimmed[0] == '\0')
		return (make_empty_array(s_trimmed));
	len = ft_lenarr2d(s_trimmed, c);
	array = malloc((len + 2) * sizeof(char *));
	if (!array)
	{
		free(s_trimmed);
		return (NULL);
	}
	array = run_split(len, array, s_trimmed, c);
	return (array);
}
