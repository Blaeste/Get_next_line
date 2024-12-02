/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:27:59 by eschwart          #+#    #+#             */
/*   Updated: 2024/12/02 09:31:42 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + (buffer[i] == '\n'));
	return (line);
}

static void	update_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

static char	*join_lines(char *line, char *temp)
{
	char	*new_line;

	if (!line)
		line = ft_strdup("");
	new_line = ft_strjoin(line, temp);
	free(line);
	free(temp);
	return (new_line);
}

static char	*get_next_line2(int fd, char *line, char *mem)
{
	ssize_t		b_read;

	while (1)
	{
		if (!mem[0])
		{
			b_read = read(fd, mem, BUFFER_SIZE);
			if (b_read <= 0)
			{
				if (b_read == 0)
					break ;
				return (free(line), NULL);
			}
			mem[b_read] = '\0';
		}
		line = join_lines(line, extract_line(mem));
		if (ft_strchr(mem, '\n'))
		{
			update_buffer(mem);
			break ;
		}
		mem[0] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	mem[1024][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	line = get_next_line2(fd, line, mem[fd]);
	return (line);
}