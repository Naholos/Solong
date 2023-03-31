/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values_and_params_errors_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:07:28 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 08:44:08 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	badsymerr(char *x, char *y, char symbol, int fd_map)
{
	printf("Error\nUnknown symbol %c at row %s, column %s\n", symbol, x, y);
	chck_close(fd_map);
}

static void	multiple_players_error(int *cep1fd)
{
	char	*players;

	players = ft_itoa(cep1fd[2]);
	printf("Error\nOnly 1 player allowed, "
		"%s players defined\n", players);
	free(players);
	chck_close(cep1fd[4]);
}

void	chck_symbols_errors(int *cep1fd, char *next_row)
{
	if (cep1fd[0] == 0)
	{
		free(next_row);
		map_value_errors(3, cep1fd[4]);
	}
	if (cep1fd[1] == 0)
	{
		free(next_row);
		map_value_errors(4, cep1fd[4]);
	}
	if (cep1fd[2] == 0)
	{
		free(next_row);
		map_value_errors(2, cep1fd[4]);
	}
	if (cep1fd[2] > 1)
	{
		free(next_row);
		multiple_players_error(cep1fd);
	}
}

void	map_value_errors(size_t index, int fd_map)
{
	if (index == 1)
		printf("Error\nEmpty map\n");
	if (index == 2)
		printf("Error\nNo player initial position defined\n");
	if (index == 3)
		printf("Error\nAt least one collectible is required\n");
	if (index == 4)
		printf("Error\nAt least one exit is required\n");
	chck_close(fd_map);
}

void	parameters_error(int parameters_number)
{
	if (parameters_number != 2)
	{
		printf("Error\nUsage: so long filemap, ");
		if (parameters_number < 2)
			printf("no filemap provided\n");
		else
			printf("only one parameter allowed\n");
		exit (1);
	}
}
