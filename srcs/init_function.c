/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:19:53 by cjang             #+#    #+#             */
/*   Updated: 2021/11/20 18:33:47 by cjang            ###   ########.fr       */
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
	param->img_ptr_p = mlx_png_file_to_image(param->mlx_ptr, \
	"./image/pum.png", &width, &height);
	param->img_ptr_c = mlx_png_file_to_image(param->mlx_ptr, \
	"./image/candy.png", &width, &height);
	param->img_ptr_e = mlx_png_file_to_image(param->mlx_ptr, \
	"./image/exit.png", &width, &height);
	param->img_ptr_1 = mlx_png_file_to_image(param->mlx_ptr, \
	"./image/wall.png", &width, &height);
	param->img_ptr_0 = mlx_png_file_to_image(param->mlx_ptr, \
	"./image/tile.png", &width, &height);
}

void	resize_map(t_map *map_info)
{
	char	**map_tmp;
	int		i;

	i = 0;
	map_tmp = (char **)malloc(map_info->map_size * 2 * sizeof(char *));
	if (!map_tmp)
	{
		// 기존의 것 할당해제하는게 깔-끔
		error_user("malloc fail\n");
	}
	while (i < map_info->map_size)
	{
		map_tmp[i] = map_info->map[i];
		i++;
	}
	free(map_info->map);
	map_info->map = map_tmp;
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
	map_info->map_size = MALLOC_SIZE;
	map_info->map = (char **)malloc(map_info->map_size * sizeof(char *));
	if (!map_info->map)
		error_user("malloc fail\n");
	map_info->map_flag = 0;
}
