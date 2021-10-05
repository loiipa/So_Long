/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:49:17 by cjang             #+#    #+#             */
/*   Updated: 2021/10/05 20:06:04 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

int		main(void)
{
	void	*ptr;
	void	*ptr_window;
	int		size_x;
	int		size_y;
	int		r;

	size_x = 1024;
	size_y = 768;
	r = 300;
	ptr = mlx_init();
	ptr_window = mlx_new_window(ptr, size_x, size_y, "cjang_miniRT");
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			mlx_pixel_put(ptr, ptr_window, i, j, 0x00646464);
			if (pow(200 - i, 2) + pow(300 - j, 2) < pow(r / 2, 2))
				mlx_pixel_put(ptr, ptr_window, i, j, 0x00006464);
			else if (pow(700 - i, 2) + pow(300 - j, 2) < pow(r, 2))
				mlx_pixel_put(ptr, ptr_window, i, j, 0x00000064);
			//mlx_string_put(ptr, ptr_window, 0, 0, 0x00006464, "cjang_world");
		}
	}
	mlx_loop(ptr);
	return (0);
}

//gcc -lmlx -framework OpenGL -framework AppKit -lz mlx_test.c
