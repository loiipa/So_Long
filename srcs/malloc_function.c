/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:01:43 by cjang             #+#    #+#             */
/*   Updated: 2021/11/20 21:26:39 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resize_map(t_map *map_info)
{
	char	**map_tmp;
	int		i;

	i = 0;
	map_tmp = (char **)malloc(map_info->map_size * 2 * sizeof(char *));
	if (!map_tmp)
		error_user("malloc fail\n");
	while (i < map_info->map_size)
	{
		map_tmp[i] = map_info->map[i];
		i++;
	}
	free(map_info->map);
	map_info->map = map_tmp;
	map_info->map_size *= 2;
}
