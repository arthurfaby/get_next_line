/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:27:16 by afaby             #+#    #+#             */
/*   Updated: 2022/04/06 18:40:39 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	print_line(char *tmp)
{
	while (*tmp && *tmp != '\n')
	{
		printf("%c", *tmp);
		tmp++;
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*tmp;

	if (argc != 2)
	{
		printf("\033[0;31mError: \033[0muse ./a.out <path>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("\033[0;31mError: ");
		printf("\033[0mcan't open file with path : %s\n", argv[1]);
		return (0);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		printf("\033[0;32m");
		print_line(tmp);
		printf("\n");
		printf("\033[0m");
		tmp = get_next_line(fd);
	}
}
