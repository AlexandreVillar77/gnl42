/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:26:51 by marvin            #+#    #+#             */
/*   Updated: 2021/01/25 17:18:49 by marvin           ###   ########.fr       */
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
	//fd = open("text.txt", O_RDONLY);
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
    rtnvalue = get_next_line(fd, &line);
	printf("result 6 : %d \n", rtnvalue);
	printf("result 6 : %s \n", line);
	free(line);
	//close(fd);
	return (0);
}