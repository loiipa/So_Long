/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:49:17 by cjang             #+#    #+#             */
/*   Updated: 2021/10/07 21:53:56 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_t_param(t_param *param, t_map *map_info)
{
	param->size_x = map_info->x * SQUARE_SIZE;
	param->size_y = map_info->y * SQUARE_SIZE;
	param->player_x = map_info->player_x;
	param->player_y = map_info->player_y;
	param->c_num = map_info->c_num;
	param->map = map_info->map;
	param->move_num = 0;
}

static void	make_map_image(t_param *p)
{
	int		cur_x;
	int		cur_y;
	char	c;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < p->size_y)
	{
		cur_x = 0;
		while (cur_x < p->size_x)
		{
			c = p->map[cur_x / SQUARE_SIZE][cur_y / SQUARE_SIZE];
			if (c == '1')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00646464);
			else if (c == '0')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00000000);
			else if (c == 'P' || c == 'p')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00640000);
			else if (c == 'E' || c == 'e')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00006400);
			else if (c == 'C' || c == 'c')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00646400);
			cur_x++;
		}
		cur_y++;
	}
}

static void	fix_map_image(t_param *p, int fix_x, int fix_y, char c)
{
	int		cur_x;
	int		cur_y;

	cur_y = fix_y * SQUARE_SIZE;
	if (c == 'P' || c == 'p')
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, fix_x * SQUARE_SIZE, fix_y * SQUARE_SIZE);
		return ;
	}
	while (cur_y < fix_y * SQUARE_SIZE + SQUARE_SIZE)
	{
		cur_x = fix_x * SQUARE_SIZE;
		while (cur_x < fix_x * SQUARE_SIZE + SQUARE_SIZE)
		{
			if (c == '1')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00646464);
			else if (c == '0')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00000000);
			else if (c == 'P' || c == 'p')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00640000);
			else if (c == 'E' || c == 'e')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00006400);
			else if (c == 'C' || c == 'c')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, cur_x, cur_y, 0x00646400);
			cur_x++;
		}
		cur_y++;
	}
}

static void	sl_move_player(int keycode, t_param *par, int next_x, int next_y)
{
	if (par->map[next_x][next_y] == '1')
		return ;
	else if ((par->map[next_x][next_y] == 'E' || par->map[next_x][next_y] == 'e') && par->c_num != 0)
		return ;
	if (par->map[next_x][next_y] == 'C' || par->map[next_x][next_y] == 'c')
		par->c_num--;
	else if ((par->map[next_x][next_y] == 'E' || par->map[next_x][next_y] == 'e') && par->c_num == 0)
	{
		printf("move : %d - exit success!\n", ++par->move_num);
		exit(0);
	}
	par->map[par->player_x][par->player_y] = '0';
	par->map[next_x][next_y] = 'P';
	fix_map_image(par, par->player_x, par->player_y, '0');
	fix_map_image(par, next_x, next_y, 'P');
	par->player_x = next_x;
	par->player_y = next_y;
	par->move_num++;
	printf("move : %d\n", par->move_num);
}

static int	ft_exit(int keycode, void *param)
{
	t_param *par;

	par = param;
	// printf("input keycode : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	//asdw
	else if (keycode == 0)
	{
		sl_move_player(keycode, par, par->player_x - 1, par->player_y);
	}
	else if (keycode == 1)
	{
		sl_move_player(keycode, par, par->player_x, par->player_y + 1);
	}
	else if (keycode == 2)
	{
		sl_move_player(keycode, par, par->player_x + 1, par->player_y);
	}
	else if (keycode == 13)
	{
		sl_move_player(keycode, par, par->player_x, par->player_y - 1);
	}
	return (1);
}

void	mlx_test(t_map *map_info)
{
	t_param param;

	init_t_param(&param, map_info);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.size_x, param.size_y, "cjang_So_Long");
	make_map_image(&param);
	//
	int		i = SQUARE_SIZE;
	param.img_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "./image/100won.xpm", &i, &i);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img_ptr, 0, 0);
	//
	mlx_key_hook(param.win_ptr, ft_exit, &param);
	mlx_loop(param.mlx_ptr);
}

//gcc -lmlx -framework OpenGL -framework AppKit -lz mlx_test.c map_checker.c

// 빨간버튼 클릭시 종료되는 hook -> mlx_hook(win_ptr, 17, 0, (실행될함수), (넘겨줄인자값));
