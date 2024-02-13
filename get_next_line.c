/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:00:52 by healeksa          #+#    #+#             */
/*   Updated: 2024/02/13 16:39:09 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buff)
{
	int	read_res;

	read_res = 1;
	while (!(ft_strchr(buff, '\n')) && read_res != 0)
	{
		read_res = read(fd, buff, BUFFER_SIZE);
		if (read_res == -1)
			return (NULL);
	}
	buff[read_res] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*str;

	// static char	*remainder;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	str = read_file(fd, buff);
	if (!str)
		return (NULL);
}
