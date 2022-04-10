/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:13:57 by afaby             #+#    #+#             */
/*   Updated: 2022/04/10 15:34:49 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)src;
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (tmp[j] != '\0')
	{
		dest[i] = tmp[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(dest + i) = *(s + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
