/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:27:16 by afaby             #+#    #+#             */
/*   Updated: 2022/04/10 16:14:58 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	print_line(char *tmp)
{
	while (*tmp)
	{
		printf("%c", *tmp);
		tmp++;
	}
}
int	main(int argc, char *argv[])
{
	int		fd;

	if (argc == 1)
		fd = 0;
	else if (argc != 2)
	{
		printf("\033[0;31mError: \033[0muse ./a.out <path>\n");
		return (0);
	}
	else 
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("\033[0;31mError: ");
		printf("\033[0mcan't open file with path : %s\n", argv[1]);
		return (0);
	}
	int	i = 0;
	printf("line %d : %s", i++, get_next_line(fd));
	printf("line %d : %s", i++, get_next_line(fd));
	printf("line %d : %s", i++, get_next_line(fd));
	printf("line %d : %s", i++, get_next_line(fd));
	printf("line %d : %s", i++, get_next_line(fd));
	printf("line %d : %s", i++, get_next_line(fd));
	printf("line %d : %s", i++, get_next_line(fd));
}
