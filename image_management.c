/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:38:38 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/19 13:05:57 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	*collectibles3(void *mlx, int y, int dim)
{
	if (y > 55 && y <= 57)
		return (mlx_xpm_file_to_image(mlx, COLL22, &dim, &dim));
	else if (y > 57 && y <= 60)
		return (mlx_xpm_file_to_image(mlx, COLL23, &dim, &dim));
	else if (y > 60 && y <= 62)
		return (mlx_xpm_file_to_image(mlx, COLL24, &dim, &dim));
	else if (y > 62 && y <= 65)
		return (mlx_xpm_file_to_image(mlx, COLL25, &dim, &dim));
	else if (y > 65 && y <= 67)
		return (mlx_xpm_file_to_image(mlx, COLL26, &dim, &dim));
	else if (y > 67 && y <= 70)
		return (mlx_xpm_file_to_image(mlx, COLL27, &dim, &dim));
	else if (y > 70 && y <= 72)
		return (mlx_xpm_file_to_image(mlx, COLL28, &dim, &dim));
	else if (y > 72 && y <= 75)
		return (mlx_xpm_file_to_image(mlx, COLL29, &dim, &dim));
	else if (y > 75 && y <= 77)
		return (mlx_xpm_file_to_image(mlx, COLL30, &dim, &dim));
	else if (y > 77 && y <= 78)
		return (mlx_xpm_file_to_image(mlx, COLL31, &dim, &dim));
	else
		return (mlx_xpm_file_to_image(mlx, COLL32, &dim, &dim));
}

static void	*collectibles2(void *mlx, int y, int dim)
{
	if (y > 27 && y <= 29)
		return (mlx_xpm_file_to_image(mlx, COLL11, &dim, &dim));
	else if (y > 29 && y <= 32)
		return (mlx_xpm_file_to_image(mlx, COLL12, &dim, &dim));
	else if (y > 32 && y <= 34)
		return (mlx_xpm_file_to_image(mlx, COLL13, &dim, &dim));
	else if (y > 34 && y <= 37)
		return (mlx_xpm_file_to_image(mlx, COLL14, &dim, &dim));
	else if (y > 37 && y <= 39)
		return (mlx_xpm_file_to_image(mlx, COLL15, &dim, &dim));
	else if (y > 39 && y <= 42)
		return (mlx_xpm_file_to_image(mlx, COLL16, &dim, &dim));
	else if (y > 42 && y <= 45)
		return (mlx_xpm_file_to_image(mlx, COLL17, &dim, &dim));
	else if (y > 44 && y <= 47)
		return (mlx_xpm_file_to_image(mlx, COLL18, &dim, &dim));
	else if (y > 47 && y <= 50)
		return (mlx_xpm_file_to_image(mlx, COLL19, &dim, &dim));
	else if (y > 49 && y <= 52)
		return (mlx_xpm_file_to_image(mlx, COLL20, &dim, &dim));
	else if (y > 52 && y <= 55)
		return (mlx_xpm_file_to_image(mlx, COLL22, &dim, &dim));
	else
		return (collectibles3(mlx, y, dim));
}

static void	*collectibles(void *mlx, int y, int dim)
{
	if (y > 0 && y <= 2)
		return (mlx_xpm_file_to_image(mlx, COLL00, &dim, &dim));
	else if (y > 2 && y <= 5)
		return (mlx_xpm_file_to_image(mlx, COLL01, &dim, &dim));
	else if (y > 5 && y <= 7)
		return (mlx_xpm_file_to_image(mlx, COLL02, &dim, &dim));
	else if (y > 7 && y <= 10)
		return (mlx_xpm_file_to_image(mlx, COLL03, &dim, &dim));
	else if (y > 10 && y <= 12)
		return (mlx_xpm_file_to_image(mlx, COLL04, &dim, &dim));
	else if (y > 12 && y <= 15)
		return (mlx_xpm_file_to_image(mlx, COLL05, &dim, &dim));
	else if (y > 15 && y <= 17)
		return (mlx_xpm_file_to_image(mlx, COLL06, &dim, &dim));
	else if (y > 17 && y <= 20)
		return (mlx_xpm_file_to_image(mlx, COLL07, &dim, &dim));
	else if (y > 20 && y <= 22)
		return (mlx_xpm_file_to_image(mlx, COLL08, &dim, &dim));
	else if (y > 22 && y <= 25)
		return (mlx_xpm_file_to_image(mlx, COLL09, &dim, &dim));
	else if (y > 25 && y <= 27)
		return (mlx_xpm_file_to_image(mlx, COLL10, &dim, &dim));
	else
		return (collectibles2(mlx, y, dim));
}

static void	*wall_management(void *mlx, int dim, t_coord a, t_graphics *m)
{
	(void)a;
	(void)(*m);
	return (mlx_xpm_file_to_image(mlx, WALL, &dim, &dim));
}

void	*get_image(void *mlx, char symbol, t_coord a, t_graphics *m)
{
	int		dim;
	void	*image;

	(void)(*m);
	dim = DIM;
	if (symbol == '0')
		image = mlx_xpm_file_to_image(mlx, FLOOR, &dim, &dim);
	if (symbol == '1')
		image = wall_management(mlx, dim, a, m);
	if (symbol == 'C')
		image = collectibles(mlx, a.x, dim);
	if (symbol == 'E')
		image = mlx_xpm_file_to_image(mlx, E1, &dim, &dim);
	if (symbol == 'P')
		image = mlx_xpm_file_to_image(mlx, PLAYERD1, &dim, &dim);
	return (image);
}
