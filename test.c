#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include "includes/pipex.h"

int main()
{
	int fd;

	char *str;

	str = get_next_line(0);
	while (str)
	{
		free(str);
		str = get_next_line(0);
	}
	free(str);
	close(fd);
	return (0);
}
