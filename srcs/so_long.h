/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:19:11 by cjang             #+#    #+#             */
/*   Updated: 2021/11/21 19:55:55 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SQUARE_SIZE 32
# define MALLOC_SIZE 2

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_opengl/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
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
	int		map_flag;
	int		map_size;
	char	**map;
}t_map;

void	init_t_param(t_param *param, t_map *map_info);
void	init_t_param_img_ptr(t_param *param);
void	init_t_map(t_map *map_info);
void	init_map(t_map *map_info, int fd);

void	check_map_size(int i, t_map *map_info);
void	check_map_vaid(t_map *m);

void	mlx_execution(t_map *map_info);

void	fix_map_image(t_param *p, int fix_x, int fix_y, char c);
void	init_map_image(t_param *p);

char	**free_2d_array(char **arr, int i);
void	resize_map(t_map *map_info);

void	error_user(char *s);
void	error_system(void);

#endif
