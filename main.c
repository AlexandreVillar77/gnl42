/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <alexandre.villar@hotmail.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:12:18 by avillar           #+#    #+#             */
/*   Updated: 2021/01/25 10:14:47 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int	main()
{
	int		fd;
	char	*line;
	int		rtnvalue;

	fd = 1;
	fd = open("test.txt", O_RDONLY);
	rtnvalue = get_next_line(fd, &line);
	printf("result 1 : %d \n", rtnvalue);
	printf("result 1 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 2 : %d \n", rtnvalue);
	printf("result 2 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 3 : %d \n", rtnvalue);
	printf("result 3 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 4 : %d \n", rtnvalue);
	printf("result 4 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 5 : %d \n", rtnvalue);
	printf("result 5 : %s \n", line);
	free(line);
	close(fd);
	return (0);
}