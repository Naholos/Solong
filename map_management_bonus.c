/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:49:51 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 08:42:34 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	symbol_counters(int *xy, char *nextrow, int *cep1fd, int rowlen)
{
	char	symb;

	while (++xy[0] < rowlen - 1)
	{
		symb = nextrow[xy[0]];
		if (symb != '0' && symb != '1' && symb != 'C' && symb != 'E'
			&& symb != 'P')
		{
			free(nextrow);
			badsymerr(ft_itoa(xy[1] + 1), ft_itoa(xy[0] + 1), symb, cep1fd[4]);
		}
		if (symb == 'C')
			cep1fd[0]++;
		if (symb == 'E')
			cep1fd[1]++;
		if (symb == 'P')
			cep1fd[2]++;
		if (symb == '1')
			cep1fd[3]++;
	}
}

int	chck_first_row(int fd_map)
{
	char	*first_row;
	size_t	x;
	size_t	row_len;

	first_row = get_next_line(fd_map);
	if (first_row == NULL)
		map_value_errors(1, fd_map);
	row_len = ft_strlen(first_row);
	if (row_len == 1)
		empty_row_error("1", fd_map, first_row);
	x = -1;
	while (++x < row_len - 1)
	{	
		if (first_row[x] != '1')
			wredge("1", ft_itoa(x + 1), fd_map, first_row);
	}
	if (x > MAX_WIDTH)
	{
		free(first_row);
		printf("Error\nMap too wide for this screen\n");
		chck_close(fd_map);
	}
	free(first_row);
	return (row_len);
}

int	chck_next_rows(int row_len, int *cep1fd)
{
	char	*nxtrow;
	int		flag_right_side_open;
	int		xy[2];

	flag_right_side_open = 0;
	xy[1] = 0;
	while (1)
	{
		nxtrow = get_next_line(cep1fd[4]);
		if (nxtrow == NULL)
			break ;
		if (flag_right_side_open == 1)
			wredge(ft_itoa(xy[1] + 1), ft_itoa(row_len - 1), cep1fd[4], nxtrow);
		xy[1]++;
		xy[0] = map_shape_errors(nxtrow, row_len, cep1fd[4], xy[1]);
		cep1fd[3] = 1;
		symbol_counters(xy, nxtrow, cep1fd, row_len);
		if (nxtrow[row_len - 2] != '1')
			flag_right_side_open = 1;
		free(nxtrow);
	}
	if (cep1fd[3] != row_len - 1)
		final_row_edge_error(ft_itoa(xy[1] + 1), cep1fd[4], nxtrow);
	chck_symbols_errors(cep1fd, nxtrow);
	return (xy[1]);
}

void	init_map(t_graphics *m, int columns, int rows, int colls)
{
	t_coord	a;
	t_coord	b;

	(*m).mlx = mlx_init();
	(*m).win = mlx_new_window((*m).mlx, DIM * columns, DIM * rows, "SO LONG!");
	(*m).colls = colls;
	(*m).steps = 0;
	(*m).height = rows;
	(*m).width = columns;
	(*m).movement = 4;
	a.y = 0;
	(*m).img = get_image((*m).mlx, '0', a, m);
	while (a.y <= rows)
	{
		a.x = 0;
		while (a.x < columns)
		{
			b = map2window(a);
			mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, b.x, b.y);
			a.x++;
		}
		a.y++;
	}
	mlx_destroy_image((*m).mlx, (*m).img);
}

char	**read_map(char *map_name, int rows)
{
	char	**map;
	int		fd_map;
	int		y;

	fd_map = chck_open(open(map_name, O_RDONLY));
	map = malloc((rows + 1) * sizeof(char *));
	if (map == NULL)
	{
		printf("Error\nCan not allocate memory\n");
		exit (1);
	}
	y = 0;
	while (y <= rows)
		map[y++] = get_next_line(fd_map);
	return (map);
}
