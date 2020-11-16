/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:10:59 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/11/11 15:10:28 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*new_save(char *saved_line)
{
	char	*new_save;
	int		i;
	int		j;

	if (!saved_line)
		return (0);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!saved_line[i])
	{
		free(saved_line);
		return (0);
	}
	new_save = malloc(sizeof(char) * (ft_strlen(saved_line) - i + 1));
	i++;
	j = 0;
	while (saved_line[i + j])
	{
		new_save[j] = saved_line[i + j];
		j++;
	}
	new_save[j] = '\0';
	free(saved_line);
	return (new_save);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*saved_line[MAX_FD];
	int			bytes_read;

	if (fd < 0 || fd > 1024 || !line || BUFFER_SIZE <= 0)
		return (-1);
	bytes_read = 1;
	while (newline_isset(saved_line[fd]) == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buffer[bytes_read] = '\0';
		saved_line[fd] = ft_strjoin(saved_line[fd], buffer);
		if (!saved_line[fd])
			return (-1);
	}
	*line = read_line(saved_line[fd]);
	saved_line[fd] = new_save(saved_line[fd]);
	if (bytes_read == 0)
		return (0);
	return (1);
}
