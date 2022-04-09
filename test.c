#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

void fork_1()
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
        printf("Done son my pid = %d\n", getpid());
    else
        printf("Done father my pid = %d\n", getpid());
}
void fork_2()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
        printf("222 Done son my pid = %d\n", getpid());
    else
        printf("222 Done father my pid = %d\n", getpid());
}

int main(int argc, char* argv[], char *envp[])
{
    // int i = 0;
    // int fd[2];
    // pid_t pid;
    // fd[0] - read
    // fd[1] - write
    int i = 0;
    printf("%d", argc);
    while (i < 4)
    {
        printf("%s\n", envp[i]);
        i++;
    }
    // while(i < 4)
    // {
    //     pipe(fd);
    //     pid = fork();
    //     if (pid == 0)
    //     {
    //         printf("%d Done son my pid = %d\n", i, getpid());
    //         close(fd[1]);
    //         close(fd[0]);
    //     }
    //     else
    //     {
    //         printf("%d Done father my pid = %d\n", i, getpid());
    //         close(fd[0]);
    //         close(fd[1]);
    //     }
    //     i++;
    // }
}


// int main(int argc, char* argv[])
// {
//     int fd[2];
//     // fd[0] - read
//     // fd[1] - write
//     if (pipe(fd) == - 1)
//     {
//         write(1, "error", 6);
//         return (1);
//     }
//     int id = fork();
//     if (id == 0)
//     {
//         close(fd[0])
//         int x = 30;
//         if (write(fd[1], &x, sizeof(int)) == - 1)
//         {
//             write(1, "error2", 7);
//             return (2);
//         }
//         close(fd[1]);
//     }
//     else 
//     {
//         close(fd[1]);
//         int y;
//         if (read(fd[0], &y, sizeof(int)) == -1)
//         {
//             write(1, "error3", 7);
//             return (3);
//         }
//         close(fd[0]);
//         printf("from child %d", y);
//     }
//     return (0);
// }