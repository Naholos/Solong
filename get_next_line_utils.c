/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:10:34 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/12/22 16:01:51 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	init(size_t *line_end, size_t *line_length, char **line, char **line2)
{
	*line = NULL;
	*line_end = 0;
	*line2 = NULL;
	*line_length = ft_strlen(*line);
}	

char	*ft_strjoin(char *s1, char *s2, size_t len)
{
	char	*concat;
	size_t	i;
	size_t	j;

	concat = malloc(len * sizeof(char));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}

char	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destiny;
	const unsigned char	*source;

	i = 0;
	destiny = dst;
	source = src;
	if (src == NULL)
		return (NULL);
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	destiny[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1, size_t len)
{
	unsigned int	i;
	char			*duplicate;

	i = 0;
	duplicate = malloc(len * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

size_t	ft_find_line_end(char const *buff)
{
	size_t	i;

	i = 0;
	while (*(buff + i) != '\0')
	{
		if (*(buff + i) == '\n')
			return (++i);
		i++;
	}
	return (0);
}
