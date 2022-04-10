/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:10:27 by afaby             #+#    #+#             */
/*   Updated: 2022/04/10 22:26:26 by afaby            ###   ########.fr       */
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

char	*ft_read(int fd, char *to_process)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(to_process, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			return (0);
		}
		buf[ret] = 0;
		to_process = ft_strjoin(to_process, buf);
	}
	free(buf);
	return (to_process);
}

char	*get_next_line(int fd)
{
	static char	*to_process;
	char		*res;

	to_process = ft_read(fd, to_process);
	if (!to_process)
		return (0);
	res = get_subline(to_process);
	to_process = cut_str(to_process);
	return (res);
}
