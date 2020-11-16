
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include "get_next_line.h"
#include "get_next_line_bonus.h"

/* DIT WAS OM MEERDERE FILES TEGELIJKERTIJD TE OPENEN EN TE LEZEN (EN TE BEWAREN WAAR DAT IE WAS MET LEZEN IN FD1 ALVORENS DOOR TE GAAN NAAR FD2 EN WEER TEUG NAAR FD1) */

int main(void)
{
    int     fd;
    int     fd2;
    int     count;
	int		count2;
    int     return_value;
    char    *line;
        fd = open("get_next_line.h", O_RDONLY);
        if (fd == -1)
        {
            fprintf(stderr, "Invalid filename\n");
            return (0);
        }
        fd2 = open("get_next_line.c", O_RDONLY);
    return_value = 1;
    count = 1;
	count2 = 1;
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
		 return_value = get_next_line(fd2, &line);
        if (return_value == -1)
        {
            fprintf(stderr, "Return value is: %d.\n", return_value);
            return (0);
        }
        printf("%d: %s\n", count2, line);
		count2++;
        free(line);
    }
    return (0);
}