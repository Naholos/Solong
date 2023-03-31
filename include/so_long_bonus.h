/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:21:56 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/20 09:35:12 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PLAYERD1 "./imgs/herod1.xpm"
# define PLAYERD2 "./imgs/herod2.xpm"
# define PLAYERD3 "./imgs/herod3.xpm"
# define PLAYERL1 "./imgs/herol1.xpm"
# define PLAYERL2 "./imgs/herol2.xpm"
# define PLAYERL3 "./imgs/herol3.xpm"
# define PLAYERR1 "./imgs/heror1.xpm"
# define PLAYERR2 "./imgs/heror2.xpm"
# define PLAYERR3 "./imgs/heror3.xpm"
# define PLAYERU1 "./imgs/herou1.xpm"
# define PLAYERU2 "./imgs/herou2.xpm"
# define PLAYERU3 "./imgs/herou3.xpm"

# define SKD1 "./imgs/enemyd1.xpm"
# define SKD2 "./imgs/enemyd2.xpm"
# define SKD3 "./imgs/enemyd3.xpm"
# define SKL1 "./imgs/enemyl1.xpm"
# define SKL2 "./imgs/enemyl2.xpm"
# define SKL3 "./imgs/enemyl3.xpm"
# define SKR1 "./imgs/enemyr1.xpm"
# define SKR2 "./imgs/enemyr2.xpm"
# define SKR3 "./imgs/enemyr3.xpm"
# define SKU1 "./imgs/enemyu1.xpm"
# define SKU2 "./imgs/enemyu2.xpm"
# define SKU3 "./imgs/enemyu3.xpm"

# define ZERO	"./imgs/0.xpm"
# define ONE	"./imgs/1.xpm"
# define TWO	"./imgs/2.xpm"
# define THREE	"./imgs/3.xpm"
# define FOUR	"./imgs/4.xpm"
# define FIVE	"./imgs/5.xpm"
# define SIX	"./imgs/6.xpm"
# define SEVEN	"./imgs/7.xpm"
# define EIGHT	"./imgs/8.xpm"
# define NINE	"./imgs/9.xpm"

# define E2		"./imgs/exit2.xpm"
# define SKULL	"./imgs/skull.xpm"
# define STEPS	"./imgs/steps.xpm"
# define STONE	"./imgs/stone.xpm"

int		put_enemies(t_graphics *m);
int		render_next_frame(t_graphics *m);

t_coord	update_coord(int x, int y, t_coord b);

void	*get_image2(void *mlx, char symbol, int dim);
void	hero_way(int value, t_graphics *m);
void	*image_hero(void *mlx, int dim, t_graphics *m);
void	killed(void);
void	update_score(t_graphics *m);

#endif
