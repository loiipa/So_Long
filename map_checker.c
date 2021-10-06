/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:10:34 by cjang             #+#    #+#             */
/*   Updated: 2021/10/06 21:32:58 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_t_map(t_map *map_info)
{
	map_info->x = 0;
	map_info->y = 0;
	map_info->x_cur = 0;
	map_info->y_cur = 0;
	map_info->x_first = 0;
	map_info->p_num = 0;
	map_info->c_num = 0;
	map_info->e_num = 0;
}

int	main(int argv, char **argc)
{
	int		fd;
	int		rd;
	t_map	map_info;
	char	c;

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
	rd = 1;
	init_t_map(&map_info);
	while (rd)
	{
		rd = read(fd, &c, 1);
		if (rd < 0)
		{
			printf("error : read\n");
			return (0);
		}
		else if (rd == 0)
		{
			break ;
		}
		if (c != '\n')
		{
			map_info.map[map_info.x][map_info.y] = c;
			// printf("[x:%d, y:%d]	<%c>\n", x, y, c);
			map_info.x++;
		}
		else
		{
			/*	map size check	*/
			if (map_info.y == 0)
			{
				map_info.x_first = map_info.x;
			}
			else if (map_info.y > 0 && map_info.x_first != map_info.x)
			{
				printf("error : map size\n");
				return (0);
			}
			map_info.x = 0;
			map_info.y++;
		}
		// printf("[x:%d, y:%d]	<%d>\n", x, y, c);
	}
	/*	if		xxx.ber 파일에 마지막 개행문자가 없는 경우	*/
	/*	else	xxx.ber 파일에 마지막 개행문자가 있는 경우	*/
	if (map_info.x == map_info.x_first)
	{
		map_info.y++;
	}
	else
	{
		map_info.x = map_info.x_first;
	}

	printf("[x:%d, y:%d]\n", map_info.x, map_info.y);
	/*	들어온 인자값이 유효한지 확인	*/
	/*	대문자, 소문자도 같이 확인해 줘야하나..?	*/
	while (map_info.y_cur < map_info.y)
	{
		map_info.x_cur = 0;
		while (map_info.x_cur < map_info.x)
		{
			/*	우선순위 (&& > ||)	*/
			if ((map_info.x_cur == 0 || map_info.x_cur == map_info.x - 1 || map_info.y_cur == 0 || map_info.y_cur == map_info.y - 1) && \
			map_info.map[map_info.x_cur][map_info.y_cur] != '1')
			{
				// printf("[x:%d, y:%d]\n", x_cur, y_cur);
				printf("error : wall boundary\n");
				return (0);
			}
			if (map_info.map[map_info.x_cur][map_info.y_cur] == 'P' || map_info.map[map_info.x_cur][map_info.y_cur] == 'p')
			{
				map_info.p_num++;
			}
			else if (map_info.map[map_info.x_cur][map_info.y_cur] == 'E' || map_info.map[map_info.x_cur][map_info.y_cur] == 'e')
			{
				map_info.e_num++;
			}
			else if (map_info.map[map_info.x_cur][map_info.y_cur] == 'C' || map_info.map[map_info.x_cur][map_info.y_cur] == 'c')
			{
				map_info.c_num++;
			}
			map_info.x_cur++;
		}
		map_info.y_cur++;
	}
	if (map_info.p_num != 1)
	{
		printf("error : player starting position isn't one (current player_num:%d)\n", map_info.p_num);
		return (0);
	}
	else if (map_info.e_num == 0)
	{
		printf("error : map exit not exist\n");
		return (0);
	}
	else if (map_info.c_num == 0)
	{
		printf("error : collectible not exist\n");
		return (0);
	}
	printf("success\n");
	return (0);
}
