/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:58:06 by faikhan           #+#    #+#             */
/*   Updated: 2024/11/09 14:10:52 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = ft_strlen(s);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	char			*ptr;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	return ((char *)ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0 && s[i] == 0)
		return ((char *)s);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	size_t			ex;

	i = 0;
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	ex = ft_strlen(s) - start;
	if (len > ex)
		len = ex;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (s[start] != 0 && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = 0;
	return ((char *)ptr);
}
