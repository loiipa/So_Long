/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:19:11 by cjang             #+#    #+#             */
/*   Updated: 2021/10/06 21:34:24 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct s_param
{
	void	*ptr;
	void	*ptr_window;
	int		size_x;
	int		size_y;
	int		move_x;
	int		move_y;
	int		r;
}t_param;

typedef struct s_map
{
	int		x;
	int		y;
	int		x_cur;
	int		y_cur;
	int		x_first;
	int		p_num;
	int		c_num;
	int		e_num;
	char	map[100][100];
}t_map;

void	mlx_test(void);

#endif
