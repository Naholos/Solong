/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_management_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:07:28 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 10:07:08 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

t_coord	find_element(char **map, char element, int rows, t_coord a)
{
	int	flag;

	flag = 0;
	while (a.y < rows)
	{
		if (flag == 1)
			a.x = 0;
		else
			flag = 1;
		while (map[a.y][a.x])
		{
			if (map[a.y][a.x] == element)
				return (a);
			a.x++;
		}
		a.y++;
	}
	a.x = 0;
	a.y = 0;
	return (a);
}

t_coord	map2window(t_coord a)
{
	a.x *= DIM;
	a.y *= DIM;
	return (a);
}

t_coord	update_coord(int x, int y, t_coord a)
{
	a.x += x;
	a.y += y;
	return (a);
}

t_coord	init_coord(int x, int y)
{
	t_coord	a;

	a.x = x;
	a.y = y;
	return (a);
}

void	update_player_pos(t_graphics *m, t_coord a, t_coord b)
{
	(*m).map[b.y][b.x] = '0';
	(*m).map[a.y][a.x] = 'P';
}
