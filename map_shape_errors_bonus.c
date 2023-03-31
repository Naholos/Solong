/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape_errors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:07:28 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 08:43:25 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	wredge(char *x, char *y, int fd_map, char *row)
{
	free(row);
	printf("Error\nNon enclosed perimeter at row %s, column %s\n", x, y);
	chck_close(fd_map);
}

void	empty_row_error(char *y, int fd_map, char *row)
{
	free(row);
	printf("Error\n%s row empty\n", y);
	chck_close(fd_map);
}

void	final_row_edge_error(char *y, int fd_map, char *row)
{
	free(row);
	printf("Error\nNon enclosed perimeter at row %s (the last one)\n", y);
	chck_close(fd_map);
}

static void	non_rectangular_error(int difference, int fd_map, int y)
{
	if (difference > 0)
		printf("Error\nRow %s is longer than first row\n", ft_itoa (y + 1));
	else
		printf("Error\nRow %s is shorter than first row\n", ft_itoa (y + 1));
	chck_close(close(fd_map));
}

int	map_shape_errors(char *next_row, int row_len, int fd_map, int y)
{
	int	len;

	len = (int)ft_strlen(next_row);
	if (len == 1)
	{
		free(next_row);
		empty_row_error(ft_itoa(y + 1), fd_map, next_row);
	}
	if (len != row_len)
	{
		free(next_row);
		non_rectangular_error(len - row_len, fd_map, y);
	}
	if (next_row[0] != '1')
		wredge(ft_itoa(y + 1), "1", fd_map, next_row);
	return (0);
}
