#include "includes/pipex_bonus.h"

int main()
{
    int i;
    int fd[2];

    i = 0;
    while(i < 4)
    {
        pipe(fd);
        printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
        i++;
    }
    return (0);
}