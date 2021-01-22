/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <alexandre.villar@hotmail.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:12:18 by avillar           #+#    #+#             */
/*   Updated: 2021/01/22 18:04:52 by avillar          ###   ########.fr       */
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

	fd = 1;
	//fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("result 1 : %s \n", line);
	free(line);
	get_next_line(fd, &line);
	printf("result 2 : %s \n", line);
	free(line);
	get_next_line(fd, &line);
	printf("result 3 : %s \n", line);
	free(line);
	//close(fd);
	return (0);
}