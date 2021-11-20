/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:19:11 by cjang             #+#    #+#             */
/*   Updated: 2021/11/20 17:49:34 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SQUARE_SIZE 32
# define MAP_SIZE 100
# define MALLOC_SIZE 128

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx_opengl/mlx.h"
# include <math.h>

typedef struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_p;
	void	*img_ptr_c;
	void	*img_ptr_e;
	void	*img_ptr_1;
	void	*img_ptr_0;
	int		size_x;
	int		size_y;
	char	**map;
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
	char	**map;
	int		map_size;
	int		map_flag;
}t_map;

void	map_size_check(t_map *map_info, int fd);
void	map_vaid_check(t_map *m);

void	mlx_execution(t_map *map_info);

void	fix_map_image(t_param *p, int fix_x, int fix_y, char c);
void	init_map_image(t_param *p);

void	init_t_param(t_param *param, t_map *map_info);
void	init_t_param_img_ptr(t_param *param);
void	init_t_map(t_map *map_info);

void	error_user(char *s);
void	error_system(void);

#endif
