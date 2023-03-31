/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:21:56 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 10:21:23 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define LEFT	0	
# define RIGHT	2
# define UP		1
# define DOWN	13
# define SCAPE	53

# define COLL00	"./imgs/coll00.xpm"
# define COLL01	"./imgs/coll01.xpm"
# define COLL02	"./imgs/coll02.xpm"
# define COLL03	"./imgs/coll03.xpm"
# define COLL04	"./imgs/coll04.xpm"
# define COLL05	"./imgs/coll05.xpm"
# define COLL06	"./imgs/coll06.xpm"
# define COLL07	"./imgs/coll07.xpm"
# define COLL08	"./imgs/coll08.xpm"
# define COLL09	"./imgs/coll09.xpm"
# define COLL10	"./imgs/coll10.xpm"
# define COLL11	"./imgs/coll11.xpm"
# define COLL12	"./imgs/coll12.xpm"
# define COLL13	"./imgs/coll13.xpm"
# define COLL14	"./imgs/coll14.xpm"
# define COLL15	"./imgs/coll15.xpm"
# define COLL16	"./imgs/coll16.xpm"
# define COLL17	"./imgs/coll17.xpm"
# define COLL18	"./imgs/coll18.xpm"
# define COLL19	"./imgs/coll19.xpm"
# define COLL20	"./imgs/coll20.xpm"
# define COLL21	"./imgs/coll21.xpm"
# define COLL22	"./imgs/coll22.xpm"
# define COLL23	"./imgs/coll23.xpm"
# define COLL24	"./imgs/coll24.xpm"
# define COLL25	"./imgs/coll25.xpm"
# define COLL26	"./imgs/coll26.xpm"
# define COLL27	"./imgs/coll27.xpm"
# define COLL28	"./imgs/coll28.xpm"
# define COLL29	"./imgs/coll29.xpm"
# define COLL30	"./imgs/coll30.xpm"
# define COLL31	"./imgs/coll31.xpm"
# define COLL32	"./imgs/coll32.xpm"

# define E1			"./imgs/exit1.xpm"
# define FLOOR		"./imgs/floor.xpm"
# define PLAYERD1	"./imgs/herod1.xpm"
# define WALL		"./imgs/wall.xpm"

# define DIM        32
# define MAX_WIDTH  80
# define MAX_HEIGHT 44

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_graphics
{
	char	**map;
	int		width;
	int		height;
	int		movement;
	int		colls;
	int		steps;
	void	*img;
	void	*mlx;
	void	*win;
}	t_graphics;

char	*ft_itoa(int n);
char	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1, size_t len);
char	*ft_strjoin(char *s1, char *s2, size_t len);
char	*get_next_line(int fd);
char	**read_map(char *map_name, int rows);

int		chck_close(int fd_map);
int		chck_first_row(int fd_map);
int		chck_next_rows(int row_len, int *cep1fd);
int		chck_open(int fd_map);
int		chck_read(int reading, int fd_map);
int		close_window(t_graphics *m);
int		map_file_errors(char *map_name);
int		map_shape_errors(char *next_row, int row_len, int fd_map, int y);

size_t	ft_find_line_end(char const *buff);
size_t	ft_strlen(const char *s);

t_coord	init_coord(int x, int y);
t_coord	find_element(char **map, char element, int row, t_coord a);
t_coord	map2window(t_coord a);

void	badsymerr(char *x, char *y, char symbol, int fd_map);
void	chck_symbols_errors(int *cep1fd, char *next_row);
void	draw_map(char **map, int columns, int rows, int colls);
void	empty_row_error(char *next_row, int fd_map, char *row);
void	extension_error(void);
void	final_row_edge_error(char *y, int fd_map, char *row);
void	*get_image(void *mlx, char symbol, t_coord a, t_graphics *m);
void	init(size_t *line_end, size_t *line_length, char **line, char **line2);
void	init_map(t_graphics *m, int columns, int rows, int colls);
void	map_value_errors(size_t index, int fd_map);
void	parameters_error(int parameters_number);
void	put_image(t_graphics m);
void	update_player_pos(t_graphics *m, t_coord a, t_coord b);
void	wredge(char *x, char *y, int fd_map, char *row);

#endif
