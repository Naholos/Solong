/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:06:03 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 09:39:50 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "./include/so_long_bonus.h"

void	*get_image2(void *mlx, char symbol, int dim)
{
	if (symbol == 'Q')
		return (mlx_xpm_file_to_image(mlx, SKD1, &dim, &dim));
	if (symbol == 'R')
		return (mlx_xpm_file_to_image(mlx, SKD2, &dim, &dim));
	if (symbol == 'S')
		return (mlx_xpm_file_to_image(mlx, SKD3, &dim, &dim));
	if (symbol == 'T')
		return (mlx_xpm_file_to_image(mlx, SKU1, &dim, &dim));
	if (symbol == 'U')
		return (mlx_xpm_file_to_image(mlx, SKU2, &dim, &dim));
	if (symbol == 'V')
		return (mlx_xpm_file_to_image(mlx, SKU3, &dim, &dim));
	if (symbol == 'M')
		return (mlx_xpm_file_to_image(mlx, SKR1, &dim, &dim));
	if (symbol == 'N')
		return (mlx_xpm_file_to_image(mlx, SKR2, &dim, &dim));
	if (symbol == 'O')
		return (mlx_xpm_file_to_image(mlx, SKR3, &dim, &dim));
	if (symbol == 'W')
		return (mlx_xpm_file_to_image(mlx, SKL1, &dim, &dim));
	if (symbol == 'X')
		return (mlx_xpm_file_to_image(mlx, SKL2, &dim, &dim));
	else
		return (mlx_xpm_file_to_image(mlx, SKL3, &dim, &dim));
}

void	killed(void)
{	
	printf("An skeleton has killed you. GAME OVER\n");
	exit (0);
}

int	put_enemies(t_graphics *m)
{
	int		i;
	int		max;
	t_coord	a;
	t_coord	b;

	a.x = 0;
	a.y = 0;
	max = (((*m).height * (*m).width) - 100) / 200;
	i = 0;
	while (i < max)
	{
		while ((*m).map[a.y][a.x] != '0')
		{
			a.y = rand() % (*m).height;
			a.x = rand() % (*m).width;
		}		
		(*m).map[a.y][a.x] = 'S';
		b = map2window(a);
		(*m).img = get_image((*m).mlx, 'S', b, m);
		mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, b.x, b.y);
		mlx_destroy_image((*m).mlx, (*m).img);
		i++;
	}
	return (-1);
}
