/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:10:27 by afaby             #+#    #+#             */
/*   Updated: 2022/04/11 19:22:58 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_str(char *to_process)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	while (to_process[i] && to_process[i] != '\n')
		i++;
	if (to_process[i] == 0)
	{
		free(to_process);
		return (0);
	}
	res = malloc(ft_strlen(to_process) - i + 1);
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (to_process[i])
		res[j++] = to_process[i++];
	res[j] = 0;
	free(to_process);
	return (res);
}

char	*get_subline(char *to_process)
{
	int		i;
	char	*res;

	i = 0;
	if (!*to_process)
		return (0);
	while (to_process[i] && to_process[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (to_process[i] && to_process[i] != '\n')
	{
		res[i] = to_process[i];
		i++;
	}
	if (to_process[i] == '\n')
	{
		res[i] = to_process[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*to_process[1025];
	char		*buf;
	int			ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	ret = 1;
	while (ret && !ft_strchr(to_process[fd], '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			return (0);
		}
		buf[ret] = '\0';
		to_process[fd] = ft_strjoin(to_process[fd], buf);
	}
	free(buf);
	res = get_subline(to_process[fd]);
	to_process[fd] = cut_str(to_process[fd]);
	return (res);
}
