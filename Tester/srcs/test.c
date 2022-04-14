/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:45:14 by afaby             #+#    #+#             */
/*   Updated: 2022/04/14 21:08:36 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"
#include "../includes/ref.h"
#include <string.h>
#include <stdio.h>

int	nTest = 1;

void	test(char *use, char *ref)
{
	if (!use && !ref)
		printf("\033[0;32m%d.OK \033[0m", nTest++);
	else if (!use || !ref)
		printf("\033[0;31m%d.KO \033[0m", nTest++);
	else if (strcmp(use, ref))
		printf("\033[0;32m%d.OK \033[0m", nTest++);
	else
		printf("\033[0;31m%d.KO \033[0m", nTest++);
}

int	main(void)
{
	char	*ref;
	char	*use;
	int		fd1;
	int		fd2;

	fd1 = open("hello.txt", O_RDONLY);
	fd2 = open("hello.txt", O_RDONLY);
	use = calloc(1, 5);
	ref = get_next_line_ref(fd2);
	test(use, ref);	
	test(use, ref);	
	test(use, ref);	
	test(use, ref);	
	test(use, ref);	
	test(use, ref);	
}
