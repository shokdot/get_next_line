/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:30:46 by healeksa          #+#    #+#             */
/*   Updated: 2024/02/21 16:24:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *reminder)
{
	int		read_res;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_res = 1;
	while (read_res != 0 && !(ft_strchr(reminder, '\n')))
	{
		read_res = read(fd, buff, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_res] = '\0';
		reminder = ft_strjoin(reminder, buff);
	}
	free(buff);
	return (reminder);
}

char	*processing(char *str)
{
	char	*proc_str;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	proc_str = ft_substr(str, 0, i + 1);
	return (proc_str);
}

char	*clean_reminder(char *reminder)
{
	int		i;
	int		len;
	char	*tmp;

	if (!reminder)
		return (NULL);
	len = ft_strlen(reminder);
	i = 0;
	while (reminder[i] != '\n' && reminder[i] != '\0')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	tmp = ft_substr(reminder, i + 1, len - i);
	free(reminder);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*reminder[DESCRIPTOR_COUNT];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(reminder[fd]);
		reminder[fd] = NULL;
		return (NULL);
	}
	reminder[fd] = read_file(fd, reminder[fd]);
	line = processing(reminder[fd]);
	reminder[fd] = clean_reminder(reminder[fd]);
	return (line);
}
