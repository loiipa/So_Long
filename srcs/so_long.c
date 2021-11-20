/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:15:33 by cjang             #+#    #+#             */
/*   Updated: 2021/11/20 21:36:55 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_open(int argv, char **argc)
{
	int		fd;

	if (argv != 2)
		error_user("Please write map location");
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
		error_system();
	return (fd);
}

int	main(int argv, char **argc)
{
	int		fd;
	t_map	map_info;

	fd = check_open(argv, argc);
	init_t_map(&map_info);
	init_map(&map_info, fd);
	check_map_vaid(&map_info);
	mlx_execution(&map_info);
	return (0);
}
