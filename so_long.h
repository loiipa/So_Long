/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:19:11 by cjang             #+#    #+#             */
/*   Updated: 2021/10/28 22:35:15 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SQUARE_SIZE 50
# define MAP_SIZE 100

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx_opengl/mlx.h"
// # include <mlx.h>
# include <math.h>

typedef struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_p;
	int		size_x;
	int		size_y;
	char	(*map)[MAP_SIZE];
	int		player_x;
	int		player_y;
	int		c_num;
	int		move_num;
}t_param;

typedef struct s_map
{
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		first_x;
	int		p_num;
	int		c_num;
	int		e_num;
	char	map[MAP_SIZE][MAP_SIZE];
}t_map;

void	map_size_check(t_map *map_info, int *fd);
void	map_vaid_check(t_map *m);

void	mlx_test(t_map *map_info);

void	error_user(char *s);
void	error_system(void);

void	init_t_param(t_param *param, t_map *map_info);
void	init_t_param_img_ptr(t_param *param);
void	init_t_map(t_map *map_info);

#endif
