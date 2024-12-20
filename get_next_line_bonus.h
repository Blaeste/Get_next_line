/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:27:44 by eschwart          #+#    #+#             */
/*   Updated: 2024/11/27 12:51:17 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// INCLUDES
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

// BUFFER
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// PROTO
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif // GET_NEXT_LINE_BONUS_H