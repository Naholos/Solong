/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:00:28 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 09:37:17 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "./include/so_long_bonus.h"

void	*image_hero(void *mlx, int dim, t_graphics *m)
{
	if ((*m).movement == 1)
		return (mlx_xpm_file_to_image(mlx, PLAYERL1, &dim, &dim));
	else if ((*m).movement == 2)
		return (mlx_xpm_file_to_image(mlx, PLAYERL2, &dim, &dim));
	else if ((*m).movement == 3)
		return (mlx_xpm_file_to_image(mlx, PLAYERL3, &dim, &dim));
	else if ((*m).movement == 4)
		return (mlx_xpm_file_to_image(mlx, PLAYERD1, &dim, &dim));
	else if ((*m).movement == 5)
		return (mlx_xpm_file_to_image(mlx, PLAYERD2, &dim, &dim));
	else if ((*m).movement == 6)
		return (mlx_xpm_file_to_image(mlx, PLAYERD3, &dim, &dim));
	else if ((*m).movement == 7)
		return (mlx_xpm_file_to_image(mlx, PLAYERR1, &dim, &dim));
	else if ((*m).movement == 8)
		return (mlx_xpm_file_to_image(mlx, PLAYERR2, &dim, &dim));
	else if ((*m).movement == 9)
		return (mlx_xpm_file_to_image(mlx, PLAYERR3, &dim, &dim));
	else if ((*m).movement == 10)
		return (mlx_xpm_file_to_image(mlx, PLAYERU1, &dim, &dim));
	else if ((*m).movement == 11)
		return (mlx_xpm_file_to_image(mlx, PLAYERU2, &dim, &dim));
	else
		return (mlx_xpm_file_to_image(mlx, PLAYERU3, &dim, &dim));
}

void	hero_way(int value, t_graphics *m)
{
	if ((*m).movement == value || (*m).movement == value + 1)
		(*m).movement++;
	else
		(*m).movement = value;
}

static void	get_number2(char *number, t_graphics *m, int dim, int i)
{
	if (number[i - 1] == '5')
		(*m).img = mlx_xpm_file_to_image((*m).mlx, FIVE, &dim, &dim);
	if (number[i - 1] == '6')
		(*m).img = mlx_xpm_file_to_image((*m).mlx, SIX, &dim, &dim);
	if (number[i - 1] == '7')
		(*m).img = mlx_xpm_file_to_image((*m).mlx, SEVEN, &dim, &dim);
	if (number[i - 1] == '8')
		(*m).img = mlx_xpm_file_to_image((*m).mlx, EIGHT, &dim, &dim);
	if (number[i - 1] == '9')
		(*m).img = mlx_xpm_file_to_image((*m).mlx, NINE, &dim, &dim);
}

static void	get_number(char *number, t_graphics *m, int dim)
{
	int	i;

	i = ft_strlen(number) + 1;
	while (--i > 0)
	{
		if (number[i - 1] == '0')
			(*m).img = mlx_xpm_file_to_image((*m).mlx, ZERO, &dim, &dim);
		else if (number[i - 1] == '1')
			(*m).img = mlx_xpm_file_to_image((*m).mlx, ONE, &dim, &dim);
		else if (number[i - 1] == '2')
			(*m).img = mlx_xpm_file_to_image((*m).mlx, TWO, &dim, &dim);
		else if (number[i - 1] == '3')
			(*m).img = mlx_xpm_file_to_image((*m).mlx, THREE, &dim, &dim);
		else if (number[i - 1] == '4')
			(*m).img = mlx_xpm_file_to_image((*m).mlx, FOUR, &dim, &dim);
		else
			get_number2(number, m, dim, i);
		mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, 10 * (i + 1), 14);
		mlx_destroy_image((*m).mlx, (*m).img);
	}
}

void	update_score(t_graphics *m)
{
	char	*number;
	int		dim;

	dim = DIM;
	(*m).img = mlx_xpm_file_to_image((*m).mlx, STEPS, &dim, &dim);
	mlx_put_image_to_window((*m).mlx, (*m).win, (*m).img, 20, 2);
	mlx_destroy_image((*m).mlx, (*m).img);
	if ((*m).steps == 2147483647)
	{
		printf("Maximum number of allowed steps exceeded. Game over\n");
		exit (0);
	}
	(*m).steps++;
	number = ft_itoa((*m).steps);
	get_number(number, m, DIM);
	free(number);
}
