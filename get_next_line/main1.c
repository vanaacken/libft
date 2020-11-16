/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 16:02:57 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/13 08:17:18 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    int     return_value;
    char    *line;
    fd = open("test", O_RDONLY);
    return_value = get_next_line(fd, &line);
    printf("Return value: %d\n", return_value);
    return (0);
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>

/*
int main(int argc, char **argv)
{
    ssize_t nbr;
    char    *line;
    if (argc == 1)
    {
        fprintf(stderr, "Please enter a byte_size for the file.\n");
        return (0);
    }
    else
    {
        nbr = atoi(argv[1]);
        if (nbr <= 0)
        {
            fprintf(stderr, "%ld is not a valid number\n", nbr);
            return (0);
        }
    }
    line = (char*)malloc((nbr + 2) * sizeof(char));
    if (line == 0)
    {
        fprintf(stderr, "Malloc fail: %s\n", strerror(errno));
        return (0);
    }
    line[nbr] = '\n';
    line[nbr + 1] = '\0';
    memset(line, 'a', nbr);
    write(1, line, nbr + 1);
    free(line);
    return (0);
} */


int			main(int argc, char **argv)
{
    int     fd;
    int     count;
    int     return_value;
    char    *line;
    if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "Invalid filename\n");
			return (0);
		}
		return_value = 1;
		count = 1;
		while (return_value > 0)
		{
			return_value = get_next_line(fd, &line);
			if (return_value == -1)
			{
				fprintf(stderr, "Return value is: %d.\n", return_value);
				return (0);
			}
			printf("%d: %s\n", count, line);
			count++;
			free(line);
		}
	}
    return (0);
}
