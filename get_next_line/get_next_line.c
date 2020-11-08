/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:48:04 by niels         #+#    #+#                 */
/*   Updated: 2020/11/04 12:57:38 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
* return (1)	a line has been read
* return (-1)	an error happened
* return (0)	EOF has been read	
* step 1 protection
* step 2 malloc buffer size
* step 3 set reader to 1?
* step 4 make local variable static 'save' to keep it through program
* step 5 while EOF not reached and there is no newline in save
		-> read (int fildes, void *buf, size_t nbyte)
		-> read (fd, buffer, BUFF_SIZE)
			-> if -1 error 
				-> free buffer and return -1
		end read bytes with '\0' 
		-> join save & buffer
* step 5 free malloced buffer
* step 6 allocate the value save to *line
* step 7 move save to next line and malloc or return 0
* step 8 if nothing read then EOF and return 0
* step 9 else return 1 for line read
*/

int		*do_read(int fd, char *str)
{
	
	char	*tmp;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (read(fd, buffer, BUFFER_SIZE ))
}

int			get_next_line(int fd, char **line)
{
	static char	*saved_line;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	do_read(fd, *line);
	if(!buffer)
		return (-1)
	
	

}	
	


















char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		save = join_str(save, buffer);
	}
	free(buffer);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
