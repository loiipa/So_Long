/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:49:17 by cjang             #+#    #+#             */
/*   Updated: 2021/10/06 21:34:17 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_t_param(t_param *param)
{
	param->size_x = 1024;
	param->size_y = 768;
	param->move_x = 0;
	param->move_y = 0;
	param->r = 300;
}

static void	make_circle(t_param *par)
{
	for (int i = 0; i < par->size_x; i++)
	{
		for (int j = 0; j < par->size_y; j++)
		{
			mlx_pixel_put(par->ptr, par->ptr_window, i, j, 0x00646464);
			if (pow(200 + par->move_x - i, 2) + pow(300 + par->move_y- j, 2) < pow(par->r / 2, 2))
				mlx_pixel_put(par->ptr, par->ptr_window, i, j, 0x00006464);
			else if (pow(700 + par->move_x - i, 2) + pow(300 + par->move_y - j, 2) < pow(par->r, 2))
				mlx_pixel_put(par->ptr, par->ptr_window, i, j, 0x00000064);
			//mlx_string_put(ptr, ptr_window, 0, 0, 0x00006464, "cjang_world");
		}
	}
}

static int	ft_exit(int keycode, void *param)
{
	t_param *par;

	par = param;
	printf("input keycode : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	//asdw
	else if (keycode == 0)
		par->move_x -= 10;
	else if (keycode == 1)
		par->move_y += 10;
	else if (keycode == 2)
		par->move_x += 10;
	else if (keycode == 13)
		par->move_y -= 10;
	else if (keycode == 12)
		par->r += 10;
	else if (keycode == 14)
		par->r -= 10;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || keycode == 12 || keycode == 14)
		make_circle(param);
	return (1);
}

void	mlx_test(void)
{
	t_param param;

	init_t_param(&param);
	param.ptr = mlx_init();
	param.ptr_window = mlx_new_window(param.ptr, param.size_x, param.size_y, "cjang_miniRT");
	make_circle(&param);
	mlx_key_hook(param.ptr_window, ft_exit ,&param);
	mlx_loop(param.ptr);
}

//gcc -lmlx -framework OpenGL -framework AppKit -lz mlx_test.c

// 빨간버튼 클릭시 종료되는 hook -> mlx_hook(win_ptr, 17, 0, (실행될함수), (넘겨줄인자값));
