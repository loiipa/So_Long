/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:10:34 by cjang             #+#    #+#             */
/*   Updated: 2021/11/16 18:36:50 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_check(int *fd, int *rd, char *c)
{
	*rd = read(*fd, c, 1);
	if (rd < 0)
		error_system();
}

static void	rd_check(int rd, char c, t_map *map_info)
{
	if (rd != 0 && c != '\n')
	{
		map_info->map[map_info->x][map_info->y] = c;
		map_info->x++;
	}
	else if (rd != 0)
	{
		if (map_info->y == 0)
			map_info->first_x = map_info->x;
		else if (map_info->y > 0 && map_info->first_x != map_info->x)
			error_user("Map size\n");
		map_info->x = 0;
		map_info->y++;
	}
}

void	map_size_check(t_map *map_info, int *fd)
{
	int		rd;
	char	c;

	rd = 1;
	while (rd)
	{
		read_check(fd, &rd, &c);
		rd_check(rd, c, map_info);
	}
	if (map_info->x == map_info->first_x)
		map_info->y++;
	else
		map_info->x = map_info->first_x;
}
	/*	if		xxx.ber 파일에 마지막 개행문자가 없는 경우	*/
	/*	else	xxx.ber 파일에 마지막 개행문자가 있는 경우	*/

static void	map_element_check(char c, t_map *map_info)
{
	if (c == 'P' || c == 'p')
	{
		map_info->player_x = cur_x;
		map_info->player_y = cur_y;
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
			c = m->map[cur_x][cur_y];
			if ((cur_x == 0 || cur_x == m->x - 1 || cur_y == 0 || \
			cur_y == m->y - 1) && c != '1')
				error_user("Wall boundary\n");
			map_element_check(c, m);
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
