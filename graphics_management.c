/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:59:52 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 11:54:52 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static t_coord	coord_management(int keycode, t_coord a)
{
	if (keycode == LEFT)
		a.x--;
	if (keycode == UP)
		a.y++;
	if (keycode == RIGHT)
		a.x++;
	if (keycode == DOWN)
		a.y--;
	return (a);
}

static void	move_player2(t_graphics *m, int keycode, t_coord a)
{
	t_coord	b;
	t_coord	c;

	a = coord_management(keycode, a);
	b = init_coord(0, 1);
	b = find_element((*m).map, 'P', (*m).height, b);
	if ((*m).map[a.y][a.x] != '1' && (*m).map[a.y][a.x] != 'E')
	{
		c = map2window(a);
		(*m).img = get_image((*m).mlx, (*m).map[b.y][b.x], b, m);
		mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
		mlx_destroy_image((*m).mlx, (*m).img);
		update_player_pos(m, a, b);
		c = map2window(b);
		(*m).img = get_image((*m).mlx, (*m).map[b.y][b.x], b, m);
		mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
		mlx_destroy_image((*m).mlx, (*m).img);
	}
	if ((*m).map[a.y][a.x] == 'E')
	{
		if ((*m).steps == 2147483647)
			(*m).steps = -1;
		printf("%d steps needed to take all treasures & escape\n", ++(*m).steps);
		exit (0);
	}
}

static void	move_player(t_graphics *m, int keycode, t_coord a)
{
	t_coord	b;
	t_coord	c;

	if ((*m).colls == 0)
		move_player2(m, keycode, a);
	a = coord_management(keycode, a);
	b = init_coord(0, 1);
	b = find_element((*m).map, 'P', (*m).height, b);
	if ((*m).map[a.y][a.x] != '1' && (*m).map[a.y][a.x] != 'E')
	{
		if ((*m).map[a.y][a.x] == 'C')
			(*m).colls--;
		c = map2window(a);
		(*m).img = get_image((*m).mlx, (*m).map[b.y][b.x], b, m);
		mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
		mlx_destroy_image((*m).mlx, (*m).img);
		update_player_pos(m, a, b);
		c = map2window(b);
		(*m).img = get_image((*m).mlx, (*m).map[b.y][b.x], b, m);
		mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
		mlx_destroy_image((*m).mlx, (*m).img);
		if ((*m).steps == 2147483647)
			(*m).steps = -1;
		printf("%d steps taken, %d treasures left\n", ++(*m).steps, (*m).colls);
	}
}

int	key_hook(int keycode, t_graphics *m)
{
	t_coord	a;

	if (keycode == SCAPE)
	{
		mlx_destroy_window((*m).mlx, (*m).win);
		printf("You have left the game...\n");
		exit (0);
	}
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
	{
		a = init_coord(0, 1);
		a = find_element((*m).map, 'P', (*m).height, a);
		if ((*m).map[a.y][a.x] != '1' && (*m).map[a.y][a.x] != 'E')
			move_player(m, keycode, a);
	}
	return (0);
}

void	draw_map(char **map, int columns, int rows, int colls)
{
	t_coord		a;
	t_coord		b;
	t_graphics	m;

	init_map(&m, columns, rows, colls);
	m.map = map;
	a.y = -1;
	while (++a.y < rows)
	{
		a.x = -1;
		while (++a.x < columns)
		{
			if (m.map[a.y][a.x] != '0')
			{
				b = map2window(a);
				m.img = get_image(m.mlx, m.map[a.y][a.x], a, &m);
				mlx_put_image_to_window(m.mlx, m.win, m.img, b.x, b.y);
				mlx_destroy_image(m.mlx, m.img);
			}
		}
	}
	mlx_key_hook(m.win, &key_hook, &m);
	mlx_hook(m.win, 17, 1L << 17, close_window, &m);
	mlx_loop(m.mlx);
}
