#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include "includes/pipex.h"

char **ft_fill_path_env(t_list pipex, char *env[])
{
	char *path;
	char **all_path;
	int i;
	
	i = 0;
	path = "PATH";
	while (env[i])
	{
		if (ft_strncmp(path, env[i], 4) == 0)
		{
			while (*env[i] != '/' && *env[i] != '\0')
				env[i]++;
			all_path = ft_split(env[i], ':');
            	return (all_path);
		}
		i++;
	}
	return (NULL);
}

int main(int argc, char* argv[], char *envp[])
{
    int i;
    t_list pipex;
    
    i = 0;
    pipex.path_absolute = ft_fill_path_env(pipex, envp);
	while (pipex.path_absolute[i] != NULL)
	{
		printf("\n%s", pipex.path_absolute[i]);
		i++;
	}
	
//    while (pipex.path_absolute[i])
//    {
//        printf("%s\n", pipex.path_absolute[i]);
//        i++;
//    }
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