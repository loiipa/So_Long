/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:15:33 by cjang             #+#    #+#             */
/*   Updated: 2021/10/28 18:39:28 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_ckeck(int argv, char **argc)
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

	fd = open_ckeck(argv, argc);
	init_t_map(&map_info);
	map_size_check(&map_info, &fd);
	map_vaid_check(&map_info);
	mlx_test(&map_info);
	return (0);
}

	/*	배열의 크기를 할당해 줘야 하는데, 배열크기의 끝에 도달했을 때에는
		배열의 크기를 2배로 재할당 해주는 식으로 작업하는 것을 고려해볼 필요가 있을듯.	*/
	/*	맨 마지막 줄에서 개행이 2개가 있을 때에도 대비를 해야하는건가..?	*/
