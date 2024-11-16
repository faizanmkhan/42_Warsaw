/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:09:41 by faikhan           #+#    #+#             */
/*   Updated: 2024/11/09 15:52:29 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*_remaining_char;
	char		*_read_buffer;
	char		*_buffer_file;

	_buffer_file = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(_remaining_char);
		free(_buffer_file);
		_remaining_char = NULL;
		_buffer_file = NULL;
		return (NULL);
	}
	if (!_buffer_file)
		return (NULL);
	_read_buffer = _search_for_new_line(fd, _buffer_file, _remaining_char);
	free(_buffer_file);
	_buffer_file = NULL;
	if (!_read_buffer)
		return (NULL);
	_remaining_char = _create_line_and_copy_remaining(_read_buffer);
	return (_read_buffer);
}

char	*_search_for_new_line(int fd, char *_buffer_read, char *_static_buffer)
{
	ssize_t	_n_byte_read;
	char	*_temporary_buffer;

	_n_byte_read = 1;
	while (_n_byte_read > 0)
	{
		_n_byte_read = read(fd, _buffer_read, BUFFER_SIZE);
		if (_n_byte_read == -1)
		{
			free (_static_buffer);
			return (NULL);
		}
		else if (_n_byte_read == 0)
			break ;
		_buffer_read[_n_byte_read] = 0;
		if (!_static_buffer)
			_static_buffer = ft_strdup("");
		_temporary_buffer = _static_buffer;
		_static_buffer = ft_strjoin(_temporary_buffer, _buffer_read);
		free (_temporary_buffer);
		_temporary_buffer = NULL;
		if (ft_strchr(_static_buffer, 10))
			break ;
	}
	return (_static_buffer);
}

char	*_create_line_and_copy_remaining(char *_extra_bytes)
{
	char	*_remaining_bytes;
	size_t	i;
	size_t	len;

	i = 0;
	while (_extra_bytes[i] != 10 && _extra_bytes[i] != 0)
		i++;
	if (_extra_bytes[i] == 0 || _extra_bytes[1] == 0)
		return (NULL);
	len = ft_strlen(_extra_bytes) - i;
	_remaining_bytes = ft_substr(_extra_bytes, i + 1, len);
	if (*_remaining_bytes == 0)
	{
		free(_remaining_bytes);
		_remaining_bytes = NULL;
	}
	_extra_bytes[i + 1] = 0;
	return (_remaining_bytes);
}
