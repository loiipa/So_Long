/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:10:34 by cjang             #+#    #+#             */
/*   Updated: 2021/11/20 19:41:24 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	gnl_check(int i, t_map *map_info)
{
	map_info->x = ft_strlen(map_info->map[i]);
	if (map_info->y == 0 && map_info->x == 0)
		error_user("Map size error\n");
	else if (map_info->y == 0)
		map_info->first_x = map_info->x;
	else if (map_info->y > 0 && map_info->map_flag == 0 && map_info->x == 0)
		return (++(map_info->map_flag));
	else if (map_info->y > 0 && map_info->map_flag != 0 && map_info->x == 0)
		error_user("Map size error\n");
	else if (map_info->y > 0 && map_info->first_x != map_info->x)
		error_user("Map size error\n");
	map_info->y++;
	return (0);
}

void	map_size_check(t_map *map_info, int fd)
{
	int		gnl;
	int		i;
	char	*line;

	i = 0;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1)
			error_user("GNL Error\n");
		map_info->map[i] = line;
		gnl_check(i, map_info);
		i++;
	}
	map_info->map[i] = NULL;
	map_info->x = map_info->first_x;
}
	/*	if		xxx.ber 파일에 마지막 개행문자가 없는 경우	*/
	/*	else	xxx.ber 파일에 마지막 개행문자가 있는 경우	*/

static void	map_element_check(char c, int *cur_x, int *cur_y, t_map *map_info)
{
	if (c == 'P' || c == 'p')
	{
		map_info->player_x = *cur_x;
		map_info->player_y = *cur_y;
		map_info->p_num++;
	}
	else if (c == 'E' || c == 'e')
		map_info->e_num++;
	else if (c == 'C' || c == 'c')
		map_info->c_num++;
	else if (c == '1' || c == '0')
		;
	else
		error_user("Invaid value\n");
}

void	map_vaid_check(t_map *m)
{
	char	c;
	int		cur_x;
	int		cur_y;

	cur_y = 0;
	while (cur_y < m->y)
	{
		cur_x = 0;
		while (cur_x < m->x)
		{
			c = m->map[cur_y][cur_x];
			if ((cur_x == 0 || cur_x == m->x - 1 || cur_y == 0 || \
			cur_y == m->y - 1) && c != '1')
				error_user("Wall boundary\n");
			map_element_check(c, &cur_x, &cur_y, m);
			cur_x++;
		}
		cur_y++;
	}
	if (m->p_num != 1)
		error_user("player starting position isn't one\n");
	else if (m->e_num == 0)
		error_user("Map exit not exist\n");
	else if (m->c_num == 0)
		error_user("Collectible not exist\n");
}
