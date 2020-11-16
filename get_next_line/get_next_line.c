/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:10:59 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/11/13 09:48:54 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *saved_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved_line)
		return (0);
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		line[i] = saved_line[i];
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
	if (!new_save)
	{
		free(saved_line);
		return (NULL);
	}
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

static int	free_return(char *s)
{
	free(s);
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*saved_line;
	int			bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (free_return(saved_line));
	bytes_read = 1;
	while (newline_isset(saved_line) == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_return(saved_line));
		buffer[bytes_read] = '\0';
		saved_line = ft_strjoin(saved_line, buffer);
		if (!saved_line)
			return (-1);
	}
	*line = read_line(saved_line);
	saved_line = new_save(saved_line);
	if (bytes_read == 0)
		return (0);
	return (1);
}

// free bij return() bytes_read == -1
// mis 1 malloc protection
// buffer als static en saved line initialize;
// unsigned char
// max open 1024 FD