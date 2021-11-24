/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:49:17 by cjang             #+#    #+#             */
/*   Updated: 2021/11/21 19:05:27 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sol_move_player(t_param *par, int next_x, int next_y)
{
	char	next;

	next = par->map[next_y][next_x];
	if (next == '1')
		return ;
	else if ((next == 'E' || next == 'e') && par->c_num != 0)
		return ;
	if (next == 'C' || next == 'c')
		par->c_num--;
	else if ((next == 'E' || next == 'e') && par->c_num == 0)
	{
		printf("move : %d - exit success!\n", ++par->move_num);
		exit(0);
	}
	par->map[par->player_y][par->player_x] = '0';
	par->map[next_y][next_x] = 'P';
	fix_map_image(par, par->player_x, par->player_y, '0');
	fix_map_image(par, next_x, next_y, 'P');
	par->player_x = next_x;
	par->player_y = next_y;
	par->move_num++;
	printf("move : %d\n", par->move_num);
}

static int	key_branch(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(par->mlx_ptr, par->win_ptr);
		exit(0);
	}
	else if (keycode == KEY_A)
		sol_move_player(par, par->player_x - 1, par->player_y);
	else if (keycode == KEY_S)
		sol_move_player(par, par->player_x, par->player_y + 1);
	else if (keycode == KEY_D)
		sol_move_player(par, par->player_x + 1, par->player_y);
	else if (keycode == KEY_W)
		sol_move_player(par, par->player_x, par->player_y - 1);
	return (0);
}

static int	sol_close(t_param *par)
{
	mlx_destroy_window(par->mlx_ptr, par->win_ptr);
	exit(0);
	return (0);
}

void	mlx_execution(t_map *map_info)
{
	t_param	param;

	init_t_param(&param, map_info);
	init_t_param_img_ptr(&param);
	init_map_image(&param);
	mlx_key_hook(param.win_ptr, key_branch, &param);
	mlx_hook(param.win_ptr, 17, 0, sol_close, &param);
	mlx_loop(param.mlx_ptr);
}
