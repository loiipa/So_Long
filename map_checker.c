/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:10:34 by cjang             #+#    #+#             */
/*   Updated: 2021/10/06 20:52:54 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argv, char **argc)
{
	int		fd;
	int		rd;

	int		x;
	int		y;
	int		x_cur;
	int		y_cur;
	int		x_first;

	int		p_num;
	int		c_num;
	int		e_num;

	char	c;
	char	map[100][100];

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
	x = 0;
	y = 0;
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
			map[x][y] = c;
			// printf("[x:%d, y:%d]	<%c>\n", x, y, c);
			x++;
		}
		else
		{
			/*	map size check	*/
			if (y == 0)
			{
				x_first = x;
			}
			else if (y > 0 && x_first != x)
			{
				printf("error : map size\n");
				return (0);
			}
			x = 0;
			y++;
		}
		// printf("[x:%d, y:%d]	<%d>\n", x, y, c);
	}
	/*	if		xxx.ber 파일에 마지막 개행문자가 없는 경우	*/
	/*	else	xxx.ber 파일에 마지막 개행문자가 있는 경우	*/
	if (x == x_first)
	{
		y++;
	}
	else
	{
		x = x_first;
	}

	printf("[x:%d, y:%d]\n", x, y);
	/*	들어온 인자값이 유효한지 확인	*/
	/*	대문자, 소문자도 같이 확인해 줘야하나..?	*/
	y_cur = 0;
	p_num = 0;
	e_num = 0;
	c_num = 0;
	while (y_cur < y)
	{
		x_cur = 0;
		while (x_cur < x)
		{
			/*	우선순위 (&& > ||)	*/
			if ((x_cur == 0 || x_cur == x - 1 || y_cur == 0 || y_cur == y - 1) \
			&& map[x_cur][y_cur] != '1')
			{
				// printf("[x:%d, y:%d]\n", x_cur, y_cur);
				printf("error : wall boundary\n");
				return (0);
			}
			if (map[x_cur][y_cur] == 'P' || map[x_cur][y_cur] == 'p')
			{
				p_num++;
			}
			else if (map[x_cur][y_cur] == 'E' || map[x_cur][y_cur] == 'e')
			{
				e_num++;
			}
			else if (map[x_cur][y_cur] == 'C' || map[x_cur][y_cur] == 'c')
			{
				c_num++;
			}
			x_cur++;
		}
		y_cur++;
	}
	if (p_num != 1)
	{
		printf("error : player starting position isn't one (current player_num:%d)\n", p_num);
		return (0);
	}
	else if (e_num == 0)
	{
		printf("error : map exit not exist\n");
		return (0);
	}
	else if (c_num == 0)
	{
		printf("error : collectible not exist\n");
		return (0);
	}
	printf("success\n");
	return (0);
}
