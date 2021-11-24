/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:19:53 by cjang             #+#    #+#             */
/*   Updated: 2021/11/21 20:52:27 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_t_param(t_param *param, t_map *map_info)
{
	param->size_x = map_info->x;
	param->size_y = map_info->y;
	param->player_x = map_info->player_x;
	param->player_y = map_info->player_y;
	param->c_num = map_info->c_num;
	param->map = map_info->map;
	param->move_num = 0;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->size_x * \
	SQUARE_SIZE, param->size_y * SQUARE_SIZE, "cjang_So_Long");
}

void	init_t_param_img_ptr(t_param *param)
{
	int		width;
	int		height;

	width = SQUARE_SIZE;
	height = SQUARE_SIZE;
	param->img_ptr_p = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./image/pum.xpm", &width, &height);
	param->img_ptr_c = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./image/candy.xpm", &width, &height);
	param->img_ptr_e = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./image/exit.xpm", &width, &height);
	param->img_ptr_1 = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./image/wall.xpm", &width, &height);
	param->img_ptr_0 = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./image/tile.xpm", &width, &height);
}

void	init_t_map(t_map *map_info)
{
	map_info->x = 0;
	map_info->y = 0;
	map_info->player_x = 0;
	map_info->player_y = 0;
	map_info->first_x = 0;
	map_info->p_num = 0;
	map_info->c_num = 0;
	map_info->e_num = 0;
}

static void	init_t_map_about_map(t_map *map_info)
{
	map_info->map_flag = 0;
	if (MALLOC_SIZE < 2)
		error_user("check MALLOC_SIZE in so_long.h\n");
	map_info->map_size = MALLOC_SIZE;
	map_info->map = (char **)malloc(map_info->map_size * sizeof(char *));
	if (!map_info->map)
		error_user("malloc fail\n");
}

void	init_map(t_map *map_info, int fd)
{
	int		gnl;
	int		i;
	char	*line;

	init_t_map_about_map(map_info);
	i = 0;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1)
			error_user("GNL Error\n");
		if (i == map_info->map_size)
			resize_map(map_info);
		map_info->map[i] = line;
		check_map_size(i++, map_info);
	}
	if (i == map_info->map_size)
		resize_map(map_info);
	map_info->map[i] = NULL;
	map_info->x = map_info->first_x;
}
