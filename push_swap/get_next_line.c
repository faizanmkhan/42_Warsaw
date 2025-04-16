/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:09:41 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/04 19:28:53 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	static char	*char_left[MAX_FD];
	char		*line_buffer;
	char		*read_buffer;

	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
	{
		free(char_left[fd]);
		free(read_buffer);
		char_left[fd] = 0;
		read_buffer = 0;
		return (0);
	}
	if (!read_buffer)
		return (0);
	line_buffer = search_for_line(fd, read_buffer, char_left[fd]);
	free(read_buffer);
	read_buffer = 0;
	if (!line_buffer)
		return (0);
	char_left[fd] = extract_line(line_buffer);
	return (line_buffer);
}

char	*search_for_line(int fd, char *for_read, char *for_storing)
{
	int		control;
	char	*temp;

	control = 1;
	while (control > 0)
	{
		control = read(fd, for_read, BUFFER_SIZE);
		if (control == -1)
		{
			free(for_storing);
			return (0);
		}
		else if (control == 0)
			break ;
		for_read[control] = 0;
		if (!for_storing)
			for_storing = ft_strdup("");
		temp = for_storing;
		for_storing = ft_strjoin(temp, for_read);
		free(temp);
		temp = 0;
		if (ft_strchr(for_storing, 10))
			break ;
	}
	return (for_storing);
}

char	*extract_line(char *read_line)
{
	int		i;
	int		len;
	char	*rest;

	i = 0;
	while (read_line[i] != 10 && read_line[i] != 0)
		i++;
	if (read_line[i] == 0 || read_line[1] == 0)
		return (0);
	len = ft_strlen(read_line) - i;
	rest = ft_substr(read_line, i + 1, len);
	if (rest[0] == 0)
	{
		free(rest);
		rest = 0;
	}
	read_line[i + 1] = 0;
	return (rest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
