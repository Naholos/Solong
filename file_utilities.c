/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:40:04 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/10 13:10:15 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" 

int	chck_close(int fd_map)
{
	if (close (fd_map == -1))
		perror("Error");
	exit (1);
}

int	chck_open(int fd_map)
{
	if (fd_map == -1)
	{
		perror("Error");
		exit (1);
	}
	return (fd_map);
}

int	chck_read(int reading, int fd_map)
{
	if (reading == -1)
	{
		perror("Error");
		reading = close(fd_map);
		if (reading == -1)
			perror("Error");
		exit (1);
	}
	return (reading);
}

int	map_file_errors(char *map_name)
{
	size_t	name_len;

	name_len = ft_strlen(map_name);
	if (map_name[name_len - 1] != 'r' || map_name[name_len - 2] != 'e'
		|| map_name[name_len - 3] != 'b' || map_name[name_len - 4] != '.')
		extension_error();
	return (chck_open(open(map_name, O_RDONLY)));
}

void	extension_error(void)
{
	printf("Error\nMap file extension error\n");
	exit (1);
}
