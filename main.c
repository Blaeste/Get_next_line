/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:22 by eschwart          #+#    #+#             */
/*   Updated: 2024/11/27 11:09:41 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("test/empty.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
