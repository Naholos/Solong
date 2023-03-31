/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:41:05 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 08:38:54 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static char	*ft_end_line(char *line, size_t l_end, size_t line_length)
{
	char	*output;

	output = ft_strdup(line, line_length + 1);
	if (l_end)
	{
		output[l_end] = '\0';
		ft_memcpy(line, line + l_end, line_length - l_end);
	}
	else
		*line = '\0';
	return (output);
}

static char	*ft_append(char *line, char *line2, char *buff, size_t line_length)
{
	line2 = ft_strjoin(line, buff, line_length + 1);
	free(line);
	line = line2;
	return (line);
}

static int	ft_check_end(ssize_t r_bytes, char *line, size_t line_length)
{
	if ((!r_bytes && (line == NULL || !line_length)) || (r_bytes == -1))
	{
		free(line);
		return (1);
	}
	return (0);
}	

static char	*ft_read(int fd, char *buff)
{
	static char	*line;
	ssize_t		r_bytes;
	char		*line2;
	size_t		line_end;
	size_t		line_length;

	free(line);
	init(&line_end, &line_length, &line, &line2);
	while (!line_end)
	{
		r_bytes = (chck_read(read(fd, buff, BUFFER_SIZE), fd));
		if (ft_check_end(r_bytes, line, line_length))
			return (NULL);
		buff[r_bytes] = '\0';
		line_length += r_bytes;
		if (line == NULL)
			line = ft_strdup(buff, r_bytes + 1);
		else
			line = ft_append(line, line2, buff, line_length + 1);
		line_end = ft_find_line_end(line);
		if (line_end || (!r_bytes && *line != '\0'))
			break ;
	}
	return (ft_end_line(line, line_end, line_length));
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	return (ft_read(fd, buff));
}
