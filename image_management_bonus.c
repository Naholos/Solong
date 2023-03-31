/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:21:51 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 09:32:51 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "./include/so_long_bonus.h"

static void	*collectible3(void *mlx, int coll, int dim)
{
	if (coll == 22)
		return (mlx_xpm_file_to_image(mlx, COLL22, &dim, &dim));
	if (coll == 23)
		return (mlx_xpm_file_to_image(mlx, COLL23, &dim, &dim));
	if (coll == 24)
		return (mlx_xpm_file_to_image(mlx, COLL24, &dim, &dim));
	if (coll == 25)
		return (mlx_xpm_file_to_image(mlx, COLL25, &dim, &dim));
	if (coll == 26)
		return (mlx_xpm_file_to_image(mlx, COLL26, &dim, &dim));
	if (coll == 27)
		return (mlx_xpm_file_to_image(mlx, COLL27, &dim, &dim));
	if (coll == 28)
		return (mlx_xpm_file_to_image(mlx, COLL28, &dim, &dim));
	if (coll == 29)
		return (mlx_xpm_file_to_image(mlx, COLL29, &dim, &dim));
	if (coll == 30)
		return (mlx_xpm_file_to_image(mlx, COLL30, &dim, &dim));
	if (coll == 31)
		return (mlx_xpm_file_to_image(mlx, COLL31, &dim, &dim));
	return (mlx_xpm_file_to_image(mlx, COLL32, &dim, &dim));
}

static void	*collectibles2(void *mlx, int coll, int dim)
{
	if (coll == 10)
		return (mlx_xpm_file_to_image(mlx, COLL10, &dim, &dim));
	if (coll == 11)
		return (mlx_xpm_file_to_image(mlx, COLL11, &dim, &dim));
	if (coll == 12)
		return (mlx_xpm_file_to_image(mlx, COLL12, &dim, &dim));
	if (coll == 13)
		return (mlx_xpm_file_to_image(mlx, COLL13, &dim, &dim));
	if (coll == 14)
		return (mlx_xpm_file_to_image(mlx, COLL14, &dim, &dim));
	if (coll == 15)
		return (mlx_xpm_file_to_image(mlx, COLL15, &dim, &dim));
	if (coll == 16)
		return (mlx_xpm_file_to_image(mlx, COLL16, &dim, &dim));
	if (coll == 17)
		return (mlx_xpm_file_to_image(mlx, COLL17, &dim, &dim));
	if (coll == 18)
		return (mlx_xpm_file_to_image(mlx, COLL18, &dim, &dim));
	if (coll == 19)
		return (mlx_xpm_file_to_image(mlx, COLL19, &dim, &dim));
	if (coll == 20)
		return (mlx_xpm_file_to_image(mlx, COLL20, &dim, &dim));
	if (coll == 21)
		return (mlx_xpm_file_to_image(mlx, COLL21, &dim, &dim));
	return (collectible3(mlx, coll, dim));
}

static void	*collectibles(void *mlx, int dim)
{
	int	coll;

	coll = rand() % 34;
	if (coll == 0)
		return (mlx_xpm_file_to_image(mlx, COLL00, &dim, &dim));
	if (coll == 1)
		return (mlx_xpm_file_to_image(mlx, COLL01, &dim, &dim));
	if (coll == 2)
		return (mlx_xpm_file_to_image(mlx, COLL02, &dim, &dim));
	if (coll == 3)
		return (mlx_xpm_file_to_image(mlx, COLL03, &dim, &dim));
	if (coll == 4)
		return (mlx_xpm_file_to_image(mlx, COLL04, &dim, &dim));
	if (coll == 5)
		return (mlx_xpm_file_to_image(mlx, COLL05, &dim, &dim));
	if (coll == 6)
		return (mlx_xpm_file_to_image(mlx, COLL06, &dim, &dim));
	if (coll == 7)
		return (mlx_xpm_file_to_image(mlx, COLL07, &dim, &dim));
	if (coll == 8)
		return (mlx_xpm_file_to_image(mlx, COLL08, &dim, &dim));
	if (coll == 9)
		return (mlx_xpm_file_to_image(mlx, COLL09, &dim, &dim));
	return (collectibles2(mlx, coll, dim));
}

static void	*wall_management(void *mlx, int dim, t_coord a, t_graphics *m)
{
	if ((*m).map[a.y][a.x + 1] != '1' && (*m).map[a.y][a.x - 1] != '1'
		&& (*m).map[a.y + 1][a.x] != '1' && (*m).map[a.y - 1][a.x] != '1')
	{
		if (rand() % 2 == 0)
			return (mlx_xpm_file_to_image(mlx, STONE, &dim, &dim));
		else
			return (mlx_xpm_file_to_image(mlx, SKULL, &dim, &dim));
	}
	else
		return (mlx_xpm_file_to_image(mlx, WALL, &dim, &dim));
}

void	*get_image(void *mlx, char symbol, t_coord a, t_graphics *m)
{
	int		dim;
	void	*image;

	dim = DIM;
	if (symbol == '0')
		image = mlx_xpm_file_to_image(mlx, FLOOR, &dim, &dim);
	if (symbol == '1')
		image = wall_management(mlx, dim, a, m);
	if (symbol == 'C')
		image = collectibles(mlx, dim);
	if (symbol == 'E')
		image = mlx_xpm_file_to_image(mlx, E1, &dim, &dim);
	if (symbol == 'P')
		image = image_hero(mlx, dim, m);
	if (symbol == 'Q' || symbol == 'R' || symbol == 'S' || symbol == 'T'
		|| symbol == 'U' || symbol == 'V' || symbol == 'W' || symbol == 'X'
		|| symbol == 'Y' || symbol == 'N' || symbol == 'M' || symbol == 'O')
		image = get_image2(mlx, symbol, dim);
	return (image);
}
