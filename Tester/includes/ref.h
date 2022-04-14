/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:26:05 by afaby             #+#    #+#             */
/*   Updated: 2022/04/14 20:51:29 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REF_H
# define REF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

char	*get_next_line_ref(int fd);
char	*ft_strjoin_ref(char *s1, char *s2);
size_t	ft_strlen_ref(char *s);
char	*ft_strdup_ref(const char *s);
char	*ft_strchr_ref(char *s, int c);

#endif
