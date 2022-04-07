/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:13:57 by afaby             #+#    #+#             */
/*   Updated: 2022/04/06 18:45:32 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		*(res + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (0);
	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_realloc(char *str, int n)
{
	char	*res;
	int		len;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	res = ft_calloc(1, len + n + 1);
	ft_strcat(res, str);
	free(str);
	return (res);
}
