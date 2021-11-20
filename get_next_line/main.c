/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:02:13 by cjang             #+#    #+#             */
/*   Updated: 2021/01/13 00:18:13 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		gnl;
	char	*line;
	int		index;

	if ((fd = open("baudelaire.txt", O_RDONLY)) < 0)
	{
		printf("Open error.\n");
		return (0);
	}
	index = 0;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(0, &line);
		if (gnl == -1)
		{
			printf("get_next_line error\n");
			return (0);
		}
		printf("%d, LINE %d:%s\n", gnl, index, line);
		if (line)
			free(line);
		index++;

	}
	gnl = get_next_line(fd, &line);
	printf("last 0 LINE %d:%s\n", index, line);
	if (line)
		free(line);
	close(fd);
	return (0);
}
