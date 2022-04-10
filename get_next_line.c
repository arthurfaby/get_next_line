/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:10:27 by afaby             #+#    #+#             */
/*   Updated: 2022/04/10 16:14:29 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	c_in_str(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*cut_str(char *to_read)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	while (to_read[i] && to_read[i] != '\n')
		i++;
	if (to_read[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (ft_strlen(to_read) - i + 1));
	if (!res)
		return (NULL);
	j = -1;
	while (to_read[i + ++j])
		res[j] = to_read[i + j];
	res[j] = '\0';
	free(to_read);
	return (res);
}

char	*get_subline(char *to_read)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (to_read[i] && to_read[i] != '\n')
		i++;
	if (to_read[i] == '\n')
		i++;
	j = 0;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = to_read[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	static char	*to_read = NULL;
	char		*res;

	buf = malloc(BUFFER_SIZE + 1);
	ret = -42;
	while (ret != 0 && !c_in_str(buf, '\n'))
	{
		if (ret != -42)
			buf[ret] = '\0';
		if (!to_read)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret < 1)
				return (NULL);
			to_read = ft_strdup(buf);
		}
		else if (ret != -42)
			to_read = ft_strjoin(to_read, buf);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	res = get_subline(to_read);
	to_read = cut_str(to_read);
	if (*res == '\0')
		return (NULL);
	free(buf);
	return (res);
}
