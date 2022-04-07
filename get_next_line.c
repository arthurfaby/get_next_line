/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:39:48 by afaby             #+#    #+#             */
/*   Updated: 2022/04/06 18:51:06 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*res;
	char		buf_c[1];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	ret = read(fd, buf_c, 1);
	res = ft_calloc(1, 1);
	res[0] = '\0';
	if (ret < 1)
		return (0);
	i = 0;
	while (ret > 0)
	{
		buf[i] = buf_c[0];
		buf[i + 1] = '\0';
		if (!buf_c[0] || buf_c[0] == '\n')
		{
			res = ft_realloc(res, ft_strlen(buf));
			ft_strcat(res, buf);
			break;
		}
		else if (buf[BUFFER_SIZE] == '\0')
		{
			res = ft_realloc(res, ft_strlen(buf));
			ft_strcat(res, buf);
			i = -1;
		}
		ret = read(fd, buf_c, 1);
		i++;
	}
	return (res);
}
