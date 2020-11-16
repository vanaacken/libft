#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

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