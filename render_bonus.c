/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:14:12 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 11:56:18 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "./include/so_long_bonus.h"

static char	enemy_img(char symbol1, char symbol2)
{	
	if (symbol1 == symbol2 || symbol1 == symbol2 + 1)
		symbol1 += 1;
	else
		symbol1 = symbol2;
	return (symbol1);
}

static t_coord	rand_pos(void)
{
	int		coord;
	t_coord	a;

	coord = rand() % 4;
	a.x = 0;
	a.y = 0;
	if (coord == 0)
		a.x = 1;
	if (coord == 1)
		a.x = -1;
	if (coord == 2)
		a.y = 1;
	if (coord == 3)
		a.y = -1;
	return (a);
}

static void	enemy_pos(t_coord a, t_coord b, t_coord c, t_graphics *m)
{
	static char	symbol;
	int			i;

	if (a.y == -1)
		symbol = enemy_img(symbol, 'T');
	if (a.y == 1)
		symbol = enemy_img(symbol, 'Q');
	if (a.x == 1)
		symbol = enemy_img(symbol, 'M');
	if (a.x == -1)
		symbol = enemy_img(symbol, 'W');
	(*m).img = get_image((*m).mlx, symbol, b, m);
	i = 0;
	while (i < 50000000)
		i++;
	mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
	mlx_destroy_image((*m).mlx, (*m).img);
	if ((*m).map[b.y][b.x] == 'P')
		killed();
}

static void	render_next_frame2(t_graphics *m)
{
	t_coord		a;
	t_coord		b;
	t_coord		c;

	a = rand_pos();
	b = init_coord(0, 1);
	b = find_element((*m).map, 'S', (*m).height, b);
	while (b.x != 0 && b.y != 0)
	{
		c = map2window(b);
		if ((*m).map[b.y + a.y][b.x + a.x] == '0'
		|| (*m).map[b.y + a.y][b.x + a.x] == 'P')
		{
			(*m).img = get_image((*m).mlx, '0', b, m);
			mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
			mlx_destroy_image((*m).mlx, (*m).img);
			(*m).map[b.y][b.x] = '0';
			b = update_coord(a.x, a.y, b);
			enemy_pos(a, b, map2window(b), m);
			(*m).map[b.y][b.x] = 'S';
		}
		b = update_coord(-b.x, 1, b);
		b = find_element((*m).map, 'S', (*m).height, b);
	}
}	

int	render_next_frame(t_graphics *m)
{
	int		dim;
	t_coord	b;
	t_coord	c;

	dim = DIM;
	render_next_frame2(m);
	if ((*m).colls == 0)
	{
		b = init_coord(0, 1);
		b = find_element((*m).map, 'E', (*m).height, b);
		while (b.x != 0 && b.y != 0)
		{
			c = map2window(b);
			(*m).img = mlx_xpm_file_to_image((*m).mlx, E2, &dim, &dim);
			mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, c.x, c.y);
			mlx_destroy_image((*m).mlx, (*m).img);
			(*m).map[b.y][b.x] = 'Z';
			b = find_element((*m).map, 'E', (*m).height, b);
		}
	}
	return (0);
}
