/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:10:34 by cjang             #+#    #+#             */
/*   Updated: 2021/10/07 20:15:32 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_t_map(t_map *map_info)
{
	map_info->x = 0;
	map_info->y = 0;
	map_info->player_x = 0;
	map_info->player_y = 0;
	map_info->first_x = 0;
	map_info->p_num = 0;
	map_info->c_num = 0;
	map_info->e_num = 0;
}

void	map_size_check(t_map *map_info, int *fd)
{
	int		rd;
	char	c;

	rd = 1;
	while (rd)
	{
		rd = read(*fd, &c, 1);
		if (rd < 0)
		{
			printf("error : read\n");
			exit(0);
		}
		else if (rd == 0)
			break ;
		if (c != '\n')
		{
			map_info->map[map_info->x][map_info->y] = c;
			// printf("[x:%d, y:%d]	<%c>\n", x, y, c);
			map_info->x++;
		}
		else
		{
			/*	map size check	*/
			if (map_info->y == 0)
				map_info->first_x = map_info->x;
			else if (map_info->y > 0 && map_info->first_x != map_info->x)
			{
				printf("error : map size\n");
				exit(0);
			}
			map_info->x = 0;
			map_info->y++;
		}
		// printf("[x:%d, y:%d]	<%d>\n", x, y, c);
	}
	/*	if		xxx.ber 파일에 마지막 개행문자가 없는 경우	*/
	/*	else	xxx.ber 파일에 마지막 개행문자가 있는 경우	*/
	if (map_info->x == map_info->first_x)
		map_info->y++;
	else
		map_info->x = map_info->first_x;
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
			/*	우선순위 (&& > ||)	*/
			c = m->map[cur_x][cur_y];
			if ((cur_x == 0 || cur_x == m->x - 1 || cur_y == 0 || cur_y == m->y - 1) && \
			c != '1')
			{
				// printf("[x:%d, y:%d]\n", cur_x, cur_y);
				printf("error : wall boundary\n");
				exit(0);
			}

			if (c == 'P' || c == 'p')
			{
				m->player_x = cur_x;
				m->player_y = cur_y;
				m->p_num++;
			}
			else if (c == 'E' || c == 'e')
				m->e_num++;
			else if (c == 'C' || c == 'c')
				m->c_num++;
			else if (c == '1' || c == '0')
				;
			else
			{
				printf("error : invaid value\n");
				exit(0);
			}
			cur_x++;
		}
		cur_y++;
	}
	if (m->p_num != 1)
	{
		printf("error : player starting position isn't one (current player_num:%d)\n", m->p_num);
		exit(0);
	}
	else if (m->e_num == 0)
	{
		printf("error : map exit not exist\n");
		exit(0);
	}
	else if (m->c_num == 0)
	{
		printf("error : collectible not exist\n");
		exit(0);
	}
}

int	main(int argv, char **argc)
{
	int		fd;
	t_map	map_info;

	/*	받은 인자값 확인 + open 확인	*/
	if (argv != 2)
	{
		printf("error : argv number\n");
		return (0);
	}
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error : open\n");
		return (0);
	}
	/*	xxx.ber 파일 읽어서 배열에 추가하는 부분	*/
	/*	배열의 크기를 할당해 줘야 하는데, 배열크기의 끝에 도달했을 때에는
		배열의 크기를 2배로 재할당 해주는 식으로 작업하는 것을 고려해볼 필요가 있을듯.	*/
	/*	맨 마지막 줄에서 개행이 2개가 있을 때에도 대비를 해야하는건가..?	*/
	/*	맨 첫번째 줄에서 x_max값 체크, n번째 줄의 x_max과 크기가 다르다면 map error처리	*/

	init_t_map(&map_info);
	map_size_check(&map_info, &fd);
	printf("[x:%d, y:%d]\n", map_info.x, map_info.y);
	/*	들어온 인자값이 유효한지 확인	*/
	/*	대문자, 소문자도 같이 확인해 줘야하나..?	*/
	map_vaid_check(&map_info);
	printf("success\n");
	mlx_test(&map_info);
	return (0);
}
