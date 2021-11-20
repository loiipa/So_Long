/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:02:13 by cjang             #+#    #+#             */
/*   Updated: 2021/01/06 17:54:57 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd[8];
	int		gnl[8];
	char	*line;
	int		index[8];

	if ((fd[0] = open("baudelaire.txt", O_RDONLY)) < 0)
	{
		printf("Open error.\n");
		return (0);
	}
	if ((fd[1] = open("cjang.txt", O_RDONLY)) < 0)
	{
		printf("Open error.\n");
		return (0);
	}
	index[0] = 0;
	index[1] = 0;
	gnl[0] = 1;
	gnl[1] = 1;
	while (gnl[0] > 0 || gnl[1] > 0)
	{
		gnl[0] = get_next_line(fd[0], &line);
		//printf("return:%d\n", gnl);
		printf("0 LINE %d:%s\n", index[0], line);
		free(line);
		index[0]++;
		if (gnl[0] == -1)
		{
			printf("get_next_line error\n");
			return (0);
		}
		gnl[1] = get_next_line(fd[1], &line);
		//printf("return:%d\n", gnl);
		printf("1 LINE %d:%s\n", index[1], line);
		free(line);
		index[1]++;
		if (gnl[1] == -1)
		{
			printf("get_next_line error\n");
			return (0);
		}
	}
	gnl[0] = get_next_line(fd[0], &line);
	//printf("return:%d\n", gnl);
	printf("last 0 LINE %d:%s\n", index[0], line);
	free(line);
	gnl[1] = get_next_line(fd[1], &line);
	//printf("return:%d\n", gnl);
	printf("last 1 LINE %d:%s\n", index[1], line);
	free(line);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
