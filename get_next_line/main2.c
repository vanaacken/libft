#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    int     return_value;
    char    *line;
   fd = 42;
   fd = open("test", O_RDONLY);
	return_value = get_next_line(fd, &line);
    printf("Return value: %d\n", return_value);
    return (0);
}