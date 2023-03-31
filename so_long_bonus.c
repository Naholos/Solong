/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:06:03 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 12:22:01 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		cep1fd[5];
	int		columns;
	int		rows;

	i = 0;
	while (i < 3)
		cep1fd[i++] = 0;
	parameters_error(argc);
	cep1fd[4] = map_file_errors(argv[1]);
	columns = chck_first_row(cep1fd[4]);
	rows = chck_next_rows(columns, cep1fd);
	if (rows >= MAX_HEIGHT)
	{
		printf("Error\nMap to high for this screen\n");
		chck_close(cep1fd[4]);
	}
	draw_map(read_map(argv[1], rows), columns - 1, rows + 1, cep1fd[0]);
	return (0);
}
